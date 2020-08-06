#include <parser/ParserBlockedInstr.hpp>

#include <variant>
#include <optional>
#include <vector>
#include <Util.hpp>
#include <Error.hpp>
#include <parser/Comment.hpp>
#include <parser/Identifier.hpp>
#include <parser/ParserResult.hpp>
#include <parser/GetInstr.hpp>
#include <parser/ParserTypeUse.hpp>
#include <structure/TypeUse.hpp>
#include <structure/InstrVariant.hpp>

ParserBlockedInstr::ParserBlockedInstr(ParserContext& parent_context){
  if(parent_context.cursor != parent_context.end){
    ParserContext context = parent_context;

    std::optional<std::string>* labelPtr = nullptr;
    std::optional<BlockType>* typePtr = nullptr;
    std::vector<InstrVariant>* instrsPtr = nullptr;
    std::vector<InstrVariant>* foldedPtr = nullptr;
    bool isFolded = false;

    if(*context.cursor == '('){
      ++context.cursor;
      isFolded = true;
      Comment::skip(context);
    }

    if(Util::matchString(context.cursor, context.end, "block")){
      context.cursor += 5;
      BlockInstr& instr = emplace<BlockInstr>(BlockInstr());
      labelPtr = &instr.label;
      typePtr = &instr.blockType;
      instrsPtr = &instr.instrs;
    }else if(Util::matchString(context.cursor, context.end, "loop")){
      context.cursor += 4;
      LoopInstr& instr = emplace<LoopInstr>(LoopInstr());
      labelPtr = &instr.label;
      typePtr = &instr.blockType;
      instrsPtr = &instr.instrs;
    }else if(Util::matchString(context.cursor, context.end, "if")){
      context.cursor += 2;
      IfInstr& instr = emplace<IfInstr>(IfInstr());
      labelPtr = &instr.label;
      typePtr = &instr.blockType;
      instrsPtr = &instr.instrs;
      if(isFolded){
        foldedPtr = &instr.foldedInstrs;
      }
    }else{
      return;
    }
    // Id
    Comment::skip(context);
    Identifier label(context);
    *labelPtr = label;

    // Return Type
    Comment::skip(context);
    ParserContext result_context = context;
    ParserResult result(result_context);
    if(result.has_value() && result.type() == typeid(ValueType)){
      typePtr->emplace<ValueType>(std::any_cast<ValueType>(result));
      context = result_context;
    }else{
      ParserTypeUse typeUse(context);
      if(typeUse.has_value()){
        **typePtr = *typeUse;
      }
    }

    // Folded instructions of if
    if(isFolded && std::holds_alternative<IfInstr>(*this)){
      Comment::skip(context);
      ParserFoldedInstr folded(context);
      if(folded.has_value()){
        for(auto it = folded->begin(); it != folded->end(); ++it){
          foldedPtr->emplace_back(*it);
        }
      }
      Comment::skip(context);
      if(*context.cursor == '('){
        ++context.cursor;
        Comment::skip(context);
        if(Util::matchString(context.cursor, context.end, "then")){
          context.cursor += 4;
        }else{
          throw Error<ErrorType::ParseError>("expected 'then' block in folded if");
        }
      }else{
        throw Error<ErrorType::ParseError>("expected 'then' block in folded if");
      }
    }

    // Instructions
    for(bool hasInstr = true; hasInstr; ){
      Comment::skip(context);
      InstrVariant instr = getInstruction(context);
      if(std::holds_alternative<std::monostate>(instr)){
        hasInstr = false;
      }else{
        instrsPtr->emplace_back(instr);
      }
    }

    // Else section in if
    Comment::skip(context);
    if(std::holds_alternative<IfInstr>(*this)){
      bool optionalFoldedElse = true;
      if(isFolded){
        if(*context.cursor == ')'){
          ++context.cursor;
          Comment::skip(context);
          if(*context.cursor == '('){
            ++context.cursor;
            Comment::skip(context);
          }else{
            optionalFoldedElse = false;
          }
        }else{
          throw Error<ErrorType::ParseError>("expected ')' in folded if");
        }
      }
      if(optionalFoldedElse && Util::matchString(context.cursor, context.end, "else")){
        context.cursor += 4;
        Comment::skip(context);
        Identifier postfix(context);
        if(postfix.has_value() && *postfix != *label){
          throw Error<ErrorType::ParseError>("postfix id of 'else' should match block label");
        }
        std::vector<InstrVariant>& elseInstrs = std::get<IfInstr>(*this).elseInstrs;
        for(bool hasInstr = true; hasInstr; ){
          Comment::skip(context);
          InstrVariant instr(getInstruction(context));
          if(std::holds_alternative<std::monostate>(instr)){
            hasInstr = false;
          }else{
            elseInstrs.emplace_back(instr);
          }
        }
        if(isFolded){
          if(*context.cursor == ')'){
            ++context.cursor;
          }else{
            throw Error<ErrorType::ParseError>("expected ')' in folded instruction");
          }
        }
      }
    }

    // Check end
    Comment::skip(context);
    if(isFolded){
      if(*context.cursor != ')'){
        throw Error<ErrorType::ParseError>("expected ')' in folded instruction");
      }else{
        ++context.cursor;
      }
    }else{
      if(Util::matchString(context.cursor, context.end, "end")){
        context.cursor += 3;
        Comment::skip(context);
        Identifier postfix(context);
        if(postfix.has_value() && *postfix != *label){
          throw Error<ErrorType::ParseError>("postfix id should match block label");
        }
      }else{
        throw Error<ErrorType::ParseError>("expected 'end' in blocked instruction");
      }
    }
    parent_context.cursor = context.cursor;
  }
}

ParserFoldedInstr::ParserFoldedInstr(ParserContext& parent_context){
  ParserContext context = parent_context;
  if(*context.cursor == '('){
    ++context.cursor;
    Comment::skip(context);
    std::vector<InstrVariant>& instrs = emplace<std::vector<InstrVariant>>(std::vector<InstrVariant>());
    InstrVariant plainInstr = getInstruction(context);
    if(!std::holds_alternative<std::monostate>(plainInstr)){
      Comment::skip(context);
      for(ParserFoldedInstr foldedInstr(context); foldedInstr.has_value(); foldedInstr = ParserFoldedInstr(context)){
        for(auto it = foldedInstr->begin(); it != foldedInstr->end(); ++it){
          instrs.emplace_back(*it);
        }
        Comment::skip(context);
      }
      instrs.emplace_back(plainInstr);
      Comment::skip(context);
      if(*context.cursor != ')'){
        throw Error<ErrorType::ParseError>("expected ')' in folded instruction");
      }
      ++context.cursor;
      parent_context.cursor = context.cursor;
    }
  }
}
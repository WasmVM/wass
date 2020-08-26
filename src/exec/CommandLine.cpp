#include "CommandLine.hpp"

#include <algorithm>
#include <set>
#include <string>
#include <string_view>
#include <stdexcept>
#include <vector>

CommandLine::OptionMap::OptionMap(std::initializer_list<std::pair<std::string, Option>> initializer){
    for(std::pair<std::string, Option> op: initializer){
        // Parse keys
        std::string_view keyView = op.first;
        std::vector<std::string> keys;
        for(size_t commaPos = keyView.find_first_of(','); commaPos != std::string_view::npos; commaPos = keyView.find_first_of(',')){
            std::string_view slicedView = keyView.substr(0, commaPos);
            if(slicedView.size() > 0){
                keys.emplace_back(slicedView);
            }
            keyView = keyView.substr(commaPos + 1, keyView.size() - commaPos + 1);
        }
        if(keyView.size() > 0){
            keys.emplace_back(keyView);
        }
        // Initialize
        if(keys.size() > 0){
            if(keys.front().starts_with('-')){
                unpositioned.insert_or_assign(keys.front(), op.second);
                for(auto it = std::next(keys.begin()); it != keys.end(); it = std::next(it)){
                    aliases.insert_or_assign(*it, keys.front());
                }
            }else{
                positioned.emplace_back(keys.front(), op.second);
            }
        }else{
            throw std::invalid_argument("Option name is required");
        }
    }
}

struct OptionVisitor {
    int& cur;
    const int argc;
    const char** (&argv);
    const bool isPositioned;
    OptionVisitor(int& cur, const int argc, const char** (&argv), const bool isPositioned):cur(cur), argc(argc), argv(argv), isPositioned(isPositioned){}
    void operator()(std::string& value){
        if(!isPositioned){
            ++cur;
        }
        if(cur < argc){
            value = argv[cur];
        }
    }
    void operator()(std::vector<std::string>& value){
        if(!isPositioned){
            ++cur;
        }
        while(cur < argc){
            value.emplace_back(argv[cur++]);
        }
    }
    void operator()(bool& value){
        value = true;
    }
    void operator()(auto&&){
        throw std::invalid_argument("Unsupported option type");
    }
};

void CommandLine::OptionMap::parse(int argc, const char *argv[]){
    auto positionedIt = positioned.begin();
    std::set<std::string> parsed;
    // Parse
    for(int cur = 0; cur < argc; ++cur){
        std::string argStr(argv[cur]);
        Option* optionPtr = nullptr;
        bool isPositioned = false;
        if(aliases.find(argStr) != aliases.end()){
            argStr = aliases[argStr];
        }
        if(unpositioned.find(argStr) != unpositioned.end()){
            // unpositioned
            optionPtr = &unpositioned[argStr];
            if(parsed.find(argStr) == parsed.end()){
                parsed.insert(argStr);
            }
        }else if(positionedIt != positioned.end()){
            // potitioned
            optionPtr = &positionedIt->second;
            if(parsed.find(positionedIt->first) == parsed.end()){
                parsed.insert(positionedIt->first);
            }
            ++positionedIt;
            isPositioned = true;
        }else{
            continue;
        }
        std::visit(OptionVisitor(cur, argc, argv, isPositioned), optionPtr->first);
    }
    // Validate
    for(auto optionIt = unpositioned.begin(); optionIt != unpositioned.end(); optionIt = std::next(optionIt)){
        auto option = unpositioned.extract(optionIt);
        if(option.mapped().second && (parsed.find(option.key()) == parsed.end())){
            throw std::invalid_argument(option.key() + " is required");
        }
        option.key() = std::string_view(option.key()).substr(option.key().find_first_not_of('-'));
        if(!unpositioned.insert(std::move(option)).inserted){
            throw std::runtime_error(std::string("error rename option") + option.key());
        }
    }
    for(std::pair<std::string, CommandLine::Option> option : positioned){
        if(option.second.second && (parsed.find(option.first) == parsed.end())){
            throw std::invalid_argument(option.first + " is required");
        }
    }
}

CommandLine::OptionValue CommandLine::OptionMap::operator[](std::string key){
    std::unordered_map<std::string, Option>::iterator unpositionedIt = unpositioned.find(key);
    if(unpositionedIt != unpositioned.end()){
        return unpositionedIt->second.first;
    }else{
        std::vector<std::pair<std::string, Option>>::iterator positionedIt = std::find_if(positioned.begin(), positioned.end(),
            [key](std::pair<std::string, Option>& target){
                return target.first == key;
            }
        );
        if(positionedIt == positioned.end()){
            throw std::invalid_argument(key + " not found");
        }else{
            return positionedIt->second.first;
        }
    }
}
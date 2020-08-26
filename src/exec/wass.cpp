#include <iostream>
#include <filesystem>
#include <variant>
#include <fstream>
#include <vector>
#include <string>
#include <BinaryCode.hpp>
#include <structure/Module.hpp>
#include <parser/ParserModule.hpp>
#include <codegen/CodeGenVisitor.hpp>
#include "CommandLine.hpp"

int main(int argc, const char *argv[]){
    // Get command line option
    CommandLine::OptionMap options({
        {"input_file", {std::string(), true}},
        {"--output_file,-o", {std::string(), false}}
    });
    options.parse(argc - 1, argv + 1);
    // Read input
    std::filesystem::path inputPath(std::get<std::string>(options["input_file"]));
    std::ifstream inputFile(inputPath);
    std::vector<char> inputData(std::filesystem::file_size(inputPath));
    inputFile.read(inputData.data(), inputData.size());
    inputFile.close();
    // Parse module
    ParserContext context(inputData);
    ParserModule parsedModule(context);
    if(!parsedModule.has_value()){
        std::cerr << "No module has been parsed" << std::endl;
    }
    // Generate binary
    CodeGenVisitor visitor;
    BinaryCode binaryCode = std::visit<BinaryCode>(visitor, CodeGenVariant(*parsedModule));
    // Write output
    std::string outputName(std::get<std::string>(options["output_file"]));
    if(outputName.size() == 0){
        outputName = inputPath.replace_extension(".wasm");
    }
    std::ofstream outputFile(outputName);
    outputFile.write(binaryCode.data(), binaryCode.size());
    outputFile.close();
    return 0;
}
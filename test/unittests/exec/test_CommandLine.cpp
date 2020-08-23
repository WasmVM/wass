#include <gtest/gtest.h>

#include <string>
#include <CommandLine.hpp>

TEST(unittest_CommandLine, positioned_required_exist){
    const char* argv[] = {"test1.txt", "test2.txt"};
    CommandLine::OptionMap options({
        {"input1", {std::string(), true}},
        {"input2", {std::string(), true}}
    });
    options.parse(2, argv);
    EXPECT_STREQ(std::get<std::string>(options["input1"]).c_str(), "test1.txt");
    EXPECT_STREQ(std::get<std::string>(options["input2"]).c_str(), "test2.txt");
}

TEST(unittest_CommandLine, positioned_required_not_exist){
}

TEST(unittest_CommandLine, positioned_not_required){
}

TEST(unittest_CommandLine, unpositioned_required_exist){
}

TEST(unittest_CommandLine, unpositioned_required_not_exist){
}

TEST(unittest_CommandLine, unpositioned_not_required){
}

TEST(unittest_CommandLine, string_type){
}

TEST(unittest_CommandLine, string_vector_type){
}

TEST(unittest_CommandLine, bool_type){
}
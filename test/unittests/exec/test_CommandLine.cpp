#include <gtest/gtest.h>

#include <string>
#include <stdexcept>
#include <CommandLine.hpp>

TEST(unittest_CommandLine, positioned_required_exist){
    const char* argv[] = {"test1.txt", "test2.txt"};
    CommandLine::OptionMap options({
        {"input1", {std::string(), true}},
        {"input2", {std::string(), true}}
    });
    EXPECT_NO_THROW(options.parse(2, argv));
    EXPECT_STREQ(std::get<std::string>(options["input1"]).c_str(), "test1.txt");
    EXPECT_STREQ(std::get<std::string>(options["input2"]).c_str(), "test2.txt");
}

TEST(unittest_CommandLine, positioned_required_not_exist){
    const char* argv[] = {"test1.txt"};
    CommandLine::OptionMap options({
        {"input1", {std::string(), true}},
        {"input2", {std::string(), true}}
    });
    EXPECT_THROW(options.parse(1, argv), std::invalid_argument);
}

TEST(unittest_CommandLine, positioned_not_required_exist){
    const char* argv[] = {"test1.txt"};
    CommandLine::OptionMap options({
        {"input1", {std::string("test"), false}}
    });
    EXPECT_NO_THROW(options.parse(1, argv));
    EXPECT_STREQ(std::get<std::string>(options["input1"]).c_str(), "test1.txt");
}

TEST(unittest_CommandLine, positioned_not_required_not_exist){
    const char* argv[] = {};
    CommandLine::OptionMap options({
        {"input1", {std::string("test"), false}}
    });
    EXPECT_NO_THROW(options.parse(0, argv));
    EXPECT_STREQ(std::get<std::string>(options["input1"]).c_str(), "test");
}

TEST(unittest_CommandLine, unpositioned_required_exist){
    const char* argv[] = {"--test", "test1.txt"};
    CommandLine::OptionMap options({
        {"--test", {std::string("test"), true}}
    });
    EXPECT_NO_THROW(options.parse(2, argv));
    EXPECT_STREQ(std::get<std::string>(options["test"]).c_str(), "test1.txt");
}

TEST(unittest_CommandLine, unpositioned_required_not_exist){
    const char* argv[] = {};
    CommandLine::OptionMap options({
        {"--test", {std::string("none"), true}}
    });
    EXPECT_THROW(options.parse(0, argv), std::invalid_argument);
}

TEST(unittest_CommandLine, unpositioned_not_required_exist){
    const char* argv[] = {"--test", "test1.txt"};
    CommandLine::OptionMap options({
        {"--test", {std::string("test"), false}}
    });
    EXPECT_NO_THROW(options.parse(2, argv));
    EXPECT_STREQ(std::get<std::string>(options["test"]).c_str(), "test1.txt");
}

TEST(unittest_CommandLine, unpositioned_not_required_not_exist){
    const char* argv[] = {"--test"};
    CommandLine::OptionMap options({
        {"--test", {std::string("none"), false}}
    });
    EXPECT_NO_THROW(options.parse(1, argv));
    EXPECT_STREQ(std::get<std::string>(options["test"]).c_str(), "none");
}

TEST(unittest_CommandLine, string_type){
    const char* argv[] = {"test1.txt"};
    CommandLine::OptionMap options({
        {"input1", {std::string(), true}}
    });
    EXPECT_NO_THROW(options.parse(1, argv));
    EXPECT_STREQ(std::get<std::string>(options["input1"]).c_str(), "test1.txt");
}

TEST(unittest_CommandLine, use_main_with_alias){
    const char* argv[] = {"--input1", "test"};
    CommandLine::OptionMap options({
        {"--input1,-i", {std::string(), false}}
    });
    EXPECT_NO_THROW(options.parse(2, argv));
    EXPECT_STREQ(std::get<std::string>(options["input1"]).c_str(), "test");
}

TEST(unittest_CommandLine, use_alias){
    const char* argv[] = {"-i", "test"};
    CommandLine::OptionMap options({
        {"--input1,-i", {std::string(), false}}
    });
    EXPECT_NO_THROW(options.parse(2, argv));
    EXPECT_STREQ(std::get<std::string>(options["input1"]).c_str(), "test");
}

TEST(unittest_CommandLine, define_more_alias){
    const char* argv[] = {"-i2", "test"};
    CommandLine::OptionMap options({
        {"--input1,-i,-i2", {std::string(), false}}
    });
    EXPECT_NO_THROW(options.parse(2, argv));
    EXPECT_STREQ(std::get<std::string>(options["input1"]).c_str(), "test");
}

TEST(unittest_CommandLine, string_vector_type){
    const char* argv[] = {"test1.txt", "test2.txt"};
    CommandLine::OptionMap options({
        {"input1", {std::vector<std::string>(), true}}
    });
    EXPECT_NO_THROW(options.parse(2, argv));
    EXPECT_STREQ(std::get<std::vector<std::string>>(options["input1"])[0].c_str(), "test1.txt");
    EXPECT_STREQ(std::get<std::vector<std::string>>(options["input1"])[1].c_str(), "test2.txt");
}

TEST(unittest_CommandLine, bool_type_true){
    const char* argv[] = {"--test_bool"};
    CommandLine::OptionMap options({
        {"--test_bool", {false, false}}
    });
    EXPECT_NO_THROW(options.parse(1, argv));
    EXPECT_TRUE(std::get<bool>(options["test_bool"]));
}

TEST(unittest_CommandLine, bool_type_false){
    const char* argv[] = {};
    CommandLine::OptionMap options({
        {"--test_bool", {false, false}}
    });
    EXPECT_NO_THROW(options.parse(0, argv));
    EXPECT_FALSE(std::get<bool>(options["test_bool"]));
}
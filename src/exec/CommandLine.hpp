#ifndef GUARD_wass_exec_CommandLine
#define GUARD_wass_exec_CommandLine

#include <variant>
#include <string>
#include <utility>
#include <optional>
#include <initializer_list>
#include <unordered_map>
#include <vector>

namespace CommandLine{

using OptionValue = std::variant<
    std::monostate,
    bool,
    std::string,
    std::vector<std::string>
>;

using Option = std::pair<OptionValue, bool>;

class OptionMap{
public:
    OptionMap(std::initializer_list<std::pair<std::string, Option>> initializer);
    void parse(int argc, const char *argv[]);
    OptionValue operator[](std::string key);
private:
    std::unordered_map<std::string, Option> unpositioned;
    std::vector<std::pair<std::string, Option>> positioned;
    std::unordered_map<std::string, std::string> aliases;
};

}

#endif
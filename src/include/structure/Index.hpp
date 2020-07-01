#ifndef GUARD_wass_structure_Index
#define GUARD_wass_structure_Index

#include <variant>
#include <string>
#include <cstdint>

using Index = std::variant<
    uint32_t,
    std::string
>;

#endif
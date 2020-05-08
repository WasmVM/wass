#include <structure/TypeUse.hpp>

TypeUse::TypeUse(const TypeUse& type):
  index(type.index), paramMap(type.paramMap), params(type.params), results(type.results)
{
}
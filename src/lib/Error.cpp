#include <Error.hpp>

template<ErrorType T>
std::ostream& operator<< (std::ostream& os, const Error<T>& err){
  return os;
}
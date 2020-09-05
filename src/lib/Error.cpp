#include <Error.hpp>

template<ErrorType T>
std::ostream& operator<< (std::ostream& os, const Error<T>& err){
  os << err.message;
  return os;
}

template std::ostream& operator<<<ErrorType::ParseError> (std::ostream& os, const Error<ErrorType::ParseError>& err);
template std::ostream& operator<<<ErrorType::GenerateError> (std::ostream& os, const Error<ErrorType::GenerateError>& err);
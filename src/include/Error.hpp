#ifndef GUARD_wass_Error
#define GUARD_wass_Error

#include <string>
#include <ostream>

enum class ErrorType{
  SyntaxError,
};

template<ErrorType T>
class Error;

template<ErrorType T>
std::ostream& operator<< (std::ostream&, const Error<T>&);

template<ErrorType T>
class Error{
private:
  std::string message;
public:
  Error(const std::string message):message(message){};
  
  friend std::ostream& operator<< <>(std::ostream&, const Error<T>&);
};

#endif
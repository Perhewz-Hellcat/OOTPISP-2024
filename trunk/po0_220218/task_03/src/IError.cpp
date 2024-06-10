#include "IError.h"

IError::IError(std::string_view _message) : message(_message) {}

void IError::Print() const
{
    std::cout << "[" << message << "]" << std::endl;
}

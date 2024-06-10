#include "IOError.h"

IOError::IOError(Type type)
    : IError("I/O Error"), error(type)
{
}

void IOError::Print() const
{
    IError::Print();
    std::cout << "Error type " << std::to_string(static_cast<bool>(error)) << std::endl;
}

bool IOError::operator==(const IOError &right) const
{
    return (this->error == right.error);
}

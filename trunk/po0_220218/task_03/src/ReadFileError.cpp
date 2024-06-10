#include "ReadFileError.h"

ReadFileError::ReadFileError(std::string_view _message)
    : IError(_message)
{
}

void ReadFileError::Print() const
{
    IError::Print();
    std::cout << "Error while reading file. Error code: " << std::to_string(errorCode) << std::endl;
}

bool ReadFileError::operator==(const ReadFileError &right) const
{
    return (this->errorCode == right.errorCode);
}

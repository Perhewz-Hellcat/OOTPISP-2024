#include "WriteFileError.h"

WriteFileError::WriteFileError(const uint8_t num)
    : IError("WriteFileError"), writeError(num)
{
}

void WriteFileError::Print() const
{
    IError::Print();
    std::cout << "Write error code: " << writeError << std::endl;
}

bool WriteFileError::operator==(const WriteFileError &right) const
{
    return (this->writeError == right.writeError);
}

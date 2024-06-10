#include "NotEnoughMemory.h"

NotEnoughMemory::NotEnoughMemory(MemoryType type)
    : IError("No memory availiable"), memType(type)
{
}

void NotEnoughMemory::Print() const
{
    IError::Print();
    std::cout << "Memory type: " << std::to_string(static_cast<int8_t>(memType)) << std::endl;
}

bool NotEnoughMemory::operator==(const NotEnoughMemory &right) const
{
    return (this->memType == right.memType);
}

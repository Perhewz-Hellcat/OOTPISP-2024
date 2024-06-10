#pragma once

#include <iostream>
#include <string>

#include "IError.h"

class NotEnoughMemory : public IError
{
public:
    enum class MemoryType : int8_t
    {
        RAM,
        VRAM,
        ROM,
    };

    NotEnoughMemory() = default;
    explicit NotEnoughMemory(MemoryType type);
    NotEnoughMemory(const NotEnoughMemory &oth) = delete;

    ~NotEnoughMemory() override = default;

    void Print() const override;

    inline void SetType(MemoryType type) { memType = type; };

    bool operator==(const NotEnoughMemory &right) const;

private:
    MemoryType memType = MemoryType::RAM;
};

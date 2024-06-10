#pragma once

#include <iostream>
#include <string>

#include "IError.h"

class IOError : public IError
{
public:
    enum class Type : bool
    {
        INPUT,
        OUTPUT,
    };

    IOError() = default;
    explicit IOError(Type type);
    IOError(const IOError &oth) = delete;

    ~IOError() override = default;

    inline Type GetType() const { return error; };

    inline void SetType(Type type) { error = type; };

    void Print() const override;

    IOError &operator=(const IOError &right) = default;
    bool operator==(const IOError &right) const;

private:
    Type error = Type::INPUT;
};
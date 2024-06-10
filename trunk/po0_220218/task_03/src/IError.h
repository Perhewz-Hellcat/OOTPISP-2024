#pragma once

#include <string_view>
#include <exception>
#include <iostream>

class IError
{
public:
    IError() = default;
    explicit IError(std::string_view _message);
    IError(const IError &oth) = delete;

    virtual ~IError() = default;

    virtual void Print() const;

    IError &operator=(const IError &right) = default;
    bool operator==(const IError &right) const = default;

private:
    std::string_view message = "";
};

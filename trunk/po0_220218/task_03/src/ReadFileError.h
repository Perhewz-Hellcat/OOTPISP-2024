#pragma once

#include <string_view>
#include <string>
#include "IError.h"

class ReadFileError : public IError
{
public:
    ReadFileError() = default;
    explicit ReadFileError(std::string_view _message);
    ReadFileError(const ReadFileError &oth) = delete;

    ~ReadFileError() override = default;

    void Print() const override;

    inline void SetErrorCode(const int8_t code) { errorCode = code; };

    bool operator==(const ReadFileError &right) const;

private:
    int8_t errorCode = 0;
};

#pragma once

#include "IError.h"

class WriteFileError : public IError
{
public:
    WriteFileError() = default;
    explicit WriteFileError(const uint8_t num);
    WriteFileError(const WriteFileError &oth) = delete;

    ~WriteFileError() override = default;

    void Print() const override;

    inline void SerWriteError(const uint8_t num) { writeError = num; };

    WriteFileError &operator=(const WriteFileError &right) = default;
    bool operator==(const WriteFileError &right) const;

private:
    uint8_t writeError = 0;
};

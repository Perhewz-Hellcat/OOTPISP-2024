#pragma once

#include <iostream>

#include "IError.h"
#include "IOError.h"
#include "NotEnoughMemory.h"
#include "ReadFileError.h"
#include "WriteFileError.h"

#include <memory>
#include <stdexcept>

class Store
{
public:
    Store() = default;

    void print() const;
    void insert(IError *_err);
    int size() const;

    IError *operator[](const int i);

    struct node
    {
        explicit node(IError *_date)
            : date(_date)
        {
        }

        IError *date;
        std::unique_ptr<node> next = nullptr;
    };

private:
    int _Size = 0;
    std::unique_ptr<node> first = nullptr;
};

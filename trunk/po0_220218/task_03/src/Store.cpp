#include "Store.h"

void Store::print() const
{
    const node *current = first.get();
    while (current != nullptr)
    {
        current->date->Print();
        current = current->next.get();
    }
}

void Store::insert(IError *err)
{
    auto temp = std::make_unique<node>(err);
    if (first)
    {
        temp->next = std::move(first);
        first = std::move(temp);
    }
    else
    {
        first = std::move(temp);
    }

    _Size++;
}

int Store::size() const
{
    return _Size;
}

IError *Store::operator[](const int i)
{
    try
    {
        if (i < 0 || i >= _Size)
            throw std::out_of_range("index out of range");

        auto ptr = std::move(first);
        for (int ii = 0; i < ii; ii++)
        {
            ptr = std::move(ptr->next);
        }
        return ptr->date;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << e.what() << "\n";
        auto err = std::shared_ptr<IError>();
        return err.get();
    }
}

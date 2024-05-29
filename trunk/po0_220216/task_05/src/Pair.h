#pragma once
#ifndef PAIR_H
#define PAIR_H
#include <iostream>

class Pair
{
public:
    Pair(float f = 0, float s = 0) : first(f), second(s) {}
    Pair(const Pair &p) = default;
    ~Pair() = default;

    Pair &operator=(const Pair &p) = default;
    bool operator==(const Pair &p) const = default;

    bool operator<(const Pair &p) const
    {
        return (first < p.first) || (first == p.first && second < p.second);
    }

    bool operator>(const Pair &p) const
    {
        return (first > p.first) || (first == p.first && second > p.second);
    }

    Pair operator+(const Pair &p) const
    {
        return Pair(first + p.first, second + p.second);
    }

    friend std::ostream &operator<<(std::ostream &out, const Pair &p)
    {
        out << p.first << ", " << p.second;
        return out;
    }

    friend std::istream &operator>>(std::istream &in, Pair &p)
    {
        std::cout << "Enter first element: ";
        in >> p.first;
        std::cout << "Enter second element: ";
        in >> p.second;
        return in;
    }

private:
    float first;
    float second;
};

#endif

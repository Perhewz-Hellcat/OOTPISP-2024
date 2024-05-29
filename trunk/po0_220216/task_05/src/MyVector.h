#pragma once
#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <vector>
#include <algorithm>
#include <iostream>

template <class T>
class MyVector
{
public:
    MyVector() = default;
    explicit MyVector(int n);
    ~MyVector() = default;
    void Print() const;
    void Add(const T &a);
    void putMinToEnd();
    void findByKeyAndDelete(T key);
    void addAllMinMaxSum();

private:
    std::vector<T> _vec;
};

#endif

template <class T>
MyVector<T>::MyVector(int n)
{
    T a;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a;
        _vec.push_back(a);
    }
}

template <class T>
void MyVector<T>::Print() const
{
    for (const auto &elem : _vec)
    {
        std::cout << elem << std::endl;
    }
}

template <class T>
void MyVector<T>::Add(const T &a)
{
    _vec.push_back(a);
}

template <class T>
void MyVector<T>::putMinToEnd()
{
    auto min_it = std::ranges::min_element(_vec.begin(), _vec.end());
    if (min_it != _vec.end())
    {
        T min_val = *min_it;
        _vec.erase(min_it);
        _vec.push_back(min_val);
    }
}

template <class T>
void MyVector<T>::findByKeyAndDelete(T key)
{
    auto it = std::ranges::find(_vec.begin(), _vec.end(), key);
    if (it != _vec.end())
    {
        _vec.erase(it);
    }
}

template <class T>
void MyVector<T>::addAllMinMaxSum()
{
    if (_vec.empty())
        return;
    auto [min_it, max_it] = std::ranges::minmax_element(_vec.begin(), _vec.end());
    T sum = *min_it + *max_it;
    for (auto &elem : _vec)
    {
        elem = elem + sum;
    }
}

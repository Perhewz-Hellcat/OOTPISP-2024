#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <numeric>

template <typename T>
class Vector
{
public:
    Vector() = default;
    ~Vector() = default;

    void append(const T &other);
    int currentSize() const;

    int getCurrentSize() const;
    T operator[](const int index) const;
    auto operator*(const T value) const;
    void print() const;

    int getMaxSize() const { return maxSize; };

    void addMaxElement();
    void removeElement(const T &key);
    void addAverageToAllElements();

private:
    std::unique_ptr<std::vector<T>> elements = std::make_unique<std::vector<T>>(2);
    int maxSize = 2;
    int currentLength = 0;
};

template <class T>
void Vector<T>::append(const T &other)
{
    if (currentLength >= maxSize)
    {
        auto newElements = std::make_unique<std::vector<T>>(maxSize * 2);
        for (int i = 0; i < currentLength; ++i)
        {
            (*newElements)[i] = (*elements)[i];
        }

        elements = std::move(newElements);
        maxSize *= 2;
    }
    (*elements)[currentLength] = other;
    currentLength++;
}

template <class T>
auto Vector<T>::operator*(const T value) const
{
    auto newVector = std::make_unique<Vector<T>>();

    for (int i = 0; i < currentLength; i++)
    {
        newVector->append((*elements)[i] * value);
    }

    return newVector;
}

template <class T>
int Vector<T>::currentSize() const
{
    return currentLength;
}

template <class T>
int Vector<T>::getCurrentSize() const
{
    return currentSize();
}

template <class T>
T Vector<T>::operator[](const int i) const
{
    return (*elements)[i];
}

template <class T>
void Vector<T>::print() const
{
    std::cout << "{ ";
    for (int i = 0; i < currentLength; ++i)
    {
        std::cout << (*elements)[i] << " ";
    }
    std::cout << "}" << std::endl;
}

template <class T>
void Vector<T>::addMaxElement()
{
    if (currentLength == 0)
        return;

    T maxElement = *std::max_element(elements->begin(), elements->begin() + currentLength);
    append(maxElement);
}

template <class T>
void Vector<T>::removeElement(const T &key)
{
    auto it = std::find(elements->begin(), elements->begin() + currentLength, key);
    if (it != elements->begin() + currentLength)
    {
        std::move(it + 1, elements->begin() + currentLength, it);
        currentLength--;
    }
}

template <class T>
void Vector<T>::addAverageToAllElements()
{
    if (currentLength == 0)
        return;

    T sum = std::accumulate(elements->begin(), elements->begin() + currentLength, T{});
    T average = sum / currentLength;

    for (int i = 0; i < currentLength; ++i)
    {
        (*elements)[i] += average;
    }
}

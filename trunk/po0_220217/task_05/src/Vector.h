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

    void app(const T &other);
    int currSize() const;

    int getCurrSize() const;
    T operator[](const int index) const;
    auto operator*(const T value) const;
    void print() const;

    int getMaxSize() const { return maxSize; };

    void addElementAtPosition(const T &key, int position);
    void removeElement(const T &key);
    void removeDefferenceBetweenMaxAndMinElement();

private:
    std::unique_ptr<std::vector<T>> elements = std::make_unique<std::vector<T>>(2);
    int maxSize = 2;
    int currLength = 0;
};

template <class T>
void Vector<T>::app(const T &other)
{
    if (currLength >= maxSize)
    {
        auto newElements = std::make_unique<std::vector<T>>(maxSize * 2);
        for (int i = 0; i < currLength; ++i)
        {
            (*newElements)[i] = (*elements)[i];
        }

        elements = std::move(newElements);
        maxSize *= 2;
    }
    (*elements)[currLength] = other;
    currLength++;
}

template <class T>
auto Vector<T>::operator*(const T value) const
{
    auto newVector = std::make_unique<Vector<T>>();

    for (int i = 0; i < currLength; i++)
    {
        newVector->app((*elements)[i] * value);
    }

    return newVector;
}

template <class T>
int Vector<T>::currSize() const
{
    return currLength;
}

template <class T>
int Vector<T>::getCurrSize() const
{
    return currSize();
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
    for (int i = 0; i < currLength; ++i)
    {
        std::cout << (*elements)[i] << " ";
    }
    std::cout << "}" << std::endl;
}

template <class T>
void Vector<T>::addElementAtPosition(const T &key, int position)
{
    if (currLength == 0)
        return;

    auto it = std::find(elements->begin(), elements->begin() + currLength, key);

    if (it != elements->begin() + currLength)
    {
        T foundElem = *it;

        if (position < 0 || position > currLength)
            return;

        elements->insert(elements->begin() + position, foundElem);
        ++currLength;
    }
}

template <class T>
void Vector<T>::removeElement(const T &key)
{
    auto it = std::find(elements->begin(), elements->begin() + currLength, key);
    if (it != elements->begin() + currLength)
    {
        std::move(it + 1, elements->begin() + currLength, it);
        currLength--;
    }
}

template <typename T>
void Vector<T>::removeDefferenceBetweenMaxAndMinElement()
{
    if (currLength == 0)
        return;

    auto maxElem = *std::max_element(elements->begin(), elements->begin() + currLength);
    auto minElem = *std::min_element(elements->begin(), elements->begin() + currLength);

    T difference = maxElem - minElem;

    for (int i = 0; i < currLength; ++i)
    {
        (*elements)[i] -= difference;
    }
}
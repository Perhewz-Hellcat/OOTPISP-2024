#pragma once

#include <iostream>
#include <queue>
#include <algorithm>
#include <numeric>
#include <vector>

template <typename T>
class QVector
{
public:
    QVector() = default;
    ~QVector() = default;

    void append(const T &value);
    int size() const;

    T front() const;
    auto operator*(const T value) const;
    void print() const;

    void addMaxElement();
    void removeElement(const T &key);
    void addAverageToAllElements();

private:
    std::queue<T> elements;

    std::vector<T> toVector() const;
    void fromVector(const std::vector<T> &vec);
};

template <class T>
void QVector<T>::append(const T &value)
{
    elements.push(value);
}

template <class T>
int QVector<T>::size() const
{
    return elements.size();
}

template <class T>
T QVector<T>::front() const
{
    return elements.front();
}

template <class T>
auto QVector<T>::operator*(const T value) const
{
    QVector<T> newVector;
    std::queue<T> tempQueue = elements;

    while (!tempQueue.empty())
    {
        newVector.append(tempQueue.front() * value);
        tempQueue.pop();
    }

    return newVector;
}

template <class T>
void QVector<T>::print() const
{
    std::queue<T> tempQueue = elements;

    std::cout << "{ ";
    while (!tempQueue.empty())
    {
        std::cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    std::cout << "}" << std::endl;
}

template <class T>
void QVector<T>::addMaxElement()
{
    if (elements.empty())
        return;

    std::vector<T> vec = toVector();
    T maxElement = *std::ranges::max_element(vec.begin(), vec.end());
    append(maxElement);
}

template <class T>
void QVector<T>::removeElement(const T &key)
{
    std::vector<T> vec = toVector();
    std::erase(vec, key);
    fromVector(vec);
}

template <class T>
void QVector<T>::addAverageToAllElements()
{
    if (elements.empty())
        return;

    std::vector<T> vec = toVector();
    T sum = std::accumulate(vec.begin(), vec.end(), T{});
    T average = sum / vec.size();

    for (auto &elem : vec)
    {
        elem += average;
    }

    fromVector(vec);
}

template <class T>
std::vector<T> QVector<T>::toVector() const
{
    std::vector<T> vec;
    std::queue<T> tempQueue = elements;

    while (!tempQueue.empty())
    {
        vec.push_back(tempQueue.front());
        tempQueue.pop();
    }

    return vec;
}

template <class T>
void QVector<T>::fromVector(const std::vector<T> &vec)
{
    std::queue<T> newQueue;
    for (const auto &elem : vec)
    {
        newQueue.push(elem);
    }
    elements = std::move(newQueue);
}

#pragma once

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <ranges>

template <typename T>
class VectorOnPriorityQueue
{
public:
    VectorOnPriorityQueue() = default;
    ~VectorOnPriorityQueue() = default;

    void app(const T &value);
    int size() const;

    T front() const;
    auto operator*(const T value) const;
    void print() const;

    void addElementAtPosition(const T &key, int position);
    void removeElement(const T &key);
    void subtractDifferenceMaxMin();

private:
    std::priority_queue<T> elements;

    std::vector<T> toVector() const;
    void fromVector(const std::vector<T> &vec);
};

template <typename T>
void VectorOnPriorityQueue<T>::app(const T &value)
{
    elements.push(value);
}

template <typename T>
int VectorOnPriorityQueue<T>::size() const
{
    return elements.size();
}

template <typename T>
T VectorOnPriorityQueue<T>::front() const
{
    if (!elements.empty())
        return elements.top();
    return T();
}

template <typename T>
auto VectorOnPriorityQueue<T>::operator*(const T value) const
{
    VectorOnPriorityQueue<T> newVector;

    for (const auto &elem : toVector())
    {
        newVector.app(elem * value);
    }

    return newVector;
}

template <typename T>
void VectorOnPriorityQueue<T>::print() const
{
    auto vec = toVector();

    std::cout << "{ ";
    for (const auto &elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << "}" << std::endl;
}

template <class T>
std::vector<T> VectorOnPriorityQueue<T>::toVector() const
{
    std::vector<T> vec;
    std::priority_queue<T> tempQueue = elements;

    while (!tempQueue.empty())
    {
        vec.push_back(tempQueue.top());
        tempQueue.pop();
    }

    std::ranges::reverse(vec.begin(), vec.end());
    return vec;
}

template <typename T>
void VectorOnPriorityQueue<T>::removeElement(const T &key)
{
    std::vector<T> vec = toVector();
    std::erase(vec, key);
    fromVector(vec);
}

template <typename T>
void VectorOnPriorityQueue<T>::subtractDifferenceMaxMin()
{
    if (elements.empty())
        return;

    std::vector<T> vec = toVector();
    T maxElement = *std::ranges::max_element(vec);
    T minElement = *std::ranges::min_element(vec);
    T difference = maxElement - minElement;

    for (auto &elem : vec)
    {
        elem -= difference;
    }

    fromVector(vec);
}

template <typename T>
std::vector<T> VectorOnPriorityQueue<T>::toVector() const
{
    std::vector<T> vec;
    std::priority_queue<T> tempQueue = elements;

    while (!tempQueue.empty())
    {
        vec.push_back(tempQueue.top());
        tempQueue.pop();
    }

    std::ranges::reverse(vec);
    return vec;
}

template <typename T>
void VectorOnPriorityQueue<T>::fromVector(const std::vector<T> &vec)
{
    std::priority_queue<T> newPriorityQueue(vec.begin(), vec.end());
    elements = std::move(newPriorityQueue);
}

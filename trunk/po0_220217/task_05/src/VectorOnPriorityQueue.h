#pragma once

#include <iostream>
#include <queue>
#include <algorithm>
#include <numeric>
#include <vector>

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

template <class T>
void VectorOnPriorityQueue<T>::app(const T &value)
{
    elements.push(value);
}

template <class T>
int VectorOnPriorityQueue<T>::size() const
{
    return elements.size();
}

template <class T>
T VectorOnPriorityQueue<T>::front() const
{
    if (!elements.empty())
        return elements.top();
    return -1;
}

template <class T>
auto VectorOnPriorityQueue<T>::operator*(const T value) const
{
    VectorOnPriorityQueue<T> newVector;

    for (const auto &elem : toVector())
    {
        newVector.app(elem * value);
    }

    return newVector;
}

template <class T>
void VectorOnPriorityQueue<T>::print() const
{
    std::vector<T> vec = toVector();

    std::cout << "{ ";
    for (const auto &elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << "}" << std::endl;
}

template <class T>
void VectorOnPriorityQueue<T>::addElementAtPosition(const T &key, int position)
{
    std::vector<T> vec = toVector();
    auto it = std::ranges::find(vec.begin(), vec.end(), key);

    if (it == vec.end())
        return;

    if (position < 0 || position > vec.size())
        return;

    vec.insert(vec.begin() + position, *it);
    fromVector(vec);
}

template <class T>
void VectorOnPriorityQueue<T>::removeElement(const T &key)
{
    std::vector<T> vec = toVector();
    std::erase(vec, key);
    fromVector(vec);
}

template <class T>
void VectorOnPriorityQueue<T>::subtractDifferenceMaxMin()
{
    if (elements.empty())
        return;

    std::vector<T> vec = toVector();
    T maxElement = *std::ranges::max_element(vec.begin(), vec.end());
    T minElement = *std::ranges::min_element(vec.begin(), vec.end());
    T difference = maxElement - minElement;

    for (auto &elem : vec)
    {
        elem -= difference;
    }

    fromVector(vec);
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

template <class T>
void VectorOnPriorityQueue<T>::fromVector(const std::vector<T> &vec)
{
    std::priority_queue<T> newPriorityQueue;
    for (const auto &elem : vec)
    {
        newPriorityQueue.push(elem);
    }
    elements = std::move(newPriorityQueue);
}
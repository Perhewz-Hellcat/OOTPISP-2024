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

    void application(const T &value);
    int sizeVec() const;

    T front() const;
    auto operator*(const T value) const;
    void show() const;

    void addPos(const T &key, int position);
    void deleteElm(const T &key);
    void subtractMinMax();

private:
    std::priority_queue<T> elements;

    std::vector<T> toVector() const;
    void fromVector(const std::vector<T> &vec);
};

template <typename T>
void VectorOnPriorityQueue<T>::application(const T &value)
{
    elements.push(value);
}

template <typename T>
int VectorOnPriorityQueue<T>::sizeVec() const
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
auto VectorOnPriorityQueue<T>::operator*(const T val) const
{
    VectorOnPriorityQueue<T> newVector;

    for (const auto &elem : toVector())
    {
        newVector.app(elem * val);
    }

    return newVector;
}

template <typename T>
void VectorOnPriorityQueue<T>::show() const
{
    auto vec = toVector();

    std::cout << "{ ";
    for (const auto &elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << "}" << std::endl;
}

template <typename T>
void VectorOnPriorityQueue<T>::addPos(const T &key, int pos)
{
    std::vector<T> vec = toVector();
    auto it = std::ranges::find(vec.begin(), vec.end(), key);

    if (it == vec.end())
        return;

    if (pos < 0 || pos > vec.size())
        return;

    vec.insert(vec.begin() + pos, *it);
    fromVector(vec);
}

template <typename T>
void VectorOnPriorityQueue<T>::deleteElm(const T &key)
{
    std::vector<T> vec = toVector();
    std::erase(vec, key);
    fromVector(vec);
}

template <typename T>
void VectorOnPriorityQueue<T>::subtractMinMax()
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

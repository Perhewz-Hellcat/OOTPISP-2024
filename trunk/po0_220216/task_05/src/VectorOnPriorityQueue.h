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

    T front() const;
    auto operator*(const T value) const;
    void show() const;

    void application(const T &value);

    void fold(const T &key, int position);
    void deleteEl(const T &key);
    void subMinMax();
    int sizeVec() const;

private:
    void fromVector(const std::vector<T> &vec);

    std::vector<T> toVector() const;

    std::priority_queue<T> objects;
};

template <typename T>
int VectorOnPriorityQueue<T>::sizeVec() const
{
    return objects.size();
}

template <typename T>
void VectorOnPriorityQueue<T>::application(const T &value)
{
    objects.push(value);
}

template <typename T>
T VectorOnPriorityQueue<T>::front() const
{
    if (!objects.empty())
        return objects.top();
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
void VectorOnPriorityQueue<T>::fold(const T &key, int position)
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

template <typename T>
void VectorOnPriorityQueue<T>::deleteEl(const T &key)
{
    std::vector<T> vec = toVector();
    std::erase(vec, key);
    fromVector(vec);
}

template <typename T>
void VectorOnPriorityQueue<T>::subMinMax()
{
    if (objects.empty())
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
    std::priority_queue<T> tempQueue = objects;

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
    objects = std::move(newPriorityQueue);
}

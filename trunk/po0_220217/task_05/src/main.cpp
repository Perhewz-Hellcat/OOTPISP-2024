#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <numeric>
#include <optional>

#include "Time.h"
#include "Vector.h"
#include "VectorOnPriorityQueue.h"

template <typename T>
void deleteElementFromDeque(std::deque<T> &deq, const T index)
{
    auto elem = std::ranges::find(deq, index);
    deq.erase(elem);
}

template <typename T>
void addElementAtPosition(std::deque<T> &deq, const T &key, size_t position)
{
    auto it = std::ranges::find(deq, key);
    if (it != deq.end() && position <= deq.size())
    {
        deq.insert(deq.begin() + position, *it);
    }
}

template <typename T>
void subtractDifferenceMaxMin(std::deque<T> &deq)
{
    if (deq.empty())
    {
        return;
    }

    T maxElem = *std::ranges::max_element(deq);
    T minElem = *std::ranges::min_element(deq);
    T difference = maxElem - minElem;

    std::ranges::for_each(deq, [difference](auto &i)
                          { i = i - difference; });
}

template <typename T>
void addElementAtPosition(std::queue<T> &q, const T &key, size_t position)
{
    std::vector<T> elements;
    std::queue<T> tempQueue = q;

    while (!tempQueue.empty())
    {
        elements.push_back(tempQueue.front());
        tempQueue.pop();
    }

    if (auto it = std::ranges::find(elements.begin(), elements.end(), key); it != elements.end() && position <= elements.size())
    {
        elements.insert(elements.begin() + position, *it);
    }

    q = std::queue<T>();
    for (const auto &elem : elements)
    {
        q.push(elem);
    }
}

template <typename T>
void removeElement(std::queue<T> &q, const T &key)
{
    std::queue<T> tempQueue;
    while (!q.empty())
    {
        if (q.front() != key)
        {
            tempQueue.push(q.front());
        }
        q.pop();
    }
    q = std::move(tempQueue);
}

template <typename T>
void subtractDifferenceMaxMin(std::queue<T> &q)
{
    if (q.empty())
    {
        return;
    }

    std::vector<T> elements;
    std::queue<T> tempQueue = q;

    while (!tempQueue.empty())
    {
        elements.push_back(tempQueue.front());
        tempQueue.pop();
    }

    T maxElem = *std::ranges::max_element(elements.begin(), elements.end());
    T minElem = *std::ranges::min_element(elements.begin(), elements.end());
    T difference = maxElem - minElem;

    for (auto &elem : elements)
    {
        elem = elem - difference;
    }

    q = std::queue<T>();
    for (const auto &elem : elements)
    {
        q.push(elem);
    }
}

int main()
{
    // TASK_1

    std::deque<double> doubleDeque = {1.5, 2.9, 4.4, 3.7};

    addElementAtPosition(doubleDeque, 2.9, 3);
    deleteElementFromDeque(doubleDeque, 1.5);
    subtractDifferenceMaxMin(doubleDeque);

    for (const auto &i : doubleDeque)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    // TASK_2

    std::deque<Time> timeDeque = {Time("11:54:16"), Time("17:23:10"), Time("4:35:25"), Time("20:00:00")};

    addElementAtPosition(timeDeque, Time("11:54:16"), 3);
    deleteElementFromDeque(timeDeque, Time("17:23:10"));
    subtractDifferenceMaxMin(timeDeque);

    for (const auto &i : timeDeque)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    // TASK_3

    Vector<int> vector;
    vector.app(5);
    vector.app(0);
    vector.app(7);
    vector.app(4);
    vector.app(8);

    vector.addElementAtPosition(7, 3);
    vector.removeElement(7);
    vector.removeDefferenceBetweenMaxAndMinElement();
    vector.print();

    // TASK_4

    std::queue<Time> timeQueueOfTC;

    timeQueueOfTC.push(Time("12:44:11"));
    timeQueueOfTC.push(Time("14:44:12"));
    timeQueueOfTC.push(Time("1:48:10"));
    timeQueueOfTC.push(Time("23:00:00"));

    addElementAtPosition(timeQueueOfTC, Time("14:44:12"), 2);
    removeElement(timeQueueOfTC, Time("12:44:11"));
    subtractDifferenceMaxMin(timeQueueOfTC);

    std::cout << "{ ";
    while (!timeQueueOfTC.empty())
    {
        std::cout << timeQueueOfTC.front() << " ";
        timeQueueOfTC.pop();
    }
    std::cout << "}" << std::endl;

    // TASK_5

    VectorOnPriorityQueue<int> vectorOnPQ;
    vectorOnPQ.app(1);
    vectorOnPQ.app(6);
    vectorOnPQ.app(9);
    vectorOnPQ.app(11);
    vectorOnPQ.app(18);

    vectorOnPQ.addElementAtPosition(9, 2);
    vectorOnPQ.removeElement(6);
    vectorOnPQ.subtractDifferenceMaxMin();

    vectorOnPQ.print();
}
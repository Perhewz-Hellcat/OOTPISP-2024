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
void removeElementFromDeque(std::deque<T> &deq, const T &value)
{
    auto it = std::ranges::find(deq, value);
    if (it != deq.end())
    {
        deq.erase(it);
    }
}

template <typename T>
void insertElementAtPosition(std::deque<T> &deq, const T &value, size_t position)
{
    if (auto it = std::ranges::find(deq, value); it != deq.end() && position <= deq.size())
    {
        deq.insert(deq.begin() + position, *it);
    }
}

template <typename T>
void adjustElementsByDifference(std::deque<T> &deq)
{
    if (!deq.empty())
    {
        auto [minIt, maxIt] = std::ranges::minmax_element(deq);
        T difference = *maxIt - *minIt;

        std::ranges::for_each(deq, [difference](T &elem)
                              { elem = elem- difference; });
    }
}

template <typename T>
void insertElementAtPosition(std::queue<T> &q, const T &value, size_t position)
{
    std::vector<T> elements;
    while (!q.empty())
    {
        elements.push_back(q.front());
        q.pop();
    }

    if (auto it = std::ranges::find(elements, value); it != elements.end() && position <= elements.size())
    {
        elements.insert(elements.begin() + position, *it);
    }

    for (const auto &elem : elements)
    {
        q.push(elem);
    }
}

template <typename T>
void removeElement(std::queue<T> &q, const T &value)
{
    std::queue<T> tempQueue;
    while (!q.empty())
    {
        if (q.front() != value)
        {
            tempQueue.push(q.front());
        }
        q.pop();
    }
    q = std::move(tempQueue);
}

template <typename T>
void adjustElementsByDifference(std::queue<T> &q)
{
    if (!q.empty())
    {
        std::vector<T> elements;
        while (!q.empty())
        {
            elements.push_back(q.front());
            q.pop();
        }

        auto [minIt, maxIt] = std::ranges::minmax_element(elements);
        T difference = *maxIt - *minIt;

        for (auto &elem : elements)
        {
            elem = elem - difference;
        }

        for (const auto &elem : elements)
        {
            q.push(elem);
        }
    }
}

int main()
{
    // TASK_1

    std::deque<double> doubleDeque = {1.5, 2.9, 4.4, 3.7};

    insertElementAtPosition(doubleDeque, 2.9, 3);
    removeElementFromDeque(doubleDeque, 1.5);
    adjustElementsByDifference(doubleDeque);

    for (const auto &elem : doubleDeque)
    {
        std::cout << elem << " ";
    }

    std::cout << std::endl;

    // TASK_2

    std::deque<Time> timeDeque = {Time("11:54:16"), Time("17:23:10"), Time("4:35:25"), Time("20:00:00")};

    insertElementAtPosition(timeDeque, Time("11:54:16"), 3);
    removeElementFromDeque(timeDeque, Time("17:23:10"));
    adjustElementsByDifference(timeDeque);

    for (const auto &elem : timeDeque)
    {
        std::cout << elem << " ";
    }

    std::cout << std::endl;

    // TASK_3

    Vector<int> vector;
    vector.app(5);
    vector.app(0);
    vector.app(7);
    vector.app(4);
    vector.app(8);

    vector.insertElementAtPosition(7, 3);
    vector.eraseElement(7);
    vector.subtractMaxMinDifference();
    vector.print();

    // TASK_4

    std::queue<Time> timeQueueOfTC;

    timeQueueOfTC.push(Time("12:44:11"));
    timeQueueOfTC.push(Time("14:44:12"));
    timeQueueOfTC.push(Time("1:48:10"));
    timeQueueOfTC.push(Time("23:00:00"));

    insertElementAtPosition(timeQueueOfTC, Time("14:44:12"), 2);
    removeElement(timeQueueOfTC, Time("12:44:11"));
    adjustElementsByDifference(timeQueueOfTC);

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

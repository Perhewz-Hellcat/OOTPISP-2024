#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <numeric>
#include <optional>

#include "CTime.h"
#include "Vector.h"
#include "QVector.h"

template <class T>
void InsertMaxToEnd(std::deque<T> &deq)
{
    auto maximalElement = std::ranges::max_element(deq);
    deq.push_back(*maximalElement);
}

template <class T>
void PopIndexFromDeq(std::deque<T> &deq, const T index)
{
    auto element = std::ranges::find(deq, index);
    deq.erase(element);
}

template <class T>
void AddAverageToDeque(std::deque<T> &deq)
{
    auto avrValue = std::accumulate(deq.begin(), deq.end(), T());
    avrValue = avrValue / static_cast<int>(deq.size());
    std::ranges::for_each(deq, [avrValue](auto &i)
                          { i = i + avrValue; });
}

template <typename T>
void addMaxElement(std::queue<T> &q)
{
    if (q.empty())
    {
        return;
    }

    std::queue<T> tempQueue = q;
    T maxElement = tempQueue.front();
    while (!tempQueue.empty())
    {
        if (tempQueue.front() > maxElement)
        {
            maxElement = tempQueue.front();
        }
        tempQueue.pop();
    }
    q.push(maxElement);
}

// Найти элемент с заданным ключом и удалить его из контейнера
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

// К каждому элементу добавить среднее арифметическое элементов контейнера
template <typename T>
void addAverageToAllElements(std::queue<T> &q)
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

    T sum = std::accumulate(elements.begin(), elements.end(), T{});
    T average = sum / static_cast<int>(elements.size());

    for (auto &elem : elements)
    {
        elem = elem + average;
    }

    q = std::queue<T>();
    for (const auto &elem : elements)
    {
        q.push(elem);
    }
}

int main()
{
    // TASK 1 //

    std::deque<int> dequeOfInts = {1, 2, 4, 3};

    InsertMaxToEnd(dequeOfInts);
    PopIndexFromDeq(dequeOfInts, 2);
    AddAverageToDeque(dequeOfInts);

    for (const auto &i : dequeOfInts)
    {
        std::cout << i << " ";
    }

    // TASK 2 //

    std::deque<CTime> dequeOfTime = {CTime("12:44:11"), CTime("14:44:12"), CTime("1:48:10"), CTime("23:00:00")};

    InsertMaxToEnd(dequeOfTime);
    PopIndexFromDeq(dequeOfTime, CTime("14:44:12"));
    AddAverageToDeque(dequeOfTime);

    for (const auto &i : dequeOfTime)
    {
        std::cout << i << " ";
    }

    // TASK 3 //

    Vector<int> vectorOfInts;
    vectorOfInts.append(1);
    vectorOfInts.append(1);
    vectorOfInts.append(2);
    vectorOfInts.append(0);
    vectorOfInts.append(5);

    vectorOfInts.addMaxElement();
    vectorOfInts.removeElement(1);
    vectorOfInts.addAverageToAllElements();

    vectorOfInts.print();

    // TASK 4 //

    std::queue<CTime> queueOfTCTime;

    queueOfTCTime.push(CTime("12:44:11"));
    queueOfTCTime.push(CTime("14:44:12"));
    queueOfTCTime.push(CTime("1:48:10"));
    queueOfTCTime.push(CTime("23:00:00"));

    addMaxElement(queueOfTCTime);
    removeElement(queueOfTCTime, CTime("14:44:12"));
    addAverageToAllElements(queueOfTCTime);

    std::cout << "{ ";
    while (!queueOfTCTime.empty())
    {
        std::cout << queueOfTCTime.front() << " ";
        queueOfTCTime.pop();
    }
    std::cout << "}" << std::endl;

    // TASK 5 //

    QVector<int> qvectorOfInts;
    qvectorOfInts.append(1);
    qvectorOfInts.append(1);
    qvectorOfInts.append(2);
    qvectorOfInts.append(11);
    qvectorOfInts.append(11);

    qvectorOfInts.addMaxElement();
    qvectorOfInts.removeElement(1);
    qvectorOfInts.addAverageToAllElements();

    qvectorOfInts.print();
}
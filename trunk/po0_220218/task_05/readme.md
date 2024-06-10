# Лабораторная работа №5 #

## Последовательные контейнеры библиотеки STL ##

## Вариант 5 ##
 

## Цель работы ##
Использование последовательных контейнеров библиотеки STL в ОО  программе. 

### Задания для 1-3 ###

```
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

```

### Задания для 4-5 ###

```

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
    T average = sum / elements.size();

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

```



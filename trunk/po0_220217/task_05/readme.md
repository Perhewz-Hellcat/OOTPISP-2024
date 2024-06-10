# Лабораторная работа №5

## Последовательные контейнеры библиотеки STL

## Вариант 3

## Цель работы

Использование последовательных контейнеров библиотеки STL в объектно-ориентированной программе

### Задания для 1 и 2 задачи

```
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

    auto it = std::find(elements.begin(), elements.end(), key);
    if (it != elements.end() && position <= elements.size())
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

    T maxElem = *std::max_element(elements.begin(), elements.end());
    T minElem = *std::min_element(elements.begin(), elements.end());
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

```

### Задания для 3 задачи

```
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

```

### Задания для 4 и 5 задачи

```
template <class T>
void VectorOnPriorityQueue<T>::addElementAtPosition(const T &key, int position)
{
    std::vector<T> vec = toVector();
    auto it = std::find(vec.begin(), vec.end(), key);

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
    T maxElement = *std::max_element(vec.begin(), vec.end());
    T minElement = *std::min_element(vec.begin(), vec.end());
    T difference = maxElement - minElement;

    for (auto &elem : vec)
    {
        elem -= difference;
    }

    fromVector(vec);
}

```

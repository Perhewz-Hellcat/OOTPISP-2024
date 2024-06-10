
# Лабораторная работа №5 #

## Последовательные контейнеры библиотеки STL ##

## Вариант 2 ##

## Цель работы ##

Создание консольного приложения, состоящего из нескольких файлов в системе  программирования Visual Studio. Использование последовательных контейнеров библиотеки STL в ОО  программе.

### Задания для первой и второй задачи ###

```c++

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
                              { elem -= difference; });
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
            elem -= difference;
        }

        for (const auto &elem : elements)
        {
            q.push(elem);
        }
    }
}

```

### Задания для третьей задачи ###

```c++

template <typename T>
void Vector<T>::insertElementAtPosition(const T &key, int position)
{
    if (currLength == 0 || position < 0 || position > currLength)
        return;

    if (auto it = std::ranges::find(*elements | std::views::take(currLength), key); it != elements->begin() + currLength)
    {
        elements->insert(elements->begin() + position, *it);
        ++currLength;
    }
}

template <typename T>
void Vector<T>::eraseElement(const T &key)
{
    if (auto it = std::ranges::find(*elements | std::views::take(currLength), key); it != elements->begin() + currLength)
    {
        std::move(it + 1, elements->begin() + currLength, it);
        --currLength;
    }
}

template <typename T>
void Vector<T>::subtractMaxMinDifference()
{
    if (currLength == 0)
        return;

    auto [minElem, maxElem] = std::ranges::minmax(*elements | std::views::take(currLength));
    T difference = *maxElem - *minElem;

    std::ranges::for_each(*elements | std::views::take(currLength), [difference](T &elem)
                          { elem -= difference; });
}

```

### Задания для четвертой и пятой задачи ###

```c++

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
    auto vec = toVector() | std::views::transform([value](const T &elem)
                                                  { return elem * value; });

    for (const auto &elem : vec)
    {
        newVector.app(elem);
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

template <typename T>
void VectorOnPriorityQueue<T>::addElementAtPosition(const T &key, int position)
{
    auto vec = toVector();
    auto it = std::ranges::find(vec, key);

    if (it == vec.end())
        return;

    if (position < 0 || position > vec.size())
        return;

    vec.insert(vec.begin() + position, key);
    fromVector(vec);
}

template <typename T>
void VectorOnPriorityQueue<T>::removeElement(const T &key)
{
    auto vec = toVector();
    std::erase(vec, key);
    fromVector(vec);
}

template <typename T>
void VectorOnPriorityQueue<T>::subtractDifferenceMaxMin()
{
    if (elements.empty())
        return;

    auto vec = toVector();
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

```

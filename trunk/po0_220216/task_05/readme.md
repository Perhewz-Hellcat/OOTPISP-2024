
# Лабораторная работа №5 #

## Последовательные контейнеры библиотеки STL ##

## Вариант 2 ##

## Цель работы ##

Создание консольного приложения, состоящего из нескольких файлов в системе  программирования Visual Studio. Использование последовательных контейнеров библиотеки STL в ОО  программе.

### Задания для первой и второй, третьей задачи ###

```c++
template <typename T>
void putMinToEnd(std::vector<T>& vec) {
    auto min_it = std::min_element(vec.begin(), vec.end());
    if (min_it != vec.end()) {
        T min_val = *min_it;
        vec.erase(min_it);
        vec.push_back(min_val);
    }
}

template <typename T>
void findByKeyAndDelete(std::vector<T>& vec, const T& key) {
    auto it = std::find(vec.begin(), vec.end(), key);
    if (it != vec.end()) {
        vec.erase(it);
    }
}

template <typename T>
void addAllMinMaxSum(std::vector<T>& vec) {
    if (vec.empty()) return;
    auto [min_it, max_it] = std::minmax_element(vec.begin(), vec.end());
    T sum = *min_it + *max_it;
    for (auto& elem : vec) {
        elem = elem + sum;
    }
}
```

### Задания для четвертой задачи ###

```c++

template<class T>
void MyQueue<T>::putMinToEnd() {
    if (_q.empty()) return;

    std::queue<T> tmp_q;
    T min_val = _q.front();
    _q.pop();
    tmp_q.push(min_val);

    while (!_q.empty()) {
        T val = _q.front();
        _q.pop();
        if (val < min_val) {
            tmp_q.push(min_val);
            min_val = val;
        }
        else {
            tmp_q.push(val);
        }
    }
    tmp_q.push(min_val);

    _q.swap(tmp_q);
}

template<class T>
void MyQueue<T>::findByKeyAndDelete(T key) {
    if (_q.empty()) return;

    std::queue<T> tmp_q;
    bool found = false;

    while (!_q.empty()) {
        T val = _q.front();
        _q.pop();
        if (!found && val == key) {
            found = true;
        }
        else {
            tmp_q.push(val);
        }
    }

    _q.swap(tmp_q);
}

template<class T>
void MyQueue<T>::addAllMinMaxSum() {
    if (_q.empty()) return;

    std::queue<T> tmp_q = _q;
    T min_val = tmp_q.front();
    T max_val = tmp_q.front();
    tmp_q.pop();

    while (!tmp_q.empty()) {
        T val = tmp_q.front();
        tmp_q.pop();
        if (val < min_val) min_val = val;
        if (val > max_val) max_val = val;
    }

    T sum = min_val + max_val;
    tmp_q = _q;

    while (!tmp_q.empty()) {
        T val = tmp_q.front();
        tmp_q.pop();
        _q.push(val + sum);
        _q.pop();
    }
}

```

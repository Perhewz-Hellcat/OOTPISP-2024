#pragma once
#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <queue>
#include <iostream>
#include <algorithm>

template<class T>
class MyQueue {
public:
    MyQueue() = default;
    explicit MyQueue(int n);
    ~MyQueue() = default;
    void Print() const;
    void Add(const T& a);
    void putMinToEnd();
    void findByKeyAndDelete(T key);
    void addAllMinMaxSum();
private:
    std::queue<T> _q;
};

#endif

template<class T>
MyQueue<T>::MyQueue(int n) {
    T a;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        _q.push(a);
    }
}

template<class T>
void MyQueue<T>::Print() const {
    std::queue<T> tmp_q = _q;
    while (!tmp_q.empty()) {
        std::cout << tmp_q.front() << std::endl;
        tmp_q.pop();
    }
}

template<class T>
void MyQueue<T>::Add(const T& a) {
    _q.push(a);
}

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

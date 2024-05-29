#include <iostream>
#include <vector>
#include <algorithm>
#include "Pair.h"
#include "MyVector.h"
#include "MyQueue.h"

template <typename T>
void putMinToEnd(std::vector<T> &vec)
{
    auto min_it = std::min_element(vec.begin(), vec.end());
    if (min_it != vec.end())
    {
        T min_val = *min_it;
        vec.erase(min_it);
        vec.push_back(min_val);
    }
}

template <typename T>
void findByKeyAndDelete(std::vector<T> &vec, const T &key)
{
    auto it = std::find(vec.begin(), vec.end(), key);
    if (it != vec.end())
    {
        vec.erase(it);
    }
}

template <typename T>
void addAllMinMaxSum(std::vector<T> &vec)
{
    if (vec.empty())
        return;
    auto [min_it, max_it] = std::minmax_element(vec.begin(), vec.end());
    T sum = *min_it + *max_it;
    for (auto &elem : vec)
    {
        elem = elem + sum;
    }
}

int main()
{
    std::cout << "Task1" << std::endl;
    std::vector<float> vec = {1.50f, 2.50f, 1.30f, 5.50f};

    putMinToEnd(vec);
    findByKeyAndDelete(vec, 1.50f);
    addAllMinMaxSum(vec);

    for (const auto &elt : vec)
    {
        std::cout << elt << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    std::cout << "Task2" << std::endl;
    std::vector<Pair> pairVec = {{1.50f, 2.50f}, {1.20f, 2.40f}, {1.10f, 2.30f}, {2.50f, 3.50f}, {2.00f, 3.00f}};

    putMinToEnd(pairVec);
    findByKeyAndDelete(pairVec, {1.50f, 2.50f});
    addAllMinMaxSum(pairVec);

    for (const auto &elt : pairVec)
    {
        std::cout << elt << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    std::cout << "Task3" << std::endl;
    MyVector<Pair> myPairVec;
    myPairVec.Add({1.50f, 2.50f});
    myPairVec.Add({1.20f, 2.40f});
    myPairVec.Add({1.10f, 2.30f});
    myPairVec.Add({2.50f, 3.50f});
    myPairVec.Add({2.00f, 3.00f});

    myPairVec.putMinToEnd();
    myPairVec.findByKeyAndDelete({1.20f, 2.40f});
    myPairVec.addAllMinMaxSum();
    myPairVec.Print();

    std::cout << "-----------------------------------" << std::endl;

    std::cout << "Task4" << std::endl;
    MyQueue<Pair> myPairQueue;
    myPairQueue.Add({1.50f, 2.50f});
    myPairQueue.Add({1.20f, 2.40f});
    myPairQueue.Add({1.10f, 2.30f});
    myPairQueue.Add({2.50f, 3.50f});

    myPairQueue.putMinToEnd();
    myPairQueue.findByKeyAndDelete({1.20f, 2.40f});
    myPairQueue.addAllMinMaxSum();
    myPairQueue.Print();

    return 0;
}

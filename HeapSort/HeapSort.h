#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>
#include <algorithm>
#include <iostream>

// 堆排序函数
template <typename T>
void heapsort(std::vector<T>& a);

// 内部方法，用于构建堆和删除最大元素
template <typename T>
void percDown(std::vector<T>& a, int i, int n);

#endif 

// 实现堆排序
template <typename T>
void heapsort(std::vector<T>& a) {
    for (int i = a.size() / 2 - 1; i >= 0; --i)
        percDown(a, i, a.size());
    for (int j = a.size() - 1; j > 0; --j) {
        std::swap(a[0], a[j]);
        percDown(a, 0, j);
    }
}

// 内部方法，用于构建堆和删除最大元素
template <typename T>
void percDown(std::vector<T>& a, int i, int n) {
    int child;
    T x = a[i];
    for (; 2 * i + 1 < n; i = child) {
        child = 2 * i + 1;
        if (child != n - 1 && a[child] < a[child + 1])
            ++child;
        if (x >= a[child])
            break;
        a[i] = a[child];
    }
    a[i] = x;
}
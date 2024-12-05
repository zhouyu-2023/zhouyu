#include "HeapSort.h"
#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>

template <typename T>
bool check(const std::vector<T>& a) {
    for (size_t i = 1; i < a.size(); ++i) {
        if (a[i - 1] > a[i]) {
            return false;
        }
    }
    return true;
}

// 生成随机序列
template <typename T>
void R1(std::vector<T>& v, int n) {
    std::random_device x1;
    std::mt19937 x2(x1());
    std::uniform_int_distribution<T> x3;
    for (int i = 0; i < n; ++i) {
        v.push_back(x3(x2));
    }
}

// 生成有序序列
void R2(std::vector<int>& v, int n) {
    for (int i = 0; i < n; ++i) {
        v.push_back(i);
    }
}

// 生成逆序序列
void R3(std::vector<int>& v, int n) {
    for (int i = 0; i < n; ++i) {
        v.push_back(n - i);
    }
}

// 生成部分元素重复序列
void R4(std::vector<int>& v, int n) {
    std::random_device y1;
    std::mt19937 y2(y1());
    std::uniform_int_distribution<> y3(0, n / 5); 
    for (int i = 0; i < n; ++i) {
        v.push_back(y3(y2));
    }
}

int main() {
    const int N = 1000000;
    std::vector<int> randomVec(N), orderedVec(N), reverseVec(N), repetitiveVec(N);

    // 生成测试数据
    R1(randomVec, N);
    R2(orderedVec, N);
    R3(reverseVec, N);
    R4(repetitiveVec, N);

    // 测试随机序列
    auto start = std::chrono::high_resolution_clock::now();
    heapsort(randomVec);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> R1HeapsortTime = end - start;
    std::cout << "随机序列 heapsort : " << R1HeapsortTime.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    std::sort_heap(randomVec.begin(), randomVec.end());
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> R1SortHeapTime = end - start;
    std::cout << "随机序列 sort_heap : " << R1SortHeapTime.count() << " s\n";

    // 测试有序序列
    start = std::chrono::high_resolution_clock::now();
    heapsort(orderedVec);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> R2HeapsortTime = end - start;
    std::cout << "有序序列 heapsort : " << R2HeapsortTime.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    std::sort_heap(orderedVec.begin(), orderedVec.end());
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> R2SortHeapTime = end - start;
    std::cout << "有序序列 sort_heap : " << R2SortHeapTime.count() << " s\n";

    // 测试逆序序列
    start = std::chrono::high_resolution_clock::now();
    heapsort(reverseVec);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> R3HeapsortTime = end - start;
    std::cout << "逆序序列 heapsort : " << R3HeapsortTime.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    std::sort_heap(reverseVec.begin(), reverseVec.end());
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> R3SortHeapTime = end - start;
    std::cout << "逆序序列 sort_heap : " << R3SortHeapTime.count() << " s\n";

    // 测试部分元素重复序列
    start = std::chrono::high_resolution_clock::now();
    heapsort(repetitiveVec);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> R4HeapsortTime = end - start;
    std::cout << "重复序列 heapsort : " << R4HeapsortTime.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    std::sort_heap(repetitiveVec.begin(), repetitiveVec.end());
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> R4SortHeapTime = end - start;
    std::cout << "重复序列 sort_heap : " << R4SortHeapTime.count() << " s\n";

    return 0;
}

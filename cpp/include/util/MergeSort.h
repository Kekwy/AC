//
// Created by Kekwy on 2023/8/29.
//

#ifndef CPP_MERGESORT_H
#define CPP_MERGESORT_H

#include <vector>

using namespace std;

void merge(vector<int> &arr, vector<int> &auxiliaryArr, int begin, int mid, int end) {
    for (int i = begin; i <= mid; i++) {
        auxiliaryArr[i] = arr[i];
    }
    for (int i = mid + 1; i <= end; i++) {
        auxiliaryArr[i] = arr[mid + 1 + (end - i)]; // 逆序拷贝
    }
    int lp = begin, rp = end;
    for (int i = begin; i <= end; i++) {
        if (auxiliaryArr[lp] <= auxiliaryArr[rp]) arr[i] = auxiliaryArr[lp++];
        else arr[i] = auxiliaryArr[rp--];
    }
}

void sort(vector<int> &arr, vector<int> &auxiliaryArr, int begin, int end) {
    if (begin >= end) return;
    int mid = begin + (end - begin) / 2; // 加法代替乘法防止溢出
    sort(arr, auxiliaryArr, begin, mid);
    sort(arr, auxiliaryArr, mid + 1, end);
    merge(arr, auxiliaryArr, begin, mid, end);
}

void mergeSort(vector<int> &arr, int begin, int end) {
    if (begin >= end) return;
    auto auxiliaryArr = vector<int>(arr.size());
    sort(arr, auxiliaryArr, begin, end);
}

#endif //CPP_MERGESORT_H

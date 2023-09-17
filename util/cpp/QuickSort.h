//
// Created by Kekwy on 2023/8/29.
//

#ifndef CPP_BINARYSEARCH_H
#define CPP_BINARYSEARCH_H

#include <vector>

using namespace std;

void quickSort(vector<int> &arr, int begin, int end) {
    if (begin >= end) return;
    int pivot = arr[begin];
    int lPtr = begin, rPtr = end - 1;
    bool flag = true;
    while (lPtr < rPtr) {
        if (flag) {
            if (arr[rPtr] <= pivot) {
                arr[lPtr] = arr[rPtr];
                lPtr++;
                flag = false;
            }
            else {
                rPtr--;
            }
        }
        else {
            if (arr[lPtr] > pivot) {
                arr[rPtr] = arr[lPtr];
                rPtr--;
                flag = true;
            }
            else {
                lPtr++;
            }
        }
    }
    arr[lPtr] = pivot;
    quickSort(arr, begin, lPtr);
    quickSort(arr, lPtr + 1, end);
}

#endif //CPP_BINARYSEARCH_H

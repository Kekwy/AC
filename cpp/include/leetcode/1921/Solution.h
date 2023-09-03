//
// Created by Kekwy on 2023/9/3.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

using namespace std;

#include <vector>

class Solution {

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

public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
        vector<int> arrivingTime;
        for (int i = 0; i < dist.size(); i++) {
            if (dist[i] % speed[i] != 0) arrivingTime.push_back(dist[i] / speed[i] + 1);
            else arrivingTime.push_back(dist[i] / speed[i]);
        }
        // quickSort(arrivingTime, 0, arrivingTime.size()); 触发快速排序的最差情况
        mergeSort(arrivingTime, 0, arrivingTime.size() - 1);
        int n = 0;
        for (int i = 0; i < arrivingTime.size(); i++) {
            if (arrivingTime[i] <= i) break;
            n++;
        }
        return n;
    }
};

#endif //CPP_SOLUTION_H

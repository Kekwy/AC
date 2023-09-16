//
// Created by Kekwy on 2023/9/16.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {

    int res = 0;

    // 快排中间过程会产生新的逆序对，且部分消除逆序对的过程不可察觉，故无法求解原数组中逆序对的个数
    /* void quickSort(int begin, int end, vector<int>& nums) {
        if (begin >= end) return;
        int pivot = nums[begin];
        int left = 0, right = 0;
        int lp = begin, rp = end - 1;
        bool flag = false;
        while (lp < rp) {
            if (flag) {
                if (nums[lp] > pivot) {
                    nums[rp--] = nums[lp];
                    flag = false;
                    left++;
                } else {
                    lp++;
                }
            } else {
                if (nums[rp] < pivot) {
                    nums[lp++] = nums[rp];
                    flag = true;
                    right++;
                } else {
                    rp--;
                }
            }
        }
        nums[lp] = pivot;
        res += left * right;
        quickSort(begin, lp, nums);
        quickSort(lp + 1, end, nums);
    } */

    // 归并排序可以察觉所有消除逆序对的步骤，且不会产生新的逆序对
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
            else { // 根据本题的描述增加的代码
                arr[i] = auxiliaryArr[rp--];
                res += (mid + 1 - begin) - (lp - begin);
            }
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
    int reversePairs(vector<int> &nums) {
        // quickSort(0, nums.size(), nums);
        mergeSort(nums, 0, nums.size() - 1);
        return res;
    }
};

#endif //CPP_SOLUTION_H

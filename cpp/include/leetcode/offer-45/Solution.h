//
// Created by Kekwy on 2023/9/16.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define VERSION 1

#if VERSION == 0
class Solution {
    // 按字符对比版
    bool compare(const string &s1, const string &s2) {
        const string *longer = &s1, *shorter = &s2;
        bool flag = false;
        if (s1.length() < s2.length()) {
            longer = &s2;
            shorter = &s1;
            flag = true;
        }
        int i = 0;
        for (; i < shorter->length(); i++) {
            if ((*longer)[i] < (*shorter)[i]) {
                return true ^ flag;
            }
            else if ((*longer)[i] > (*shorter)[i]) {
                return false ^ flag;
            }
        }
        if (longer->length() > shorter->length()) {
            return compare(longer->substr(shorter->length(), longer->length() - shorter->length()), *shorter) ^ flag;
        }
        return false ^ flag;
    }

    void merge(vector<string> &arr, vector<string> &auxiliaryArr, int begin, int mid, int end) {
        for (int i = begin; i <= mid; i++) {
            auxiliaryArr[i] = arr[i];
        }
        for (int i = mid + 1; i <= end; i++) {
            auxiliaryArr[i] = arr[mid + 1 + (end - i)]; // 逆序拷贝
        }
        int lp = begin, rp = end;
        for (int i = begin; i <= end; i++) {
            if (compare(auxiliaryArr[lp], auxiliaryArr[rp])) arr[i] = auxiliaryArr[lp++];
            else arr[i] = auxiliaryArr[rp--];
        }
    }

    void sort(vector<string> &arr, vector<string> &auxiliaryArr, int begin, int end) {
        if (begin >= end) return;
        int mid = begin + (end - begin) / 2; // 加法代替乘法防止溢出
        sort(arr, auxiliaryArr, begin, mid);
        sort(arr, auxiliaryArr, mid + 1, end);
        merge(arr, auxiliaryArr, begin, mid, end);
    }

    void mergeSort(vector<string> &arr, int begin, int end) {
        if (begin >= end) return;
        auto auxiliaryArr = vector<string>(arr.size());
        sort(arr, auxiliaryArr, begin, end);
    }

public:
    string minNumber(vector<int> &nums) {
        // 将所有整型数转化为字符串方便比较和拼接
        vector<string> strNums;
        for (const int &n : nums) {
            strNums.push_back(to_string(n));
        }
        mergeSort(strNums, 0, strNums.size() - 1);
        string res;
        for (const string &s : strNums) {
            res += s;
        }
        return res;
    }
};


#elif VERSION == 1

class Solution {

public:
    string minNumber(vector<int> &nums) {
        vector<string> strNums;
        for (const int &n : nums) {
            strNums.push_back(to_string(n));
        }
        sort(strNums.begin(), strNums.end(), [](const string &s1, const string &s2) {
            return s1 + s2 < s2 + s1;   // 利用运算符简单实现对比
        });
        string res;
        for (const string &s : strNums) {
            res += s;
        }
        return res;
    }
};

#endif

#endif //CPP_SOLUTION_H

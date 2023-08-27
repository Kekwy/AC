//
// Created by Kekwy on 2023/8/27.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {

    void quickSort(vector<vector<int>>& intervals, int begin, int end) {
        if (begin >= end) return; //
        vector<int> pivot = intervals[begin];
        int lPtr = begin, rPtr = end - 1;
        bool flag = true;
        while(lPtr < rPtr) {
            if (flag) {
                if (intervals[rPtr][0] < pivot[0]) {
                    flag = false;
                    intervals[lPtr] = intervals[rPtr];
                    lPtr++;
                } else {
                    rPtr--;
                }
            } else {
                if (intervals[lPtr][0] >= pivot[0]) { // 
                    flag = true;
                    intervals[rPtr] = intervals[lPtr];
                    rPtr--;
                } else {
                    lPtr++;
                }
            }
        }
        intervals[lPtr] = pivot;
        quickSort(intervals, begin, lPtr);
        quickSort(intervals, lPtr + 1, end);
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        quickSort(intervals, 0, intervals.size()); // 将每个区间按起始值大小递增排序
        auto res = vector<vector<int>>();
        int lBound = intervals[0][0], rBound = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > rBound) {
                res.push_back({lBound, rBound});
                lBound = intervals[i][0];
                rBound = intervals[i][1];
            } else if (intervals[i][1] > rBound) { //
                rBound = intervals[i][1];
            }
        }
        res.push_back({lBound, rBound});
        return res;
    }
};

#endif //CPP_SOLUTION_H

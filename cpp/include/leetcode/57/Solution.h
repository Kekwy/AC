//
// Created by Kekwy on 2023/8/28.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto res = vector<vector<int>>();
        bool flag = false;
        int lBound = newInterval[0], rBound = newInterval[1];
        for (int i = 0; i < intervals.size(); i++) {
            if (flag) {
                res.push_back(intervals[i]);
            } else {
                if (rBound < intervals[i][0]) {
                    res.push_back({lBound, rBound});
                    res.push_back(intervals[i]);
                    flag = true;
                } else if (lBound > intervals[i][1]) {
                    res.push_back(intervals[i]);
                } else {
                    lBound = lBound < intervals[i][0]? lBound : intervals[i][0];
                    rBound = rBound > intervals[i][1]? rBound : intervals[i][1];
                }
            }
        }
        if (!flag) {
            res.push_back({lBound, rBound});
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

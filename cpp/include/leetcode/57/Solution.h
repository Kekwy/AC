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

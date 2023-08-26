//
// Created by Kekwy on 2023/8/26.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        auto res = vector<string>();
        if (nums.empty()) return res;
        int begin = nums[0], end = nums[0];
        for(int i = 0; i + 1 < nums.size(); i++) {
//            if (nums[i + 1] - nums[i] == 1) { // 减法溢出
            if (nums[i + 1] == nums[i] + 1) { 
                end = nums[i + 1];
            } else {
                if (begin == end) {
                    res.push_back(to_string(begin));
                } else {
                    res.push_back(to_string(begin) + "->" + to_string(end));
                }
                begin = nums[i + 1];
                end = nums[i + 1];
            }
        }
        if (begin == end) {
            res.push_back(to_string(begin));
        } else {
            res.push_back(to_string(begin) + "->" + to_string(end));
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

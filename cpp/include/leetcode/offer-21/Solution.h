//
// Created by Kekwy on 2023/8/31.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if (nums.empty()) return {}; //
        int lPtr = 0;
        int rPtr = nums.size() - 1;
        int tmp = nums[0];
        bool flag = true;
        auto res = vector<int>(nums.size());
        while (lPtr < rPtr) {
            if (flag) {
                if (nums[rPtr] % 2 == 1) {
                    res[lPtr] = nums[rPtr];
                    lPtr++;
                    flag = false;
                } else {
                    res[rPtr] = nums[rPtr];
                    rPtr--;
                }
            } else {
                if (nums[lPtr] % 2 == 0) {
                    res[rPtr] = nums[lPtr];
                    rPtr--;
                    flag = true;
                } else {
                    res[lPtr] = nums[lPtr];
                    lPtr++;
                }
            }
        }
        res[lPtr] = tmp;
        return res;
    }
};

#endif //CPP_SOLUTION_H

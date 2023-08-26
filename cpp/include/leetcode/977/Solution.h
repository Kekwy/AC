//
// Created by Kekwy on 2023/8/26.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        int ptr = nums.size() - 1;
        auto res = vector<int>();
        res.resize(nums.size());
        while(i <= j) {
            int a =  nums[i] * nums[i];
            int b =  nums[j] * nums[j];
            if (a >= b) {
                i++;
                res[ptr] = a;
            } else {
                j--;
                res[ptr] = b;
            }
            ptr--;
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

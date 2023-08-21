//
// Created by Kekwy on 2023/8/12.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;


class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int lPtr = 0, rPtr = (int) nums.size() - 1;
        while (lPtr <= rPtr) {
            if (nums[lPtr] == val) {
                if (nums[rPtr] == val) {
                    rPtr--;
                    continue;
                } else {
                    nums[lPtr] = nums[rPtr];
                    lPtr++;
                    rPtr--;
                }
            } else {
                lPtr++;
            }
        }
        return rPtr + 1;
    }
};

#endif //CPP_SOLUTION_H

//
// Created by Kekwy on 2023/8/12.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int quickPtr = 1, lowPtr = 0;
        while (quickPtr < nums.size()) {
            if(nums[lowPtr] == nums[quickPtr]) {
                quickPtr++;
            }
        }
        return lowPtr + 1;
    }
};

#endif //CPP_SOLUTION_H

//
// Created by Kekwy on 2023/8/26.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowPtr = 0, quickPtr = 0;
        while(quickPtr < nums.size()) {
            if (nums[quickPtr] == 0) {
                quickPtr++;
            } else {
                nums[slowPtr++] = nums[quickPtr++];
            }
        }
        while (slowPtr < nums.size()) {
            nums[slowPtr++] = 0;
        }
	}
};

#endif //CPP_SOLUTION_H

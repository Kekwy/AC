//
// Created by Kekwy on 2023/9/16.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int i, j;
        for (i = nums.size() - 2; i >= 0 && nums[i] >= nums[i + 1]; i--);
        if (i < 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        for (j = nums.size() - 1; j > 0 && nums[j] <= nums[i]; j--);
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};
#endif //CPP_SOLUTION_H

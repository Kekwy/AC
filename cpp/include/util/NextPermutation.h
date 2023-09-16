//
// Created by Kekwy on 2023/9/16.
//

#ifndef CPP_NEXT_PERMUTATION_H
#define CPP_NEXT_PERMUTATION_H

#include <vector>

using namespace std;

class NextPermutation {

public:
    static void nextPermutation(vector<int> &nums) {
        int i, j;
        for (i = nums.size() - 2; i >= 0 && nums[i] >= nums[i + 1]; i--);
        if (i >= 0) {
            for (j = nums.size() - 1; j > 0 && nums[j] <= nums[i]; j--);
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

#endif //CPP_NEXT_PERMUTATION_H

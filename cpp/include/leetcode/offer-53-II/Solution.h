//
// Created by Kekwy on 2023/9/2.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int begin = 0, end = nums.size();
        while(begin < end) {
            int mid = (begin + end) / 2;
            if (nums[mid] == mid) begin = mid + 1;
            else end = mid;
        }
        return begin;
    }
};

#endif //CPP_SOLUTION_H

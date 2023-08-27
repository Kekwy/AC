//
// Created by Kekwy on 2023/8/26.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int curSum = 0;
        int lPtr = 0, rPtr = 0;
        bool flag = true;
        while (rPtr < nums.size()) {
            curSum += nums[rPtr++];
            if (!flag) {  // 第一次达到目标和之后，滑动窗口的大小只减不增 
                do {
                    curSum -= nums[lPtr++];
                } while(curSum - nums[lPtr] >= target);
            } else if (flag && curSum >= target) { // 第一次达到目标和
                flag = false;
            }
        }
        if (flag) return 0;
        while(curSum - nums[lPtr] >= target) {   // 滑动窗口滑至最右端后，调整滑动窗口大小
            curSum -= nums[lPtr++];
        }
        return rPtr - lPtr;
    }
};

#endif //CPP_SOLUTION_H

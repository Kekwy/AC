//
// Created by Kekwy on 2023/8/31.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        // 通过二分查找找到与 target / 2 最接近的数的下标，以该下标为中心向两边查找
        int begin = 0, end = nums.size();
        int pos = -1;
        int tmp = target / 2;
        while (begin < end) {
            pos = (begin + end) / 2;
            if (nums[pos] > tmp) end = pos;
            else if (nums[pos] < tmp) begin = pos + 1;
            else break;
        }
        int lp, rp;
        if (2 * nums[pos] > target) {
            rp = pos;
            lp = pos - 1;
        } else if (2 * nums[pos] < target) {
            rp = pos + 1;
            lp = pos;
        } else {
            rp = pos + 1;
            lp = pos - 1;
        }
        auto res = vector<int>();
        while (lp >= 0 && rp < nums.size()) {
            int sum = nums[lp] + nums[rp];
            if (sum < target) rp++;
            else if (sum > target) lp--;
            else {
                res.push_back(nums[lp]);
                res.push_back(nums[rp]);
                break; // 
            }
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

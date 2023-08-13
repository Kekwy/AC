//
// Created by Kekwy on 2023/8/13.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {

private:

    int searchRightBound(vector<int> &nums, int target, int low, int high) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] != target) {      // 右侧部分只有大于等于 target 的元素
                high = mid - 1;
            } else {
                if ((mid == high || nums[mid + 1] != target)) return mid;
                else low = mid + 1;
            }
        }
        return -1;
    }

    int searchLeftBound(vector<int> &nums, int target, int low, int high) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] != target) {      // 左侧部分只有小于等于 target 的元素
                low = mid + 1;
            } else {
                if ((mid == low || nums[mid - 1] != target)) return mid;
                else high = mid - 1;
            }
        }
        return -1;
    }


public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int low = 0, high = (int) nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (target < nums[mid]) high = mid - 1;
            else if (target > nums[mid]) low = mid + 1;
            else {
                int left = mid, right = mid;
                if (mid > 0 && nums[mid - 1] == target) {
                    left = searchLeftBound(nums, target, low, mid - 1);
                }
                if (mid < nums.size() - 1 && nums[mid + 1] == target) {
                    right = searchRightBound(nums, target, mid + 1, high);
                }
                return {left, right};
            }
        }
        return {-1, -1};
    }
};

#endif //CPP_SOLUTION_H

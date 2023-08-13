//
// Created by 68278 on 2023/8/13.
//

#ifndef CPP_BINARYSEARCH_H
#define CPP_BINARYSEARCH_H

#include <vector>

using namespace std;

int search(vector<int> &nums, int target) {
    int low = 0, high = (int) nums.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (target == nums[mid]) return mid;
        else if (target < nums[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

#endif //CPP_BINARYSEARCH_H

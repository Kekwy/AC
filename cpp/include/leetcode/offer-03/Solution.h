//
// Created by Kekwy on 2023/9/1.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int> &nums) {
        int hashTable[100001] = { 0 };
        for (int i = 0; i < nums.size(); i++) {
            hashTable[nums[i]]++;
            if (hashTable[nums[i]] > 1) return nums[i];
        }
        return -1;
    }
};

#endif //CPP_SOLUTION_H

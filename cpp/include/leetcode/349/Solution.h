//
// Created by Kekwy on 2023/9/3.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

using namespace std;

#include <vector>

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        bool hashTable[1001] = { false };
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) {
            hashTable[nums1[i]] = true;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (hashTable[nums2[i]]) {
                hashTable[nums2[i]] = false;
                res.push_back(nums2[i]);
            }
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

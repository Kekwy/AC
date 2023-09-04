//
// Created by Kekwy on 2023/9/4.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    //     int res = 0;
    //     unordered_map<int, int> sumMap;
    //     for (int i = 0; i < nums1.size(); i++) {
    //         for (int j = 0; j < nums2.size(); j++) {
    //             sumMap[nums1[i] + nums2[j]]++;
    //         }
    //     }
    //     for (int i = 0; i < nums3.size(); i++) {
    //         for (int j = 0; j < nums4.size(); j++) {
    //             int tmp = -(nums3[i] + nums4[j]);
    //             if (sumMap.count(tmp)) {
    //                 res += sumMap[tmp];
    //             }
    //         }
    //     }
    //     return res;
    // }
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res = 0;
        unordered_map<int, int> sumMap;
        for (int a : nums1) {
            for (int b : nums2) {
                sumMap[a + b]++;
            }
        }
        for (int c : nums3) {
            for (int d : nums4) {
                int tmp = -(c + d);
                if (sumMap.find(tmp) != sumMap.end()) {
                    res += sumMap[tmp];
                }
            }
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

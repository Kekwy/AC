//
// Created by Kekwy on 2023/9/5.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int p1 = 0, p2 = 0;
        while (p1 < nums1.size() && p2 < nums2.size()) {
            if (nums1[p1] < nums2[p2]) p1++;
            else if (nums1[p1] > nums2[p2]) p2++;
            else return nums1[p1];
        }
        if (nums1[0] < nums2[0]) return nums1[0] * 10 + nums2[0];
        return nums2[0] * 10 + nums1[0];
    }
};

#endif //CPP_SOLUTION_H

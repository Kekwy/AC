//
// Created by Kekwy on 2023/9/3.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // vector<int> twoSum(vector<int> &nums, int target) {
    //     vector<int> res;
    //     unordered_map<int, vector<int>> map;
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (map.count(nums[i])) map[nums[i]].push_back(i);
    //         else map[nums[i]] = { i };
    //     }
    //     for (int i = 0; i < nums.size(); i++) { // 最坏情况时间复杂度为 O(n^2)
    //         int tmp = target - nums[i];
    //         if (map.count(tmp)) {
    //             vector<int> positions = map[tmp];
    //             for (int j = 0; j < positions.size(); j++) {
    //                 if (positions[j] != i) {
    //                     res.push_back(i);
    //                     res.push_back(positions[j]);
    //                     return res;
    //                 }
    //             }
    //         }
    //     }
    //     return res;
    // }
    vector<int> twoSum(vector<int> &nums, int target) {  // 遍历数组的过程进行寻找就不存在重复元素下标被覆盖的问题
        vector<int> res;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = target - nums[i];
            if (map.count(tmp)) {
                res.push_back(i);
                res.push_back(map[tmp]);
                break;
            }
            map[nums[i]] = i;
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

//
// Created by Kekwy on 2023/8/11.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 考虑到数组在内存中的缓存方式，不应该模拟遍历对角线的过程，而应该逐行访问二维数组
     */
    int diagonalSum(vector<vector<int>> &mat) {
        int n = (int) mat.size() - 1;
        int stepLength = 1;
        int i = 0;
        int res = 0;
        for (const auto &item: mat) {
            int a = i, b = n - i;
            if (a == b) {
                res += item[a];
            } else {
                res += item[a] + item[b];
            }
            if (a == b) stepLength = -1;
            if (a == b - 1) {   // ！！需要特殊判断！！
                switch (stepLength) {
                    case 1:
                        stepLength = 0;
                        break;
                    case 0:
                        stepLength = -1;
                        break;
                    default:
                        break;
                }
            }
            i += stepLength;
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

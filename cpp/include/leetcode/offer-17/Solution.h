//
// Created by Kekwy on 2023/9/16.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

// 需要考虑大数的情况，但是力扣的评测没有设置好
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        int maxVal = 0;
        while (n > 0) {
            maxVal = maxVal * 10 + 9;
            n--;
        }
        for (int i = 1; i <= maxVal; i++) {
            res.push_back(i);
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

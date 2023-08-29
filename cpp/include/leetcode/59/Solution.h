//
// Created by Kekwy on 2023/8/28.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {

public:
    vector<vector<int>> generateMatrix(int n) {
        auto res = vector<vector<int>>();
        res.resize(n);
        for (int i = 0; i < n; i++) {
            res[i].resize(n);
        }
        int i = 1;
        int loop = 0;
        int m = n / 2;
        while (loop < m) {
            for (int j = loop; j < n - loop - 1; j++) {
                res[loop][j] = i;
                i++;
            }
            for (int j = loop; j < n - loop - 1; j++) {
                res[j][n - loop - 1] = i;
                i++;
            }
            for (int j = n - loop - 1; j > loop; j--) {
                res[n - loop - 1][j] = i;
                i++;
            }
            for (int j = n - loop - 1; j > loop; j--) {
                res[j][loop] = i;
                i++;
            }
            loop++;
        }
        if (n % 2 == 1) {
            res[m][m] = i;
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

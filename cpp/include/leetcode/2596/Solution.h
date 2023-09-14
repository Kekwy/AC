//
// Created by Kekwy on 2023/9/7.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>> &grid) {
        if (grid[0][0] != 0) return false; // 骑士会从棋盘的 左上角 出发
        int n = grid.size();
        auto steps = vector<vector<int>>(n * n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                steps[grid[i][j]][0] = i;
                steps[grid[i][j]][1] = j;
            }
        }
        for (int i = 0; i < steps.size() - 1; i++) {
            int rowX = abs(steps[i + 1][0] - steps[i][0]);
            int colX = abs(steps[i + 1][1] - steps[i][1]);
            if (!((rowX == 1 && colX == 2) || (rowX == 2 && colX == 1))) return false;
        }
        return true;
    }
};

#endif //CPP_SOLUTION_H

//
// Created by Kekwy on 2023/9/14.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king) {
        auto res = vector<vector<int>>();
        bool grid[8][8] = { 0 };
        for (vector<int> queen : queens) {
            grid[queen[0]][queen[1]] = true;
        }
        // 找同行、同列的皇后
        for (int i = king[1] + 1; i < 8; i++) {
            if (grid[king[0]][i]) {
                res.push_back({ king[0], i });
                break;
            }
        }
        for (int i = king[1] - 1; i >= 0; i--) {
            if (grid[king[0]][i]) {
                res.push_back({ king[0], i });
                break;
            }
        }
        for (int i = king[0] + 1; i < 8; i++) {
            if (grid[i][king[1]]) {
                res.push_back({ i, king[1] });
                break;
            }
        }
        for (int i = king[0] - 1; i >= 0; i--) {
            if (grid[i][king[1]]) {
                res.push_back({ i, king[1] });
                break;
            }
        }
        // 找在同一对角线上的皇后
        for (int i = king[0] + 1, j = king[1] + 1; i < 8 && j < 8; i++, j++) {
            if (grid[i][j]) {
                res.push_back({ i, j });
                break;
            }
        }
        for (int i = king[0] - 1, j = king[1] + 1; i >= 0 && j < 8; i--, j++) {
            if (grid[i][j]) {
                res.push_back({ i, j });
                break;
            }
        }
        for (int i = king[0] + 1, j = king[1] - 1; i < 8 && j >= 0; i++, j--) {
            if (grid[i][j]) {
                res.push_back({ i, j });
                break;
            }
        }
        for (int i = king[0] - 1, j = king[1] - 1; i >= 0 && j >= 0; i--, j--) {
            if (grid[i][j]) {
                res.push_back({ i, j });
                break;
            }
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

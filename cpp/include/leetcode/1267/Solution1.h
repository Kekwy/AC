//
// Created by Kekwy on 2023/8/13.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {

public:
    int countServers(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int *rowNum = new int[row]{0};
        int *colNum = new int[col]{0};
        int res = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    bool flag = false;

                    if (rowNum[i] == 0) rowNum[i] = -j - 1;
                    else if (rowNum[i] < 0) {
                        res += 1;
                        flag = true;
                        colNum[-rowNum[i] - 1] = 2;
                    } else flag = true;

                    if (colNum[j] == 0) colNum[j] = 1;
                    else if (colNum[j] == 1) {
                        res += 1;
                        flag = true;
                    } else flag = true;

                    if (flag) {
                        rowNum[i] = 2;
                        colNum[j] = 2;
                        res++;
                    }
                }
            }
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

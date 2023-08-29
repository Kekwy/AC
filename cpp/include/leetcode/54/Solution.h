//
// Created by Kekwy on 2023/8/28.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        auto res = vector<int>();
        auto visited = vector<vector<bool>>();
        for (int i = 0; i < matrix.size(); i++) {
            visited.push_back(vector<bool>());
            for (int j = 0; j < matrix[i].size(); j++) {
                visited[i].push_back(false);
            }
        }
        int i = 0, j = -1;
        while (true) {
            bool flag = true;
            for(; j + 1 < visited[i].size() && !visited[i][j + 1]; j++) {
                res.push_back(matrix[i][j + 1]);
                visited[i][j + 1] = true;
                flag = false;
            }
            for(; i + 1 < visited.size() && !visited[i + 1][j]; i++) {
                res.push_back(matrix[i + 1][j]);
                visited[i + 1][j] = true;
                flag = false;
            }
            for(; j > 0 && !visited[i][j - 1]; j--) {
                res.push_back(matrix[i][j - 1]);
                visited[i][j - 1] = true;
                flag = false;
            }
            for(; i > 0 && !visited[i - 1][j]; i--) {
                res.push_back(matrix[i - 1][j]);
                visited[i - 1][j] = true;
                flag = false;
            }
            if (flag) break;
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

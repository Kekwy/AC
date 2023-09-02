//
// Created by Kekwy on 2023/9/2.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {

    bool findNumberInPartial2DArray(vector<vector<int>>& matrix, int beginRow, int beginCol, int endRow, int endCol, int target) {
        if (beginRow >= endRow || beginCol >= endCol) return false;
        int midR = beginRow + (endRow - beginRow) / 2;
        int midC = beginCol + (endCol - endCol) / 2;
        if (matrix[midR][midC] < target) {
            return findNumberInPartial2DArray(matrix, midR + 1, beginCol, endRow, midC + 1, target) 
                || findNumberInPartial2DArray(matrix, beginRow, midC + 1, midR + 1, endCol, target)
                || findNumberInPartial2DArray(matrix, midR + 1, midC + 1, endRow, endCol, target);
        } else if (matrix[midR][midC] > target) {
            return findNumberInPartial2DArray(matrix, midR, beginCol, endRow, midC, target) 
                || findNumberInPartial2DArray(matrix, beginRow, midC, midR, endCol, target)
                || findNumberInPartial2DArray(matrix, beginRow, beginCol, midR, midC, target);
        } else {
            return true;
        }
    }

public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        return findNumberInPartial2DArray(matrix, 0, 0, matrix.size(), matrix[0].size(), target);
    }
};

#endif //CPP_SOLUTION_H

//
// Created by Kekwy on 2023/9/2.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <string>
#include <vector>

using namespace std;

class Solution {

    bool search(int i, int j, int index,
        vector<vector<char>> &board, string &word, vector<vector<bool>> &traveled) {
        bool res = false;
        if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size()
            && !traveled[i][j] && board[i][j] == word[index]) {
            if (index == word.length() - 1) return true;
            traveled[i][j] = true;
            res = search(i - 1, j, index + 1, board, word, traveled)
                || search(i + 1, j, index + 1, board, word, traveled)
                || search(i, j - 1, index + 1, board, word, traveled)
                || search(i, j + 1, index + 1, board, word, traveled);
            traveled[i][j] = false;
        }
        return res;
    }

public:
    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size();
        int n = board[0].size();
        auto traveled = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (search(i, j, 0, board, word, traveled)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

#endif //CPP_SOLUTION_H

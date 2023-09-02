//
// Created by Kekwy on 2023/9/2.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {

    bool isForbidden(int i, int j, int k) {
        int tmp = 0;
        while (i > 0) {
            tmp += i % 10;
            i /= 10;
        }
        while (j > 0) {
            tmp += j % 10;
            j /= 10;
        }
        return tmp > k;
    }

    void dp(vector<vector<bool>> &traveled, int m, int n, int k, int i, int j) {
        if (i >= 0 && i < m && j >= 0 && j < n && !traveled[i][j] && !isForbidden(i, j, k)) {
            traveled[i][j] = true;
            dp(traveled, m, n, k, i + 1, j);
            dp(traveled, m, n, k, i - 1, j);
            dp(traveled, m, n, k, i, j + 1);
            dp(traveled, m, n, k, i, j - 1);
        }
    }

public:
    int movingCount(int m, int n, int k) {
        auto traveled = vector<vector<bool>>(m, vector<bool>(n, false));
        dp(traveled, m, n, k, 0, 0);
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (traveled[i][j]) res++;
            }
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

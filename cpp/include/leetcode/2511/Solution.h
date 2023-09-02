//
// Created by Kekwy on 2023/9/2.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

using namespace std;

#include <vector>

class Solution {
public:
    int captureForts(vector<int> &forts) {
        int lp = -1;
        bool flag = false;
        int res = 0;
        for (int i = 0; i < forts.size(); i++) {
            if (forts[i] == 1) {
                if (lp != -1 && !flag) {
                    int tmp = i - lp - 1;
                    if (tmp > res) res = tmp;
                }
                flag = true;
                lp = i;
            } else if (forts[i] == -1) {
                if (lp != -1 && flag) {
                    int tmp = i - lp - 1;
                    if (tmp > res) res = tmp;
                }
                flag = false;
                lp = i;
            }
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

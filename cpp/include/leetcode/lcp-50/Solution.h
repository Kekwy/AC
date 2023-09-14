//
// Created by Kekwy on 2023/9/15.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (vector<int> o : operations) {
            int m = gem[o[0]] / 2;
            gem[o[0]] -= m;
            gem[o[1]] += m;
        }
        int maxG = INT_MIN, minG = INT_MAX;
        for (int g : gem) {
            if (g > maxG) maxG = g;
            if (g < minG) minG = g;
        }
        return maxG - minG;
    }
};

#endif //CPP_SOLUTION_H

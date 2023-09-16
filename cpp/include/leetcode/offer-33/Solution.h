//
// Created by Kekwy on 2023/9/16.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {

    int i;

    void recur(int minVal, int maxVal, vector<int>& postorder) {
        if (i < 0 || postorder[i] < minVal || postorder[i] > maxVal) return;
        int val = postorder[i--];
        recur(val, maxVal, postorder);
        recur(minVal, val, postorder);
    }

public:
    bool verifyPostorder(vector<int>& postorder) {
        i = postorder.size() - 1;
        recur(INT_MIN, INT_MAX, postorder);
        return i < 0;
    }
};

#endif //CPP_SOLUTION_H

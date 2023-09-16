//
// Created by Kekwy on 2023/9/16.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

    bool nextPermutation(string &str) {
        int i, j;
        for (i = str.length() - 2; i >= 0 && str[i] >= str[i + 1]; i--);
        if (i >= 0) {
            for (j = str.length() - 1; j > 0 && str[j] <= str[i]; j--);
            swap(str[i], str[j]);
            reverse(str.begin() + i + 1, str.end());
            return true;
        } else {
            return false;
        }
    }

public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<string> res;
        do {
            res.push_back(s);
        } while (nextPermutation(s));
        return res;
    }
};

#endif //CPP_SOLUTION_H

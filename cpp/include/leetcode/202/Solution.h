//
// Created by Kekwy on 2023/9/3.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

using namespace std;

#include <unordered_set>

class Solution {

    unordered_set<int> set;

public:
    bool isHappy(int n) {
        if (set.count(n)) return false;
        if (n == 1) return true;
        set.insert(n);
        int next = 0;
        while (n > 0) {
            next += (int)pow((n % 10), 2);
            n /= 10;
        }
        return isHappy(next);
    }
};

#endif //CPP_SOLUTION_H

//
// Created by Kekwy on 2023/9/16.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1 / x;
        int mid = n / 2;
        double tmp = myPow(x, mid);
        double res = tmp * tmp;
        if (n % 2 == 1) res *= x;
        if (n % 2 == -1) res /= x;
        return res;
    }
};

#endif //CPP_SOLUTION_H

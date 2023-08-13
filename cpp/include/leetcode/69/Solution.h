//
// Created by Kekwy on 2023/8/13.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {

public:
    int mySqrt(int x) {
        int low = 0, high = x;
        int res = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mid > 0 && x / mid < mid) high = mid - 1;
            else if (x / (mid + 1) >= (mid + 1)) low = mid + 1;
            else {
                res = mid;
                break;
            }
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

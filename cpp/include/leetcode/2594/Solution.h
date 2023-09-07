//
// Created by Kekwy on 2023/9/7.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

// 被力扣给的示例说明误导了qwq

class Solution {
public:
    long long repairCars(vector<int> &ranks, int cars) {
        long long begin = 0, end = ranks[0] * (long long)cars * cars;
        while (begin < end) {
            long long mid = begin + (end - begin) / 2;
            long long sum = 0;
            for (int r : ranks) {
                sum += sqrt(mid / r);
            }
            if (sum >= cars) {
                end = mid;
            } else if (sum < cars) {
                begin = mid + 1;
            }
        }
        return end;
    }
};

#endif //CPP_SOLUTION_H

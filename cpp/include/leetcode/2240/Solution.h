//
// Created by Kekwy on 2023/9/1.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

using namespace std;

class Solution {

public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int penCost = 0;
        long long res = 0;
        while (penCost <= total) {
            int remain = total - penCost;
            int pencilCount = remain / cost2;
            res += pencilCount + 1;
            penCost += cost1;
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

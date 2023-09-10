//
// Created by Kekwy on 2023/9/8.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

using namespace std;

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};

#endif //CPP_SOLUTION_H

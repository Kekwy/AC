//
// Created by Kekwy on 2023/9/2.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int begin = 0, end = numbers.size() - 1;
        while (begin < end) {
            int mid = (begin + end) / 2;
            if (mid != end && numbers[mid] == numbers[end]) {
                end--;
                continue;
            } else if (mid != begin && numbers[mid] == numbers[begin]) {
                begin++;
                continue;
            }
            if (numbers[mid] > numbers[end]) {
                begin = mid + 1;
            } else {
                if (numbers[mid] > numbers[begin]) end = mid - 1;
                else end = mid;
            }
        }
        return numbers[begin];
    }
};

#endif //CPP_SOLUTION_H

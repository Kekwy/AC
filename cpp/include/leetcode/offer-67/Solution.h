//
// Created by Kekwy on 2023/8/30.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <string>

using namespace std;

class Solution {

public:
    int strToInt(string str) {
        int res = 0;
        int state = 0;
        for (int i = 0; i < str.length(); i++) {
            switch (state)
            {
            case 0: 
                if (str[i] == ' ') {
                    state = 0;
                } else if (str[i] == '-') {
                    state = 1;
                } else if (str[i] == '+') {
                    state = 2;
                } else if (str[i] >= '0' && str[i] <= '9') {
                    res = str[i] - '0';
                    state = 3;
                } else {
                    return res;
                }
                break;
            case 1: 
                if (str[i] > '0' && str[i] <= '9') {
                    res = -(str[i] - '0');
                    state = 3;
                } else if (str[i] != '0') {
                    return res;
                }
                break;
            case 2:
                if (str[i] > '0' && str[i] <= '9') {  // if (str[i] >= '0' && str[i] <= '9') {
                    res = str[i] - '0';               // "-000000000000001" -> -1
                    state = 3;
                } else if (str[i] != '0') {
                    return res;
                }
                break; //
            case 3:
                if (str[i] >= '0' && str[i] <= '9') {
                    if (res < 0) { // 这里要分正负号
                        if (res < (INT_MIN + (str[i] - '0')) / 10) {
                            return INT_MIN;
                        }
                        res = res * 10 - (str[i] - '0');
                    } else {
                        if (res > (INT_MAX - (str[i] - '0')) / 10) {
                            return INT_MAX;
                        }
                        res = res * 10 + (str[i] - '0');
                    }
                    state = 3;
                } else {
                    return res;
                }
            default:
                break;
            }
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

//
// Created by Kekwy on 2023/8/30.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <string>

using namespace std;

class Solution {

    void reverse(string &s, int lPtr, int rPtr) {
        while (lPtr < rPtr) {
            char tmp = s[lPtr];
            s[lPtr] = s[rPtr];
            s[rPtr] = tmp;
            lPtr++;
            rPtr--;
        }
    }

public:
    string reverseLeftWords(string s, int n) {
        reverse(s, 0, n - 1);
        reverse(s, n, s.length() - 1);
        reverse(s, 0, s.length() - 1);
        return s;
    }
};

#endif //CPP_SOLUTION_H

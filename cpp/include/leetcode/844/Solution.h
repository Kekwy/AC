//
// Created by Kekwy on 2023/8/26.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {

    int removeBackspace(string &s) {
        int slowPtr = 0, quickPtr = 0;
        while(quickPtr < s.size()) {
            if (s[quickPtr] == '#') {
                if(slowPtr > 0) {
                    slowPtr--;
                }
                quickPtr++;
            } else {
                s[slowPtr++] = s[quickPtr++];
            }
        }
        return slowPtr;
    }

public:
    bool backspaceCompare(string s, string t) {
        int len1 = removeBackspace(s);
        int len2 = removeBackspace(t);
        if (len1 != len2) return false;
        return strncmp(s.c_str(), t.c_str(), len1) == 0;
    }
};

#endif //CPP_SOLUTION_H

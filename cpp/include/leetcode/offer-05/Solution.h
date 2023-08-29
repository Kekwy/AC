//
// Created by Kekwy on 2023/8/29.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for(int i = 0; i< s.size();i++) {
            if(s[i] == ' ') res.append("%20");
            else res += s[i];
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

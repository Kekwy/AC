//
// Created by Kekwy on 2023/8/31.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <string>

using namespace std;

class Solution {

    void reverse(string &s, int begin, int end) {
        int lp = begin, rp = end - 1;
        while (lp < rp) {
            int tmp = s[lp];
            s[lp++] = s[rp];
            s[rp--] = tmp;
        }
    }

public:
    string reverseWords(string s) {
        if (s.empty()) return ""; // 
        int lp = -1;
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ' && lp == -1) {
                lp = i;
            } else if (s[i] == ' ' && lp != -1) {
                reverse(s, lp, i);
                res.append(s.substr(lp, i - lp));
                res.append(" ");
                lp = -1;
            }
        }
        if (lp != -1) {
            reverse(s, lp, s.length());
            res.append(s.substr(lp, s.length() - lp));
        } else if (!res.empty() && res.back() == ' ') { //
            res.pop_back();
        }
        reverse(res, 0, res.length());
        return res;
    }
};

#endif //CPP_SOLUTION_H

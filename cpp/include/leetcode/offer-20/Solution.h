//
// Created by Kekwy on 2023/8/30.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <string>

using namespace std;

class Solution {

    enum State {
        STATE_HEADSPACE,
        STATE_TAILSPACE,
        STATE_NUM,
        STATE_DOT,
        STATE_OPT,
        STATE_E
    };

public:
    bool isNumber(string s) {
        bool dot = true, e = true, num = false;
        State state = STATE_HEADSPACE;
        for (int i = 0; i < s.length(); i++) {
            switch (state)
            {
            case STATE_HEADSPACE: {
                if (s[i] == ' ') {
                    state = STATE_HEADSPACE;
                } else if (s[i] == '-' || s[i] == '+') {
                    state = STATE_OPT;
                } else if (s[i] == '.') {
                    state = STATE_DOT;
                } else if (s[i] >= '0' && s[i] <= '9') {
                    state = STATE_NUM;
                } else {
                    return false;
                }
                break;
            }
            case STATE_TAILSPACE: {
                if (s[i] != ' ') {
                    return false;
                }
                break;
            }
            case STATE_NUM: {
                num = true;
                if (s[i] == ' ') {
                    state = STATE_TAILSPACE;
                } else if (dot && s[i] == '.') {
                    state = STATE_DOT;
                } else if (s[i] >= '0' && s[i] <= '9') {
                    state = STATE_NUM;
                } else if (e && (s[i] == 'e' || s[i] == 'E')) {
                    state = STATE_E;
                } else {
                    return false;
                }
                break;
            }
            case STATE_DOT: {
                dot = false;
                if (num && s[i] == ' ') {
                    state = STATE_TAILSPACE;
                } else if (num && (s[i] == 'e' || s[i] == 'E')) {
                    state = STATE_E;
                } else if (s[i] >= '0' && s[i] <= '9') {
                    state = STATE_NUM;
                } else {
                    return false;
                }
                break;
            }
            case STATE_OPT: {
                if (dot && s[i] == '.') {
                    state = STATE_DOT;
                } else if (s[i] >= '0' && s[i] <= '9') {
                    state = STATE_NUM;
                } else {
                    return false;
                }
                break;
            }
            case STATE_E: {
                e = false;
                dot = false;
                if (s[i] == '-' || s[i] == '+') {
                    state = STATE_OPT;
                } else if (s[i] >= '0' && s[i] <= '9') {
                    state = STATE_NUM;
                } else {
                    return false;
                }
                break;
            }
            }
            
        }
        if (state == STATE_NUM || state == STATE_TAILSPACE || (state == STATE_DOT && num)) {
            return true;
        }
        return false;
    }
};

#endif //CPP_SOLUTION_H

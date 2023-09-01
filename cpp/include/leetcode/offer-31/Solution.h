//
// Created by Kekwy on 2023/9/1.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pushedPtr = 0;
        int poppedPtr = 0;
        auto s = stack<int>();
        // pushed 数组不一定是递增顺序
        // while (pushedPtr < pushed.size()) {
        //     if (popped[poppedPtr] > pushed[pushedPtr]) {
        //         s.push(pushed[pushedPtr]);
        //         pushedPtr++;
        //     } else if (popped[poppedPtr] < pushed[pushedPtr]) {
        //         return false;
        //     } else {
        //         pushedPtr++;
        //         poppedPtr++;
        //     }
        // }
        while (pushedPtr < pushed.size()) {
            if (popped[poppedPtr] != pushed[pushedPtr]) {
                if (!s.empty() && s.top() == popped[poppedPtr]) {
                    s.pop();
                    poppedPtr++;
                } else {
                    s.push(pushed[pushedPtr]);
                    pushedPtr++;
                }
            } else {
                pushedPtr++;
                poppedPtr++;
            }
        }

        while (poppedPtr < popped.size()) {
            int top = s.top();
            s.pop();
            if (top != popped[poppedPtr]) return false;
            poppedPtr++;
        }
        if (!s.empty()) return false;
        return true;
    }
};

#endif //CPP_SOLUTION_H

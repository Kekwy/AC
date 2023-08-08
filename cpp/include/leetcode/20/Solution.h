//
// Created by Kekwy on 2023/8/8.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (const auto &item: s) {
            switch (item) {
                case '(':
                case '[':
                case '{': {
                    stack.push(item);
                    break;
                }
                case ')': {
                    if (stack.empty() || stack.top() != '(') return false;
                    stack.pop();
                    break;
                }
                case ']': {
                    if (stack.empty() || stack.top() != '[') return false;
                    stack.pop();
                    break;
                }
                case '}': {
                    if (stack.empty() || stack.top() != '{') return false;
                    stack.pop();
                    break;
                }
                default:
                    return false;
            }
        }
        if (stack.empty()) return true;
        return false;
    }
};

#endif //CPP_SOLUTION_H

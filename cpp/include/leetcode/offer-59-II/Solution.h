//
// Created by Kekwy on 2023/9/1.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <stack>

using namespace std;

class MinStack {

    stack<int> dataStack;

    stack<int> minStack;

    int minNum;

public:
    /** initialize your data structure here. */
    MinStack() : minNum(0) {

    }

    void push(int x) {
        if (dataStack.empty() || x <= minNum) {
            minStack.push(minNum);
            minNum = x;
        }
        dataStack.push(x);
    }

    void pop() {
        int p = dataStack.top();
        dataStack.pop();
        if (p == minNum) {
            minNum = minStack.top();
            minStack.pop();
        }
    }

    int top() {
        return dataStack.top();
    }

    int min() {
        return minNum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

#endif //CPP_SOLUTION_H

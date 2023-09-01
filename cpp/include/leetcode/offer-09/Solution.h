//
// Created by Kekwy on 2023/8/31.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <stack>

using namespace std;

class CQueue {

    stack<int> input;

    stack<int> output;

    void update() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }

public:

    CQueue() {

    }

    void appendTail(int value) {
        input.push(value);
    }

    int deleteHead() {
        update();
        if (output.empty()) return -1;
        int front = output.top();
        output.pop();
        return front;
    }

};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

#endif //CPP_SOLUTION_H

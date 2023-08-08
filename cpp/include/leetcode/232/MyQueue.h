//
// Created by Kekwy on 2023/8/8.
//

#ifndef CPP_MYQUEUE_H
#define CPP_MYQUEUE_H

#include <stack>

using namespace std;

class MyQueue {

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
    MyQueue() {

    }

    void push(int x) {
        input.push(x);
    }

    int pop() {
        update();
        int front = output.top();
        output.pop();
        return front;
    }

    int peek() {
        update();
        return output.top();
    }

    bool empty() {
        return output.empty() && input.empty();
    }
};

#endif //CPP_MYQUEUE_H

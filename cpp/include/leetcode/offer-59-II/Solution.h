//
// Created by Kekwy on 2023/9/1.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <queue>

using namespace std;

class MaxQueue {

    queue<int> data;

    deque<int> moque;

public:
    MaxQueue() {

    }
    
    int max_value() {
        if (data.empty()) return -1;
        return moque.front();
    }
    
    void push_back(int value) {
        data.push(value);
        // if (!moque.empty() && moque.back() < value) { // while 写成 if 了还半天看不出来
        while (!moque.empty() && moque.back() < value) {
            moque.pop_back();
        }
        moque.push_back(value);
    }
    
    int pop_front() {
        if (data.empty()) return -1;
        int front = data.front();
        data.pop();
        if (front == moque.front()) {
            moque.pop_front();
        }
        return front;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

#endif //CPP_SOLUTION_H

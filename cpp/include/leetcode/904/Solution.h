//
// Created by Kekwy on 2023/8/26.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class HashTable {

    struct Node {
        int val;
        int count;
        Node *next;
        Node(int val, Node *next): val(val), count(0), next(next) {}
    };

    Node* data[7];

    int num;

public:

    HashTable(): num(0) {
        for (int i = 0; i < 7; i++) {
            data[i] = nullptr;
        }
    }

    void insert(int val) {
        int loc = val % 7;
        Node *ptr = data[loc];
        while(ptr != nullptr) {

        }
        auto node = new Node(val, data[loc]);
    }

};

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // int 
    }
};

#endif //CPP_SOLUTION_H

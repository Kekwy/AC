//
// Created by Kekwy on 2023/8/26.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

#define HASH_TABLE_SIZE 499

#define HASH_TABLE_SIZE 499

class HashTable {

    struct Node {
        int val;
        int lastLoc; // 遍历过程对应数最后一次出现的位置
        Node *next;
        Node(int val, int lastLoc, Node *next): val(val), lastLoc(lastLoc), next(next) {}
    };

    Node* data[HASH_TABLE_SIZE];

    int num;

public:

    HashTable(): num(0) {
        for (int i = 0; i < HASH_TABLE_SIZE; i++) {
            data[i] = nullptr;
        }
    }

    ~HashTable() {
        for (int i = 0; i < HASH_TABLE_SIZE; i++) {
            Node *ptr = data[i];
            while(ptr != nullptr) {
                Node *temp = ptr->next;
                delete ptr;
                ptr = temp;
            }
            data[i] = nullptr;
        }
        num = 0;
    }

    void insert(int val, int j) {
        int loc = val % HASH_TABLE_SIZE;
        Node *ptr = data[loc];
        while(ptr != nullptr) {
            if (ptr->val == val) {
                ptr->lastLoc = j;
                return;
            }
            ptr = ptr->next;
        }
        auto node = new Node(val, j, data[loc]);
        data[loc] = node;
        num++;
    }

    bool remove(int val) {
        int loc = val % HASH_TABLE_SIZE;
        Node *ptr = data[loc];
        Node *prePtr = nullptr;
        while(ptr != nullptr) {
            if (ptr->val == val) {
                if (prePtr == nullptr) {
                    data[loc] = ptr->next;
                } else {
                    prePtr->next = ptr->next;
                }
                delete ptr;
                num--;
                return true;
            }
            prePtr = ptr;
            ptr = ptr->next;
        }
        return false;
    }

    int getLastLoc(int val) {
        int loc = val % HASH_TABLE_SIZE;
        Node *ptr = data[loc];
        while(ptr != nullptr) {
            if (ptr->val == val) {
                return ptr->lastLoc;
            }
            ptr = ptr->next;
        }
        return -1;
    }

    int size() {
        return num;
    }

};

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ptr = 0, curNum = fruits[0];    //
        auto hashTable = HashTable();
        int res = 0, sum = 0;
        for (int i = 0; i < fruits.size(); i++) {
            // if (fruits[i] != curNum) {      //
            //     ptr = i - 1;                //
            // }                               //
            hashTable.insert(fruits[i], i);
            if (hashTable.size() > 2) {
                if (sum > res) res = sum;
                int lastLoc = hashTable.getLastLoc(fruits[ptr]);
                hashTable.remove(fruits[ptr]);
                sum = i - lastLoc;
            } else {
                sum++;
            }
            if (fruits[i] != curNum) {      //
                ptr = i - 1;                //
                curNum = fruits[i]; //
            }                               //
        }
        if (sum > res) res = sum;
        return res;
    }
};

#endif //CPP_SOLUTION_H

//
// Created by Kekwy on 2023/8/31.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <string>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

#define HASH_TABLE_SIZE 997

class HashMap {

    struct HashNode {
        Node *key;
        Node *val;
        HashNode *next;
        HashNode(Node *key, Node *val, HashNode *next) : key(key), val(val), next(next) {}
    };

    HashNode *data[HASH_TABLE_SIZE];

    int num;

public:

    HashMap() : num(0) {
        for (int i = 0; i < HASH_TABLE_SIZE; i++) {
            data[i] = nullptr;
        }
    }

    ~HashMap() {
        for (int i = 0; i < HASH_TABLE_SIZE; i++) {
            HashNode *ptr = data[i];
            while (ptr != nullptr) {
                HashNode *temp = ptr->next;
                delete ptr;
                ptr = temp;
            }
            data[i] = nullptr;
        }
        num = 0;
    }

    void put(Node *key, Node *val) {
        int loc = ((long)key) % HASH_TABLE_SIZE;
        HashNode *ptr = data[loc];
        while (ptr != nullptr) {
            if (ptr->val == val) {
                ptr->val = val;
                return;
            }
            ptr = ptr->next;
        }
        auto node = new HashNode(key, val, data[loc]);
        data[loc] = node;
        num++;
    }

    Node *get(Node *key) {
        int loc = ((long)key) % HASH_TABLE_SIZE;
        HashNode *ptr = data[loc];
        while (ptr != nullptr) {
            if (ptr->key == key) {
                return ptr->val;
            }
            ptr = ptr->next;
        }
        return nullptr;
    }

    int size() {
        return num;
    }

};

class Solution {

public:

    Node *copyRandomList(Node *head) {
        Node *dummyHead = new Node(0);
        dummyHead->next = nullptr;

        auto map = HashMap();

        for (Node *p = head, *q = dummyHead; p != nullptr; q = q->next, p = p->next) {
            Node *newP = map.get(p);
            if (newP == nullptr) {
                newP = new Node(p->val);
                map.put(p, newP);
            }
            if (p->random != nullptr) {
                Node *random = map.get(p->random);
                if (random == nullptr) {
                    random = new Node(p->random->val);
                    map.put(p->random, random);
                }
                newP->random = random;
            }
            q->next = newP;
        }

        return dummyHead->next;
    }
};

#endif //CPP_SOLUTION_H
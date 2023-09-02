//
// Created by Kekwy on 2023/9/2.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <queue>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {

    Node *head = nullptr;

    Node *prev;


    void visit(Node *node) {
        if (head == nullptr) {
            head = node;
        } else {
            prev->right = node;
            node->left = prev;
        }
        prev = node;
    }

    void travel(Node *node) {
        if (node == nullptr) return;
        travel(node->left);
        visit(node);
        travel(node->right);
    }

public:
    Node *treeToDoublyList(Node *root) {
        travel(root);
        if (head != nullptr) {
            head->left = prev;
            prev->right = head;
        }
        return head;
    }
};

#endif //CPP_SOLUTION_H

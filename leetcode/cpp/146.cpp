/*
 * @lc app=leetcode.cn id=146 lang=cpp
 * @lcpr version=21917
 *
 * [146] LRU 缓存
 */
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start
class LRUCache {

    struct Node {
        int key;
        int val;
        Node *prev;
        Node *next;
        Node() :prev(nullptr), next(nullptr), val(-1), key(-1) {}
        Node(int key, int val) :prev(nullptr), next(nullptr), val(val), key(key) {}
    };

    unordered_map<int, Node *> keyNodeMap;

    Node *head;
    Node *tail;

    int capacity;
    int size;

    // 将指定节点移至表尾
    void updateNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = tail;
        node->prev = tail->prev;

        tail->prev->next = node;
        tail->prev = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (keyNodeMap.find(key) != keyNodeMap.end()) {
            Node *node = keyNodeMap[key];
            updateNode(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (keyNodeMap.find(key) != keyNodeMap.end()) {
            Node *node = keyNodeMap[key];
            node->val = value;
            updateNode(node);
        } else {
            if (size < capacity) {
                Node *node = new Node(key, value);

                node->next = tail;
                node->prev = tail->prev;

                tail->prev->next = node;
                tail->prev = node;

                keyNodeMap[key] = node;

                size++;
            } else {
                Node *node = head->next;

                keyNodeMap.erase(node->key);

                node->key = key;
                node->val = value;

                updateNode(node);

                keyNodeMap[key] = node;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 // @lc code=end

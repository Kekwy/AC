//
// Created by Kekwy on 2023/8/29.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

#define HASH_TABLE_SIZE 997

/**
 * 基于拉链法进行冲突处理的哈希表
 */
class HashTable {

    struct Node {
        int val;
        int count; // 以 val 为根的二叉树的个数
        Node *next;
        Node(int val, int count, Node *next): val(val), count(count), next(next) {}
    };

    Node* data[HASH_TABLE_SIZE];

public:

    HashTable() {
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
    }

    void setCount(int val, int count) {
        int loc = val % HASH_TABLE_SIZE;
        Node *ptr = data[loc];
        auto node = new Node(val, count, data[loc]);
        data[loc] = node;
    }

    int getCount(int val) {
        int loc = val % HASH_TABLE_SIZE;
        Node *ptr = data[loc];
        while(ptr != nullptr) {
            if (ptr->val == val) {
                return ptr->count;
            }
            ptr = ptr->next;
        }
        return -1;
    }

};

class Solution {

    void quickSort(vector<int>& arr, int begin, int end) {
        if (begin >= end) return;
        int pivot = arr[begin];
        int lPtr = begin, rPtr = end - 1;
        bool flag = true;
        while(lPtr < rPtr) {
            if (flag) {
                if (arr[rPtr] <= pivot) {
                    arr[lPtr] = arr[rPtr];
                    lPtr++;
                    flag = false;
                } else {
                    rPtr--;
                }
            } else {
                if (arr[lPtr] > pivot) {
                    arr[rPtr] = arr[lPtr];
                    rPtr--;
                    flag = true;
                } else {
                    lPtr++;
                }
            }
        }
        arr[lPtr] = pivot;
        quickSort(arr, begin, lPtr);
        quickSort(arr, lPtr + 1, end);
    }

public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        quickSort(arr, 0, arr.size());         // 从小到大排序，便于动态规划
        auto hashTable = HashTable();          // 哈希表，用于存储以数组中每个数为根时的二叉树个数
        // vector<long long> dp(n); // 优化：由于 arr 中数字各不相同故可用每个数在 arr 中的下标作为标识，建立大小为 n 的连续、无冲突哈希表
        int res = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++) {
            int lPtr = 0, rPtr = i - 1;
            // 寻找所有相乘等于 arr[i] 的组合
            // 由于数组已经递增排序，故只需通过双指针法在数组的前半部分查找即可
            int count = 1; // 没有子树，作为叶子结点
            while (lPtr <= rPtr) {
                long long mul = (long long)arr[lPtr] * arr[rPtr];
                if (mul < arr[i]) {
                    lPtr++;
                } else if (mul > arr[i]) {
                    rPtr--;
                } else {
                    // - 应用动态规划：
                    //   由于数组递增排序，故分别以 arr[lPtr]、arr[rPtr] 为根
                    //   的二叉树的个数已经求得，并保存在哈希表中；
                    // - 将二者相乘即为分别以 arr[lPtr]、arr[rPtr] 作为左右子树根节点时的二叉树个数；
                    // - 将所有可能作为子树的根节点的值找到，重复上述操作，最终将二叉树个数相加，即为以 arr[i] 为根节点时的二叉树总个数。
                    long long count1 = hashTable.getCount(arr[lPtr]);
                    long long count2 = hashTable.getCount(arr[rPtr]);
                    long long tmpCount = (count1 * count2) % mod;
                    if (lPtr != rPtr) {
                        tmpCount = (tmpCount * 2) % mod;
                    }
                    count = (count + tmpCount) % mod;
                    lPtr++;
                    rPtr--;
                }
            }
            res = (res + count) % mod;
            hashTable.setCount(arr[i], count);
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

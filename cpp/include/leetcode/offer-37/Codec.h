//
// Created by Kekwy on 2023/9/3.
//

#ifndef CPP_CODEC_H
#define CPP_CODEC_H

using namespace std;

#include <string>
#include <queue>
#include <vector>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {

    void split(const string &str, vector<string> &res, char c, int begin, int end) {
        string tmp = "";
        for (int i = begin; i < end; i++) {
            if (str[i] == c) {
                res.push_back(tmp);
                tmp.clear();
            }
            else {
                tmp += str[i];
            }
        }
        if (!tmp.empty()) {
            res.push_back(tmp);
        }
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string res = "[";
        auto bfsQueue = queue<TreeNode *>();
        if (root != nullptr) bfsQueue.push(root);
        while (!bfsQueue.empty()) {
            TreeNode *node = bfsQueue.front();
            bfsQueue.pop();
            if (node == nullptr) {
                res += "null,";
                continue;
            }
            res = res + to_string(node->val) + ",";
            bfsQueue.push(node->left);
            bfsQueue.push(node->right);
        }
        if (res.back() == ',') res.pop_back();
        res += "]";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        auto vals = vector<string>();
        split(data, vals, ',', 1, data.length() - 1);
        TreeNode *root = nullptr;
        auto bfsQueue = queue<TreeNode **>();
        if (!vals.empty()) {
            root = new TreeNode(atoi(vals[0].c_str()));
            bfsQueue.push(&root->left);
            bfsQueue.push(&root->right);
        }
        int i = 1;
        while (!bfsQueue.empty()) {
            TreeNode **ptr = bfsQueue.front();
            bfsQueue.pop();
            if (vals[i] != "null") {
                *ptr = new TreeNode(atoi(vals[i].c_str()));
                bfsQueue.push(&(*ptr)->left);
                bfsQueue.push(&(*ptr)->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

#endif //CPP_CODEC_H

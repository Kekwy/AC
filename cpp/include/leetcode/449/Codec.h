//
// Created by Kekwy on 2023/9/4.
//

#ifndef CPP_CODEC_H
#define CPP_CODEC_H

#include <string>
#include <vector>

using namespace std;

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

    void split(const string &str, vector<int> &res, char c, int begin, int end) {
        string tmp = "";
        for (int i = begin; i < end; i++) {
            if (str[i] == c) {
                res.push_back(atoi(tmp.c_str()));
                tmp.clear();
            }
            else {
                tmp += str[i];
            }
        }
        if (!tmp.empty()) {
            res.push_back(atoi(tmp.c_str()));
        }
    }

    void recurSerialize(TreeNode *node, string &res) {
        if (node == nullptr) return;
        res = res + to_string(node->val) + ',';
        recurSerialize(node->left, res);
        recurSerialize(node->right, res);
    }

    void recurDeserialize(TreeNode *&node, int minVal, int maxVal, vector<int> &vals, int &index) {
        if (index >= vals.size()) return;
        node = new TreeNode(vals[index]);
        index++;
        if (index < vals.size() && vals[index] > minVal && vals[index] < node->val) {
            recurDeserialize(node->left, minVal, node->val, vals, index);
        }
        if (index < vals.size() && vals[index] > node->val && vals[index] < maxVal) {
            recurDeserialize(node->right, node->val, maxVal, vals, index);
        }
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {  // 先序遍历序列化
        string res = "[";
        recurSerialize(root, res);
        if (res.back() == ',') res.pop_back();
        res += "]";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        vector<int> vals;
        split(data, vals, ',', 1, data.length() - 1);
        TreeNode *root = nullptr;
        int index = 0;
        recurDeserialize(root, INT_MIN, INT_MAX, vals, index);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

#endif //CPP_CODEC_H

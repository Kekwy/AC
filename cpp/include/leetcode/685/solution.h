//
// Created by Kekwy on 2023/8/25.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class UFSets {

    int* data;

public:

    explicit UFSets(int size) {
        data = new int[size];
        for(int i = 0; i < size; i++) {
            data[i] = -1;
        }
    }

    void unionRoots(int a, int b) {
        int root1 = findRoot(a);
        int root2 = findRoot(b);
        data[root1] += data[root2];
        data[root2] = root1;
    }

    int findRoot(int target) {
        int root = target;
        while(data[root] >= 0) root = data[root];
        int i = target, j;
        // 压缩路径
        while(data[i] >= 0) {
            j = i;
            i = data[i];
            data[j] = root;
        }
        return root;
    }

};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> res;
        int size = (int) edges.size();
        auto ufSets = UFSets(size + 1);
        for (const auto &item: edges) {
            int a = item[0];
            int b = item[1];
            int root1 = ufSets.findRoot(a);
            int root2 = ufSets.findRoot(b);
            if (root1 != root2 && root2 == b) ufSets.unionRoots(a, b);
            else res = item;
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

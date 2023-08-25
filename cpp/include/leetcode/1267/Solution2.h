//
// Created by Kekwy on 2023/8/24.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

/**
 * 并查集
 */
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
        if (root1 != root2) {
            // 小树并入大树
            if (-data[root1] <= -data[root2]) {
                data[root2] += data[root1];
                data[root1] = root2;
            } else {
                data[root1] += data[root2];
                data[root2] = root1;
            }
        }
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
    int countServers(vector<vector<int>>& grid) {

    }
};

#endif //CPP_SOLUTION_H

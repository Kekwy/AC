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

    int *data;
    int size;

public:

    explicit UFSets(int size) : size(size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = -1;
        }
    }

    ~UFSets() {
        delete[]data;
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
        while (data[root] >= 0) root = data[root];
        int i = target, j;
        // 压缩路径
        while (data[i] >= 0) {
            j = i;
            i = data[i];
            data[j] = root;
        }
        return root;
    }

    int setsSize(int min) {
        int res = 0;
        for (int i = 0; i < size; i++) {
            if (data[i] <= -min) {
                res += data[i];
            }
        }
        return -res;
    }

};


class Solution {

public:
    int countServers(vector<vector<int>> &grid) {
        int num = 0;
        int row = (int) grid.size();
        int col = (int) grid[0].size();
        int *rowNode = new int[row];
        int *colNode = new int[col];
        auto nodes = vector<vector<int>>();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    rowNode[i] = num;
                    colNode[j] = num;
                    nodes.push_back({i, j});
                    num++;
                }
            }
        }
        auto ufSets = UFSets(num);
        for (int i = 0; i < nodes.size(); i++) {
            ufSets.unionRoots(i, rowNode[nodes[i][0]]);
            ufSets.unionRoots(i, colNode[nodes[i][1]]);
        }
        return ufSets.setsSize(2);
    }
};

#endif //CPP_SOLUTION_H

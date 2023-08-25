//
// Created by Kekwy on 2023/8/25.
//

#ifndef CPP_UFSETS_H
#define CPP_UFSETS_H

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

#endif //CPP_UFSETS_H

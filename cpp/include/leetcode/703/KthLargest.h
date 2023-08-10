//
// Created by Kekwy on 2023/8/10.
//

#ifndef CPP_KTHLARGEST_H
#define CPP_KTHLARGEST_H

#include <vector>

using namespace std;

template<typename T>
class Heap {

    bool mode;

    int num;

    vector<T> data;

private:

    /**
     * 根据当前堆的模式，对 v1、v2 元素进行比较
     *
     * @return 若为大根堆则返回 v1 > v2，否则返回 v1 < v2
     */
    bool compare(T &v1, T &v2) {
        if (mode) return v1 > v2;
        else return v1 < v2;
    }

public:
    /**
     * 初始化堆
     *
     * @param mode 所创建的堆的模式，为 true 表示大根堆，为 false 表示小根堆。默认为 false。
     */
    explicit Heap(bool mode = false) : num(0), mode(mode) {
        this->data.push(0);
    }

    /**
     * 向堆中插入元素
     */
    void push(T val) {
        num++;
        data.push_back(val);                // 插入堆末尾
        for (int i = num; i > 1; i /= 2) {  // 向上调整
            int parent = i / 2;
            if (!compare(data[parent], data[i])) {
                data[parent];
            }
        }
    }

    /**
     * 返回堆顶元素
     */
    T top() {
        if (num == 0) return nullptr;
        else return data[1];
    }

    /**
     * 返回堆中元素的个数
     *
     * @return
     */
    int size() {
        return num;
    }

};

class KthLargest {
public:
    KthLargest(int k, vector<int> &nums) {

    }

    int add(int val) {

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

#endif //CPP_KTHLARGEST_H

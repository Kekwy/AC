//
// Created by Kekwy on 2023/8/10.
//

#ifndef CPP_HEAP_H
#define CPP_HEAP_H

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

    /**
     * 将第 k 个元素向上调整
     */
    void upAdjust(int k) {
        for (int i = k; i > 1; i /= 2) {  // 向上调整
            int parent = i / 2;
            if (!compare(data[parent], data[i])) {
                swap(data[parent], data[i]);
            } else {
                break;
            }
        }
    }

    /**
     * 将第 k 个元素向下调整
     */
    void downAdjust(int k) {
        for (int i = k * 2; i <= num; i *= 2) {
            if (i < num && compare(data[i + 1], data[i])) i++;
            if (!compare(data[k], data[i])) {
                swap(data[k], data[i]);
                k = i;
            } else {
                break;
            }
        }
    }

    void swap(T &v1, T &v2) {
        T temp = v1;
        v1 = v2;
        v2 = temp;
    }

public:
    /**
     * 初始化堆
     *
     * @param mode 所创建的堆的模式，为 true 表示大根堆，为 false 表示小根堆。默认为 false。
     */
    explicit Heap(bool mode = false) : num(0), mode(mode) {
        this->data.push_back(0);
    }

    /**
     * 向堆中插入元素
     */
    void push(T val) {
        num++;
        data.push_back(val);  // 插入堆末尾
        upAdjust(num);        // 调整
    }

    /**
     * 删除对顶元素
     */
    void pop() {
        if (num < 1) return;
        else if (num == 1) {
            num = 0;
            data.pop_back();
        } else {
            data[1] = data[num]; // 将堆底的元素置于堆顶
            num--;
            data.pop_back();
            downAdjust(1);       // 调整
        }
    }

    /**
     * 返回堆顶元素
     */
    T top() {
        if (num == 0) return 0;
        else return data[1];
    }

    /**
     * 返回堆中元素的个数
     */
    int size() {
        return num;
    }

};

#endif //CPP_HEAP_H

/*
 * @lc app=leetcode.cn id=剑指 Offer 41 lang=cpp
 * @lcpr version=21913
 *
 * [剑指 Offer 41] 数据流中的中位数
 */

 // @lc code=start

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
        return (v1 < v2) ^ mode;
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
    explicit Heap(bool mode) : num(0), mode(mode) {
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

class MedianFinder {

    Heap<int> minHeap;
    Heap<int> maxHeap;

    int size;

public:
    /** initialize your data structure here. */
    MedianFinder() : minHeap(false), maxHeap(true) {
        size = 0;
    }

    void addNum(int num) {
        if (num >= minHeap.top()) {
            minHeap.push(num);
        } else {
            maxHeap.push(num);
        }
        if (minHeap.size() > maxHeap.size() + 1) {
            int tmp = minHeap.top();
            minHeap.pop();
            maxHeap.push(tmp);
        } else if (maxHeap.size() > minHeap.size()) {
            int tmp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(tmp);
        }
        size++;
    }

    double findMedian() {
        if (size % 2 == 1) {
            return minHeap.top();
        } else {
            return  ((double)minHeap.top() + (double)maxHeap.top()) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
 // @lc code=end



 /*
 // @lcpr case=start
 // ["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"][[],[1],[2],[],[3],[]]\n
 // @lcpr case=end

 // @lcpr case=start
 // ["MedianFinder","addNum","findMedian","addNum","findMedian"][[],[2],[],[3],[]]\n
 // @lcpr case=end

  */


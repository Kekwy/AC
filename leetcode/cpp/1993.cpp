/*
 * @lc app=leetcode.cn id=1993 lang=cpp
 * @lcpr version=21917
 *
 * [1993] 树上的操作
 */
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start
class LockingTree {

    vector<int> parent;

    vector<vector<int>> children;

    vector<int> lockState;

public:
    LockingTree(vector<int> &parent) :parent(parent) {
        lockState.resize(parent.size(), 0);
        children.resize(parent.size());
        for (int i = 1; i < parent.size(); i++) {
            children[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user) {
        if (lockState[num] == 0) {
            lockState[num] = user;
            return true;
        }
        return false;
    }

    bool unlock(int num, int user) {
        if (lockState[num] == user) {
            lockState[num] = 0;
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user) {
        // 遍历父结点
        int curN = num;
        while (curN != -1) {
            if (lockState[curN] != 0) return false;
            curN = parent[curN];
        }
        // 遍历子节点
        bool flag = false;
        stack<int> travelStack;
        for (int child : children[num]) {
            travelStack.push(child);
        }
        while (!travelStack.empty()) {
            int node = travelStack.top();
            travelStack.pop();
            if (lockState[node] != 0) {
                flag = true;
                lockState[node] = 0;
            }
            for (int child : children[node]) {
                travelStack.push(child);
            }
        }
        if (flag) lockState[num] = user;
        return flag;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
 // @lc code=end



 /*
 // @lcpr case=start
 // ["LockingTree", "lock", "unlock", "unlock", "lock", "upgrade", "lock"][[[-1, 0, 0, 1, 1, 2, 2]], [2, 2], [2, 3], [2, 2], [4, 5], [0, 1], [0, 1]]\n
 // @lcpr case=end

  */


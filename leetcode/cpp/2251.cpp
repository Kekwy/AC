/*
 * @lc app=leetcode.cn id=2251 lang=cpp
 * @lcpr version=21917
 *
 * [2251] 花期内花的数目
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

class Solution1 {

    struct Interval {
        int begin;
        int end;
        int num;
    };

    void buildIntervals(vector<vector<int>> &flowers, list<Interval> &intervalsList) {
        intervalsList.push_back({ flowers[0][0], flowers[0][1], 1 });
        auto it = intervalsList.begin();
        for (int i = 1; i < flowers.size(); i++) {
            int begin = flowers[i][0];
            int end = flowers[i][1];
            // 对已有区间进行重新划分
            while (it != intervalsList.end()) {
                if (begin > (*it).end) {
                    it++;
                    continue;
                }
                if (begin > (*it).begin) {
                    auto itOld = it;
                    it++;
                    int endOld = (*itOld).end;
                    (*itOld).end = begin - 1;
                    it = intervalsList.insert(it, { begin, endOld, (*itOld).num });
                } else {
                    break;
                }
            }
            auto tmpIt = it;
            while (tmpIt != intervalsList.end()) {
                if (end < (*tmpIt).end) {
                    int oldEnd = (*tmpIt).end;
                    int oldNum = (*tmpIt).num;
                    (*tmpIt).end = end; // 1
                    (*tmpIt).num++; // 1
                    auto nextIt = tmpIt; // 2
                    nextIt++; // 2
                    intervalsList.insert(nextIt, { end + 1, oldEnd, oldNum });
                    break;
                } else if (end > (*tmpIt).end) {
                    begin = (*tmpIt).end + 1;
                    (*tmpIt).num++;
                    tmpIt++;
                } else {
                    (*tmpIt).num++;
                    break;
                }
            }
            if (tmpIt == intervalsList.end()) { // 与所有区间合并之后仍有剩余
                intervalsList.push_back({ begin, end, 1 });
                if (it == intervalsList.end()) it--; // 3
            }
        }
    }

    int search(vector<Interval> &intervalsArray, int target) {
        int begin = 0, end = intervalsArray.size();
        while (begin < end) {
            int mid = (end - begin) / 2 + begin;
            if (intervalsArray[mid].begin > target) end = mid;
            else if (intervalsArray[mid].begin < target) {
                if (intervalsArray[mid].end < target) begin = mid + 1;
                else return intervalsArray[mid].num;
            } else return intervalsArray[mid].num;
        }
        return 0;
    }

public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people) {
        sort(flowers.begin(), flowers.end(), [](vector<int> &a, vector<int> &b) { return a[0] < b[0];});
        list<Interval> intervalsList;
        buildIntervals(flowers, intervalsList);
        // 将划分好的区间列表转化为有序排列的区间数组，便于应用二分查找
        vector<Interval> intervalsArray;
        for (const Interval &interval : intervalsList) intervalsArray.push_back(interval);
        vector<int> res;
        for (int p : people) {
            res.push_back(search(intervalsArray, p)); // 通过二分查找找到每个数所在的区间
        }
        return res;
    }
};

// @lc code=start
class Solution {

    int searchLessNumer(int target, vector<int> &array) {
        int begin = 0, end = array.size();
        while (begin < end) {
            int mid = (end - begin) / 2 + begin;
            if (array[mid] > target) end = mid;
            else if (array[mid] <= target) begin = mid + 1;    
            // else return mid + 1; // 有重复元素，故不能找到就返回，应找到最右侧的元素
        }
        return begin;
    }

public:
    // 二分查找的做法，找到某个时间点之前的正增量以及负增量
    // 将开花时间点以及凋谢时间点看作元素，即需要找到当前时间点之前开花的时间点个数以及凋谢的时间点个数
    // 将开花时间、凋谢时间存储在两个数组中并排序，
    // 则即找开花时间数组中小于当前时间点的数的个数，以及凋谢时间数组中小于当前时间点的数的个数。
    // ps: 可参考官方题解学习“差分数组 + 离线查询”的思路。
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> bloomTimeArray;
        vector<int> fadeTimeArray;
        for (const auto &flower : flowers) {
            bloomTimeArray.push_back(flower[0]);
            fadeTimeArray.push_back(flower[1] + 1); // 1
        }
        sort(bloomTimeArray.begin(), bloomTimeArray.end());
        sort(fadeTimeArray.begin(), fadeTimeArray.end());
        vector<int> res;
        for (const auto p : people) {
            res.push_back(searchLessNumer(p, bloomTimeArray) - searchLessNumer(p, fadeTimeArray));
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,6],[3,7],[9,12],[4,13]]\n[2,3,7,11]\n
// @lcpr case=end

// @lcpr case=start
// [[1,10],[3,3]]\n[3,3,2]\n
// @lcpr case=end

 */


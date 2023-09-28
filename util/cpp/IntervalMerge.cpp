#include <vector>
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
class IntervalMerge {

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
};
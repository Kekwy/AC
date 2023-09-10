//
// Created by Kekwy on 2023/9/10.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        auto inDegree = vector<int> (numCourses);
        auto res = vector<int>();
        auto graph = vector<vector<int>> (numCourses, vector<int>());
        for (vector<int> edge : prerequisites) {
            inDegree[edge[0]]++;
            graph[edge[1]].push_back(edge[0]);
        }
        stack<int> s;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                s.push(i);
            }
        }
        int count = 0;
        while (!s.empty()) {
            int v = s.top();
            s.pop();
            res.push_back(v);
            count++;
            for (int &u : graph[v]) {
                if (--inDegree[u] == 0) {
                    s.push(u);
                }
            }
        }
        if (count != numCourses) res.clear();
        return res;
    }
};

#endif //CPP_SOLUTION_H

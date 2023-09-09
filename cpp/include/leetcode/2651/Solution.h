//
// Created by Kekwy on 2023/9/9.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        auto inDegree = vector<int> (numCourses);
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
            count++;
            for (int &u : graph[v]) {
                if (--inDegree[u] == 0) {
                    s.push(u);
                }
            }
        }
        return count == numCourses;
    }
};

#endif //CPP_SOLUTION_H

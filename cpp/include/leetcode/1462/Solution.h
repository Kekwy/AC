//
// Created by Kekwy on 2023/9/14.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>

using namespace std;

class Solution {

    void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited, vector<vector<bool>> &reachable) {
        reachable[node][node] = true;
        visited[node] = true;
        for (int n : graph[node]) {
            if (!visited[n]) dfs(graph, n, visited, reachable);
            for (int i = 0; i < reachable[node].size(); i++) {
                reachable[node][i] = reachable[node][i] || reachable[n][i]; 
            }
        }
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries) {
        auto reachable = vector<vector<bool>>(numCourses, vector<bool>(numCourses, false));
        auto graph = vector<vector<int>>(numCourses, vector<int>());
        for (vector<int> edge : prerequisites) {
            graph[edge[0]].push_back(edge[1]);
        }

        auto visited = vector<bool>(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) dfs(graph, i, visited, reachable);
        }

        auto res = vector<bool>();
        for (vector<int> query : queries) {
            res.push_back(reachable[query[0]][query[1]]);
        }
        return res;
    }
};

#endif //CPP_SOLUTION_H

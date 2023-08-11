#include <iostream>

#include <vector>

using namespace std;

#include "../include/leetcode/1572/Solution.h"


int main() {
    auto *solution = new Solution();

    vector<vector<int>> input0 = vector<vector<int>>({{1, 2, 3},
                                                      {4, 5, 6},
                                                      {7, 8, 9}});

    vector<vector<int>> input1 = vector<vector<int>>({{5}});

    vector<vector<int>> input2 = vector<vector<int>>({{1, 1, 1, 1},
                                                      {1, 1, 1, 1},
                                                      {1, 1, 1, 1},
                                                      {1, 1, 1, 1}});

    solution->diagonalSum(input0);
    solution->diagonalSum(input1);
    solution->diagonalSum(input2);
    delete solution;
}

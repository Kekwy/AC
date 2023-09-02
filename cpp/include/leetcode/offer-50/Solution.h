//
// Created by Kekwy on 2023/9/2.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <string>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        int hashTable[26] = { 0 };
        for (int i = 0; i < s.length(); i++) {
            hashTable[s[i] - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (hashTable[s[i] - 'a'] == 1) return s[i];
        }
        return ' ';
    }
};

#endif //CPP_SOLUTION_H

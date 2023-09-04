//
// Created by Kekwy on 2023/9/3.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int rHashTable[26] = { 0 };
        int mHashTable[26] = { 0 };
        for (char c : ransomNote) {
            rHashTable[c - 'a']++;
        }
        for (char c : magazine) {
            mHashTable[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (rHashTable[i] > mHashTable[i]) return false;
        }
        return true;
    }
};

#endif //CPP_SOLUTION_H

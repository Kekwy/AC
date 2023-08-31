//
// Created by Kekwy on 2023/8/31.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int hashTableS[26] = { 0 };
        int hashTableT[26] = { 0 };
        for (int i = 0; i < s.length(); i++) {
            hashTableS[s[i] - 'a']++;
        }
        for (int i = 0; i < t.length(); i++) {
            hashTableT[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (hashTableS[i] != hashTableT[i]) {
                return false;
            }
        }
        return true;
    }
};

#endif //CPP_SOLUTION_H

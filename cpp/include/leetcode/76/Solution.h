//
// Created by Kekwy on 2023/8/28.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        int targetUpperNum[26] = {0}; // 存储目标字符串中各大写字母数量       
        int targetLowerNum[26] = {0}; // 存储目标字符串中各小写字母数量   
        
        for (int i = 0; i < t.length(); i++) {
            if (t[i] >= 'a' && t[i] <= 'z') {
                targetLowerNum[t[i] - 'a']++;
            } else {
                targetUpperNum[t[i] - 'A']++;
            }
        }

        int num = 0;   // 记录目标字符串中不同字符的种数
        for (int i = 0; i < 26; i++) {
            if (targetLowerNum[i] > 0) num++;
        }
        for (int i = 0; i < 26; i++) {
            if (targetUpperNum[i] > 0) num++;
        }

        int lPtr = 0, rPtr = 0;
        int tempLPtr = 0, tempRPtr = 0;
        bool flag = false;

        int upperNum[26] = {0};  
        int lowerNum[26] = {0};

        while (tempRPtr < s.length()) {
            if (!flag) {
                if (s[tempRPtr] >= 'a' && s[tempRPtr] <= 'z') {
                    lowerNum[s[tempRPtr] - 'a']++;
                    if (lowerNum[s[tempRPtr] - 'a'] == targetLowerNum[s[tempRPtr] - 'a']) {
                        num--;
                    }
                } else {
                    upperNum[s[tempRPtr] - 'A']++;
                    if (upperNum[s[tempRPtr] - 'A'] == targetUpperNum[s[tempRPtr] - 'A']) {
                        num--;
                    }
                }
                if (num == 0) {

                    while (tempLPtr < tempRPtr) {
                        if (s[tempLPtr] >= 'a' && s[tempLPtr] <= 'z') {
                            if (lowerNum[s[tempLPtr] - 'a'] - 1 < targetLowerNum[s[tempLPtr] - 'a']) {
                                break;
                            } else {
                                lowerNum[s[tempLPtr] - 'a']--;
                            }
                        } else {
                            if (upperNum[s[tempLPtr] - 'A'] - 1 < targetUpperNum[s[tempLPtr] - 'A']) {
                                break;
                            } else {
                                upperNum[s[tempLPtr] - 'A']--;
                            }
                        }
                        tempLPtr++;
                    }

                    flag = true;
                    lPtr = tempLPtr;
                    rPtr = tempRPtr;
                }
            } else {

                if (s[tempRPtr] >= 'a' && s[tempRPtr] <= 'z') {
                    lowerNum[s[tempRPtr] - 'a']++;
                } else {
                    upperNum[s[tempRPtr] - 'A']++;
                }

                while (tempLPtr < tempRPtr) {
                    if (s[tempLPtr] >= 'a' && s[tempLPtr] <= 'z') {
                        if (lowerNum[s[tempLPtr] - 'a'] - 1 < targetLowerNum[s[tempLPtr] - 'a']) {
                            break;
                        } else {
                            lowerNum[s[tempLPtr] - 'a']--;
                        }
                    } else {
                        if (upperNum[s[tempLPtr] - 'A'] - 1 < targetUpperNum[s[tempLPtr] - 'A']) {
                            break;
                        } else {
                            upperNum[s[tempLPtr] - 'A']--;
                        }
                    }
                    tempLPtr++;
                }

                if (tempRPtr - tempLPtr < rPtr - lPtr) {
                    lPtr = tempLPtr;
                    rPtr = tempRPtr;
                }
            }
            tempRPtr++;
        }

        tempRPtr--;

        if (!flag) {
            return "";
        } else {
            while (tempLPtr < tempRPtr) {
                if (s[tempLPtr] >= 'a' && s[tempLPtr] <= 'z') {
                    if (lowerNum[s[tempLPtr] - 'a'] - 1 < targetLowerNum[s[tempLPtr] - 'a']) {
                        break;
                    } else {
                        lowerNum[s[tempLPtr] - 'a']--;
                    }
                } else {
                    if (upperNum[s[tempLPtr] - 'A'] - 1 < targetUpperNum[s[tempLPtr] - 'A']) {
                        break;
                    } else {
                        upperNum[s[tempLPtr] - 'A']--;
                    }
                }
                tempLPtr++;
            }

            if (tempRPtr - tempLPtr < rPtr - lPtr) {
                lPtr = tempLPtr;
                rPtr = tempRPtr;
            }
            return s.substr(lPtr, rPtr - lPtr + 1);
        }
    }
};

#endif //CPP_SOLUTION_H

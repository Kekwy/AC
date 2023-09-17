//
// Created by Kekwy on 2023/9/3.
//

#ifndef CPP_SPLIT_H
#define CPP_SPLIT_H

#include <vector>
#include <string>

using namespace std;

class Split {

public:
    void split(const string &str, vector<string> &res, char c, int begin, int end) {
        string tmp = "";
        for (int i = begin; i < end; i++) {
            if (str[i] == c) {
                res.push_back(tmp);
                tmp.clear();
            } else {
                tmp += str[i];
            }
        }
        if (!tmp.empty()) {
            res.push_back(tmp);
        }
    }
};

#endif //CPP_SPLIT_H

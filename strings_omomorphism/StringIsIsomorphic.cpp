//
// Created by huangzewu on 15/06/2017.
//

#include <iostream>
#include "StringIsIsomorphic.h"
using namespace std;

bool StringIsIsomorphic::isIsomorphic(string &s, string &t) {
    // Write your code here
    for(int i = 0; i < s.size(); i++) {
        replace(s, i, t[i]);
    }
    return s == t;
}

void StringIsIsomorphic::replace(string &s, int pos, char c) {
    if(hadUsedForReplace.find(c) != hadUsedForReplace.end()) {
        return;
    } else {
        hadUsedForReplace.insert(c);
        char orginal = s[pos];
        for(int i = pos; i < s.size(); i++) {
            if(orginal == s[i]) {
                s.replace(i, 1, 1, c);
            }
        }
    }
}

StringIsIsomorphic *StringIsIsomorphic::instance() {
    static StringIsIsomorphic * instance = new StringIsIsomorphic();
    return instance;
}


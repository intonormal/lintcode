//
// Created by huangzewu on 15/06/2017.
//

#include <iostream>
#include "LongestPalindrome.h"

using namespace std;

LongestPalindrome *LongestPalindrome::intance() {
    static LongestPalindrome*  instance = new LongestPalindrome();
    return instance;
}

int LongestPalindrome::getLongestPalidromeOf(string &s) {
    map<char, int> dict;
    genDict(s, dict);
    //printMap(dict);
    return getEvenNumLengthSum(dict) + getMaxOddNumLength(dict);
}

void LongestPalindrome::genDict(string &s, map<char, int> &dict) {
    for(int i = 0; i < s.size(); i++) {
        auto it = dict.find(s[i]);
        if(it != dict.end()) {
            int num = it->second + 1;
            dict.erase(it);
            dict.insert(pair<char, int>(it->first, num));
        } else {
            dict.insert(pair<char, int>(s[i], 1));
        }
    }
    //cout<<"string size is:"<<s.size()<<endl;
}

int LongestPalindrome::getEvenNumLengthSum(map<char, int> &dict) {
    int sum  = 0;
    for(auto it = dict.begin(); it != dict.end(); it++) {
        if(it->second % 2 == 0)
            sum += it->second;
    }
    //cout<<"getEvenNumLengthSum:"<<sum<<endl;
    return sum;
}

int LongestPalindrome::getMaxOddNumLength(map<char, int> &dict) {
    int max = 0;
    for(auto it = dict.begin(); it != dict.end(); it++) {
        if(it->second % 2 != 0 && max < it->second)
            max = it->second;
    }
    //cout<<"getMaxOddNumLength:"<<max<<endl;
    return max;
}

void LongestPalindrome::printMap(std::map<char, int> &dict) {
    int total = 0;
    for(auto it =  dict.begin(); it != dict.end(); it++) {
        total += it->second;
        cout<< "[" <<it->first << ", "<<it->second<<"] "<<endl;
    }
    //cout<< "string size is:"<<total<<endl;
}



//
// Created by huangzewu on 16/06/2017.
//

#include <iostream>
#include "SubstringAnagrams.h"

using namespace std;
//vector<int> SubstringAnagrams::findAnagrams(string &s, string &p) {
//    // Write your code here
//    vector<int> result;
//    for(int i = 0; i < s.size(); i++) {
//        string temp = s.substr(i, p.size());
//        if(isAnagrams(temp, p)) {
//            result.push_back(i);
//            cout<<"------index = "<<i<<endl;
//        }
//    }
//    return result;
//}
void SubstringAnagrams::findAnagrams(string &s, string &p) {
    vector<int> result;

    map<char, int> dict_p;
    genDict(p, dict_p);

    int left = 0;
    int right = 0;
    int winsize = p.size();

    for(; right < s.size(); right++) {
        auto it = dict_p.find(s[right]);
        if(it != dict_p.end()) {
            int temp = it->second - 1;
            dict_p.erase(it);
            dict_p.insert(pair<char,int>(s[right], temp));
        }

        if(right - left == p.size() - 1) {
            bool flag = false;
            for(auto iter = dict_p.begin(); iter != dict_p.end(); iter++) {
                if(iter->second != 0)
                    flag = true;

            }
            if(!flag) {
                result.push_back(left);
                cout<<"index:"<<left<<endl;
            }

            auto it = dict_p.find(s[left]);
            if(it != dict_p.end()) {
                int temp = it->second + 1;
                dict_p.erase(it);
                dict_p.insert(pair<char,int>(s[left], temp));
            }
            left++;
        }

    }
}
bool SubstringAnagrams::isAnagrams(string &s, string &p) {
    if(s.size() != p.size()) return false;
    map<char, int> dict_s;
    genDict(s, dict_s);
    map<char, int> dict_p;
    genDict(p, dict_p);
    if( dict_s.size() != dict_p.size()) return false;
    for(auto it = dict_s.begin(); it != dict_s.end(); it++) {
        auto temp = dict_p.find(it->first);
        if(temp != dict_p.end() && temp->second == it->second)
            continue;
        else
            return false;
    }
    return true;
}

void SubstringAnagrams::genDict(string &s, map<char, int> &dict) {
    for(int i = 0; i < s.size(); i++) {
        auto it = dict.find(s[i]);
        if(it != dict.end()) {
            int num = it->second + 1;
            dict.erase(it);
            dict.insert(pair<char, int>(s[i], num));
        } else {
            dict.insert(pair<char, int>(s[i], 1));
        }
    }
}

SubstringAnagrams *SubstringAnagrams::instance() {
    static SubstringAnagrams * instance = new SubstringAnagrams();
    return instance;
}

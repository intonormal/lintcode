//
// Created by huangzewu on 16/06/2017.
//

#ifndef LINTCODE_SUBSTRINGANAGRAMS_H
#define LINTCODE_SUBSTRINGANAGRAMS_H

#include <vector>
#include <string>
#include <map>

class SubstringAnagrams {
public:
    void findAnagrams(std::string& s, std::string& p);
    static SubstringAnagrams *instance();

private:
    bool isAnagrams(std::string& s, std::string& p);
    void genDict(std::string &s, std::map<char, int>& dict);
};


#endif //LINTCODE_SUBSTRINGANAGRAMS_H

//
// Created by huangzewu on 15/06/2017.
//

#ifndef LINTCODE_STRINGISISOMORPHIC_H
#define LINTCODE_STRINGISISOMORPHIC_H
/*
 Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

 注意事项

You may assume both s and t have the same length.

您在真实的面试中是否遇到过这个题？ Yes
样例
Given s = "egg", t = "add", return true.

Given s = "foo", t = "bar", return false.

Given s = "paper", t = "title", return true.
 */
#include <string>
#include <set>

class StringIsIsomorphic {
public:
    static StringIsIsomorphic* instance();
    bool isIsomorphic(std::string& s, std::string& t);
private:
    void replace(std::string& s, int index, char c);
private:
    std::set<char> hadUsedForReplace;
};


#endif //LINTCODE_STRINGISISOMORPHIC_H

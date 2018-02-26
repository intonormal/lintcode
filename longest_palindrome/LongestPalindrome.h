//
// Created by huangzewu on 15/06/2017.
//
/*
 给出一个包含大小写字母的字符串。求出由这些字母构成的最长的回文串的长度是多少。

数据是大小写敏感的，也就是说，"Aa" 并不会被认为是一个回文串。

 注意事项

假设字符串的长度不会超过 1010。

您在真实的面试中是否遇到过这个题？ Yes
样例
给出 s = "abccccdd" 返回 7

一种可以构建出来的最长回文串方案是 "dccaccd"。
 */
#ifndef LINTCODE_LONGPALINDROME_H
#define LINTCODE_LONGPALINDROME_H


#include <map>
#include <string>

class LongestPalindrome {
public:
    static LongestPalindrome* intance();
    int getLongestPalidromeOf(std::string& s);

private:
    void genDict(std::string& s, std::map<char, int>& dict);
    int getEvenNumLengthSum(std::map<char, int>& dict);
    int getMaxOddNumLength(std::map<char, int>& dict);
    void printMap(std::map<char, int>& dict);
};


#endif //LINTCODE_LONGPALINDROME_H

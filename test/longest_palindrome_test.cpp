//
// Created by huangzewu on 15/06/2017.
//

#include "gtest.h"
#include <string>
#include "../longest_palindrome/LongestPalindrome.h"
using namespace std;

TEST(LongestPalindromeTest, null_string_first) {
    LongestPalindrome* instance = LongestPalindrome::intance();
    string s = "";
    EXPECT_EQ(0, instance->getLongestPalidromeOf(s));
}

TEST(LongestPalindromeTest, single_string_first) {
    LongestPalindrome* instance = LongestPalindrome::intance();
    string s = "abc";
    EXPECT_EQ(1, instance->getLongestPalidromeOf(s));
}

TEST(LongestPalindromeTest, long_string_first) {
    LongestPalindrome* instance = LongestPalindrome::intance();
    string s = "NTrQdQGgwtxqRTSBOitAXUkwGLgUHtQOmYMwZlUxqZysKpZxRoehgirdMUgy";
    EXPECT_EQ(39, instance->getLongestPalidromeOf(s));
}
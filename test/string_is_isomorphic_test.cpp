//
// Created by huangzewu on 15/06/2017.
//
#include "gtest.h"
#include <string>
#include "../strings_omomorphism/StringIsIsomorphic.h"
using namespace std;

TEST(StringIsIsomorphicTest, first_string_first) {
    StringIsIsomorphic* instance = StringIsIsomorphic::instance();
    string s = "egg";
    string t = "add";
    EXPECT_TRUE(instance->isIsomorphic(s, t));
}

TEST(StringIsIsomorphicTest, second_string_first) {
    StringIsIsomorphic* instance = StringIsIsomorphic::instance();
    string s = "foo";
    string t = "bar";
    EXPECT_FALSE(instance->isIsomorphic(s, t));
}

TEST(StringIsIsomorphicTest, third_string_first) {
    StringIsIsomorphic* instance = StringIsIsomorphic::instance();
    string s = "paper";
    string t = "title";
    EXPECT_TRUE(instance->isIsomorphic(s, t));
}


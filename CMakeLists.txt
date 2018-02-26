cmake_minimum_required(VERSION 3.7)
project(lintcode)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        test/longest_palindrome_test.cpp
        longest_palindrome/LongestPalindrome.cpp longest_palindrome/LongestPalindrome.h strings_omomorphism/StringIsIsomorphic.cpp strings_omomorphism/StringIsIsomorphic.h test/string_is_isomorphic_test.cpp substring_anagrams/SubstringAnagrams.cpp substring_anagrams/SubstringAnagrams.h test/substring_anagrams.cpp guess_game/Guess_Game.cpp guess_game/Guess_Game.h graph/source/dijkstra/dijkstra.cpp graph/source/dijkstra/dijkstra.h graph/test/dijkstr_test.cpp graph/source/MiniSpanTree/minispantree.h graph/test/minispantree_test.cpp graph/source/MiniSpanTree/minispantree.cpp graph/source/m-color/graph_color.h graph/test/graph_color_test.cpp graph/source/m-color/graph_color.cpp graph/source/m-color/node.cpp graph/source/m-color/node.h)

include_directories(
        "/usr/local/include"
        "/usr/local/include/gtest"
        "/usr/local/include/gtest/internal"
)

link_libraries(/usr/local/lib/libgtest.a)

add_executable(lintcode ${SOURCE_FILES} )
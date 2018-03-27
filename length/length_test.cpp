//
// Created by huangzewu on 20/03/2018.
//

#include "gtest.h"
#include "length.h"

TEST(Compare_Length, 1_mile_equl_to_1760_yard) {
    EXPECT_TRUE(Length(1, Mile) == Length(1760, Yard));
}

TEST(Compare_Length, 1_mile_not_equl_to_1765_yard) {
    EXPECT_TRUE(Length(1, Mile) != Length(1765, Yard));
}

TEST(Compare_Length, 1_yard_equl_to_3_feet) {
    EXPECT_TRUE(Length(1, Yard) == Length(3, Feet));
}

TEST(Compare_Length, 1_yard_not_equl_to_4_feet) {
    EXPECT_TRUE(Length(1, Yard) != Length(4, Feet));
}

TEST(Compare_Length, 1_Mile_equl_to_5280_feet) {
    EXPECT_TRUE(Length(1, Mile) == Length(5280, Feet));
}

TEST(Compare_Length, 1_Mile_not_equl_to_5290_feet) {
    EXPECT_TRUE(Length(1, Mile) != Length(5290, Feet));
}

TEST(Compare_Length, 1_Feet_equl_to_12_Inch) {
    EXPECT_TRUE(Length(1, Feet) == Length(12, Inch));
}

TEST(Compare_Length, 1_Feet_not_equl_to_13_Inch) {
    EXPECT_TRUE(Length(1, Feet) != Length(13, Inch));
}

TEST(Compare_Length, 1_Yard_equl_to_36_Inch) {
    EXPECT_TRUE(Length(1, Yard) == Length(36, Inch));
}

TEST(Compare_Length, 1_Yard_not_equl_to_36_Inch) {
    EXPECT_TRUE(Length(1, Mile) != Length(13, Inch));
}

TEST(Compare_Length, 1_Mile_equl_to_63360_Inch) {
    EXPECT_TRUE(Length(1, Mile) == Length(63360, Inch));
}

TEST(Compare_Length, 1_Mile_not_equl_to_63361_Inch) {
    EXPECT_TRUE(Length(1, Mile) != Length(63361, Inch));
}

////////////////////////////////////////////////////////////////////

TEST(Factor_Length, 12_Inch_add_2_Feet_is_36_Inch) {
    EXPECT_TRUE(Length(12, Inch) + Length(2, Feet) == Length(36, Inch));
}

////////////////////////////////////////////////////////////////////

TEST(Print_Length, 35_Inch_is_2_2_Feet_11_Inch) {
    EXPECT_TRUE(Length(35, Inch).print_to_descending() == "2 Feet 11 Inch ");
}


TEST(Print_Length, 2_Inch_is_2_Inch) {
    EXPECT_TRUE(Length(2, Inch).print_to_minUnit() == "2 Inch");
}

TEST(Print_Length, 2_Feet_is_24_Inch) {
    EXPECT_TRUE(Length(2, Feet).print_to_minUnit() == "24 Inch");
}

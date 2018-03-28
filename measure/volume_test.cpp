//
// Created by huangzewu on 20/03/2018.
//

#include "gtest.h"
#include "volume.h"

TEST(volume_test, 1_TBSP_equal_to_3_TSP) {
    EXPECT_TRUE(Volume(1, TBSP) == Volume(3, TSP));
}


TEST(volume_test, 1_TBSP_not_equal_to_4_TSP) {
    EXPECT_FALSE(Volume(1, TBSP) == Volume(4, TSP));
}

TEST(volume_test, 1_OZ_equal_to_2_TBSP) {
    EXPECT_TRUE(Volume(1, OZ) == Volume(2, TBSP));
}

TEST(volume_test, 1_OZ_not_equal_to_3_TBSP) {
    EXPECT_FALSE(Volume(1, OZ) == Volume(3, TBSP));
}

////////////////////////////////////////////////////////////////////

TEST(Factor_Volume, 1_OZ_add_3_TBSP_is_15_TBSP) {
    EXPECT_TRUE(Volume(1, OZ) + Volume(3, TBSP) == Volume(15, TSP));
}

////////////////////////////////////////////////////////////////////

TEST(Factor_Volume, 8_TSP_is_1_OZ_2_TSP) {
    EXPECT_TRUE(Volume(8, TSP).print_to_descending() == "1 OZ 2 TSP ");
}


TEST(Factor_Volume, 1_OZ_is_6_TSP) {
    EXPECT_TRUE(Volume(1, OZ).print_to_minUnit() == "6 TSP");
}
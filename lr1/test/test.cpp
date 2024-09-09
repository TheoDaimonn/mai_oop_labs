
#include <gtest/gtest.h>
#include "../include/to32Binary.hpp"

TEST(To32BinaryTest, HandlesPositiveNumbers) {
    EXPECT_EQ(to32Binary(5), "00000000000000000000000000000101");
    EXPECT_EQ(to32Binary(1023), "00000000000000000000001111111111");
    EXPECT_EQ(to32Binary(2147483647), "01111111111111111111111111111111");
}

TEST(To32BinaryTest, HandlesNegativeNumbers) {
    EXPECT_EQ(to32Binary(-5), "-00000000000000000000000000000101");
    EXPECT_EQ(to32Binary(-1023), "-00000000000000000000001111111111");

    EXPECT_EQ(to32Binary(-2147483647), "-01111111111111111111111111111111");
}

TEST(To32BinaryTest, HandlesZero) {
    EXPECT_EQ(to32Binary(0), "00000000000000000000000000000000");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

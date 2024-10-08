#include "gtest/gtest.h"
#include "../include/figures.hpp"
#include "../include/array.hpp"

using namespace lab3;

TEST(RectangleTest, AreaTest) {
    Point p1{0, 0}, p2{2, 3};
    Rectangle rect(p1, p2);
    EXPECT_DOUBLE_EQ(double(rect), 6.0);
}

TEST(RectangleTest, GeometricCenterTest) {
    Point p1{0, 0}, p2{2, 2};
    Rectangle rect(p1, p2);
    Point center = rect.geometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 1.0);
    EXPECT_DOUBLE_EQ(center.y, 1.0);
}

TEST(TrapezoidTest, AreaTest) {
    Point p1{0, 0}, p2{2, 2}, p3{4, 2}, p4{6, 0};
    Trapezoid tr(p1, p2, p3, p4);
    EXPECT_DOUBLE_EQ(double(tr), 8.0);
}

TEST(TrapezoidTest, GeometricCenterTest) {
    Point p1{0, 0}, p2{2, 2}, p3{4, 2}, p4{6, 0};
    Trapezoid tr(p1, p2, p3, p4);
    Point center = tr.geometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 3.0);
    EXPECT_DOUBLE_EQ(center.y, 1.0);
}

TEST(SquareTest, AreaTest) {
    Point p1{0, 0}, p2{2, 2};
    Square sq(p1, p2);
    EXPECT_DOUBLE_EQ(double(sq), 4.0);
}

TEST(SquareTest, GeometricCenterTest) {
    Point p1{0, 0}, p2{2, 2};
    Square sq(p1, p2);
    Point center = sq.geometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 1.0);
    EXPECT_DOUBLE_EQ(center.y, 1.0);
}

TEST(ArrayTest, PushBackTest) {
    Array array;
    Point p1{0, 0}, p2{2, 2};
    array.pushBack(new Square(p1, p2));
    EXPECT_EQ(array.size(), 1);
}

TEST(ArrayTest, EraseTest) {
    Array array;
    Point p1{0, 0}, p2{2, 2};
    array.pushBack(new Square(p1, p2));
    array.pushBack(new Rectangle(p1, p2));
    array.erase(0);
    EXPECT_EQ(array.size(), 1);
    Rectangle* rect = dynamic_cast<Rectangle*>(array[0]);
    EXPECT_TRUE(rect != nullptr);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#include <gtest/gtest.h>
#include "array.hpp"
#include "figure.hpp"

namespace lab4 {
    // Tests for the Rectangle class
    TEST(RectangleTest, Initialization) {
        Point<double> p1(0, 0);
        Point<double> p2(4, 3);
        Rectangle<double> rect(p1, p2);
        
        EXPECT_NEAR(rect.geometricCenter().x, 2, 1e-6);
        EXPECT_NEAR(rect.geometricCenter().y, 1.5, 1e-6);
    }

    TEST(RectangleTest, Equality) {
        Point<double> p1(0, 0);
        Point<double> p2(4, 3);
        Rectangle<double> rect1(p1, p2);
        Rectangle<double> rect2(p1, p2);
        Rectangle<double> rect3(Point<double>(1, 1), Point<double>(3, 2));

        EXPECT_TRUE(rect1 == rect2);
        EXPECT_FALSE(rect1 == rect3);
    }

    TEST(RectangleTest, StreamOutput) {
        Point<double> p1(0, 0);
        Point<double> p2(4, 3);
        Rectangle<double> rect(p1, p2);

        std::ostringstream oss;
        oss << rect;
        EXPECT_EQ(oss.str(), "Rectangle[ (0, 0) (4, 0) (0, 3) (4, 3) ]");
    }

    // Tests for the Square class
    TEST(SquareTest, Initialization) {
        Point<double> p1(0, 0);
        Point<double> p2(4, 4);
        Square<double> square(p1, p2);
        
        EXPECT_NEAR(square.geometricCenter().x, 2, 1e-6);
        EXPECT_NEAR(square.geometricCenter().y, 2, 1e-6);
    }

    TEST(SquareTest, Equality) {
        Point<double> p1(0, 0);
        Point<double> p2(4, 4);
        Square<double> sq1(p1, p2);
        Square<double> sq2(p1, p2);
        Square<double> sq3(Point<double>(1, 1), Point<double>(3, 3));

        EXPECT_TRUE(sq1 == sq2);
        EXPECT_FALSE(sq1 == sq3);
    }

    TEST(SquareTest, StreamOutput) {
        Point<double> p1(0, 0);
        Point<double> p2(4, 4);
        Square<double> square(p1, p2);

        std::ostringstream oss;
        oss << square;
        EXPECT_EQ(oss.str(), "Square[ (0, 0) (4, 0) (0, 4) (4, 4) ]");
    }

    // Tests for the Trapezoid class
    TEST(TrapezoidTest, Initialization) {
        Point<double> p1(0, 0);
        Point<double> p2(4, 0);
        Point<double> p3(3, 3);
        Point<double> p4(1, 3);
        Trapezoid<double> trap(p1, p2, p3, p4);
        
        EXPECT_NEAR(trap.geometricCenter().x, 2, 1e-6);
        EXPECT_NEAR(trap.geometricCenter().y, 1.5, 1e-6);
    }

    TEST(TrapezoidTest, Equality) {
        Point<double> p1(0, 0);
        Point<double> p2(4, 0);
        Point<double> p3(3, 3);
        Point<double> p4(1, 3);
        Trapezoid<double> trap1(p1, p2, p3, p4);
        Trapezoid<double> trap2(p1, p2, p3, p4);
        Trapezoid<double> trap3(Point<double>(0, 0), Point<double>(4, 0), Point<double>(2, 2), Point<double>(1, 2));

        EXPECT_TRUE(trap1 == trap2);
        EXPECT_FALSE(trap1 == trap3);
    }

    TEST(TrapezoidTest, StreamOutput) {
        Point<double> p1(0, 0);
        Point<double> p2(4, 0);
        Point<double> p3(3, 3);
        Point<double> p4(1, 3);
        Trapezoid<double> trap(p1, p2, p3, p4);

        std::ostringstream oss;
        oss << trap;
        EXPECT_EQ(oss.str(), "Trapezoid[ (0, 0) (4, 0) (3, 3) (1, 3) ]");
    }

    // Test for move constructors and assignment
    TEST(MoveConstructorAndAssignment, Rectangle) {
        Point<double> p1(0, 0);
        Point<double> p2(4, 3);
        Rectangle<double> rect1(p1, p2);
        
        Rectangle<double> rect2(std::move(rect1)); // Move constructor
        EXPECT_NEAR(rect2.geometricCenter().x, 2, 1e-6);
        EXPECT_NEAR(rect2.geometricCenter().y, 1.5, 1e-6);
        
        Rectangle<double> rect3;
        rect3 = std::move(rect2); // Move assignment
        EXPECT_NEAR(rect3.geometricCenter().x, 2, 1e-6);
        EXPECT_NEAR(rect3.geometricCenter().y, 1.5, 1e-6);
    }

    TEST(MoveConstructorAndAssignment, Square) {
        Point<double> p1(0, 0);
        Point<double> p2(4, 4);
        Square<double> sq1(p1, p2);
        
        Square<double> sq2(std::move(sq1)); // Move constructor
        EXPECT_NEAR(sq2.geometricCenter().x, 2, 1e-6);
        EXPECT_NEAR(sq2.geometricCenter().y, 2, 1e-6);
        
        Square<double> sq3;
        sq3 = std::move(sq2); // Move assignment
        EXPECT_NEAR(sq3.geometricCenter().x, 2, 1e-6);
        EXPECT_NEAR(sq3.geometricCenter().y, 2, 1e-6);
    }

    TEST(MoveConstructorAndAssignment, Trapezoid) {
        Point<double> p1(0, 0);
        Point<double> p2(4, 0);
        Point<double> p3(3, 3);
        Point<double> p4(1, 3);
        Trapezoid<double> trap1(p1, p2, p3, p4);
        
        Trapezoid<double> trap2(std::move(trap1)); // Move constructor
        EXPECT_NEAR(trap2.geometricCenter().x, 2, 1e-6);
        EXPECT_NEAR(trap2.geometricCenter().y, 1.5, 1e-6);
        
        Trapezoid<double> trap3;
        trap3 = std::move(trap2); // Move assignment
        EXPECT_NEAR(trap3.geometricCenter().x, 2, 1e-6);
        EXPECT_NEAR(trap3.geometricCenter().y, 1.5, 1e-6);
    }
}
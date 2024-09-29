#include <gtest/gtest.h>
#include "../include/Twelve.hpp"

// Тесты для конструктора по умолчанию
TEST(TwelveTest, DefaultConstructor) {
    Twelve num;
    EXPECT_EQ(num.getSize(), 1);
    EXPECT_EQ(num.getData()[0], '0');
}

// Тесты для конструктора с размером и символом
TEST(TwelveTest, ConstructorWithSizeAndChar) {
    Twelve num(4, '1');
    EXPECT_EQ(num.getSize(), 4);
    EXPECT_EQ(num.getData()[0], '1');
    EXPECT_EQ(num.getData()[1], '1');
    EXPECT_EQ(num.getData()[2], '1');
    EXPECT_EQ(num.getData()[3], '1');
}



// Тесты для сложения
TEST(TwelveTest, Addition) {
    Twelve num1("1111");
    Twelve num2("111");
    num1 += num2;
    std::cout << num1.getData() << "\n\n\n";
    EXPECT_EQ(num1.getSize(), 4);
    EXPECT_EQ(num1.getData()[3], '1');
    EXPECT_EQ(num1.getData()[2], '2');
    EXPECT_EQ(num1.getData()[1], '2');
    EXPECT_EQ(num1.getData()[0], '2'); // 1111 + 111 = 1222
}

// Тесты для вычитания
TEST(TwelveTest, Subtraction) {
    Twelve num1("2222");
    Twelve num2("111");
    num1 -= num2;

    EXPECT_EQ(num1.getSize(), 4);
    EXPECT_EQ(num1.getData()[3], '2');
    EXPECT_EQ(num1.getData()[2], '1');
    EXPECT_EQ(num1.getData()[1], '1');
    EXPECT_EQ(num1.getData()[0], '1'); // 2222 - 111 = 2111
}

// Тесты для равенства
TEST(TwelveTest, Equality) {
    Twelve num1("1111");
    Twelve num2("1111");
    Twelve num3("2222");

    EXPECT_TRUE(num1 == num2);
    EXPECT_FALSE(num1 == num3);
}

// Тесты для сравнения больше/меньше
TEST(TwelveTest, Comparison) {
    Twelve num1("1111");
    Twelve num2("2222");

    EXPECT_TRUE(num1 < num2);
    EXPECT_FALSE(num1 > num2);
    EXPECT_TRUE(num1 != num2);
}

// Тест на исключение при вычитании
TEST(TwelveTest, SubtractionException) {
    Twelve num1("111");
    Twelve num2("2222");

    EXPECT_THROW(num1 -= num2, std::runtime_error);
}

// Тест на исключение при недопустимых символах
TEST(TwelveTest, InvalidCharacter) {
    EXPECT_THROW(Twelve num("1C2"), std::logic_error);
}

// Тест на самоприсваивание
TEST(TwelveTest, SelfAssignment) {
    Twelve num("1111");
    EXPECT_THROW(num = num, std::runtime_error);
}

// Главная функция тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

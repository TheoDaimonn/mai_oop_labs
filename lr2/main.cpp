#include <iostream>
#include "./include/Twelve.hpp"

int main(){
    size_t firstLength;
    std::cout << "Enter the first digit length: ";
    std::cin >> firstLength;

    unsigned char firstVal;
    std::cout << "Enter default number for the first: ";
    std::cin >> firstVal;

    Twelve number1;

    try {
        number1 = Twelve(firstLength, firstVal);
        std::cout << "First number: ";
        number1.repr();
    } catch(...){
        std::cout << "Something went wrong";

    }


    std::cout << "Enter 3 twelve numeric digits to form second number: ";
    unsigned char secValue[3];
    for (int i = 0; i < 3; ++i){
        std::cin >> secValue[i];
    }

    Twelve number2;
    try{
        number2 = Twelve({secValue[0], secValue[1], secValue[2]});
        std::cout << "Second number: ";
        number2.repr();
    } catch(...){
        std::cout << "Something went wrong with init second number" << std::endl;
        return 1;
    }

    std::string thridVal;
    std::cout << "Enter the string to set the third number";
    std::cin >> thridVal;

    Twelve number3;
    try{
        number3 = Twelve(thridVal);
        std::cout << "Third number: ";
        number3.repr();
    } catch(...){
        std::cout << "Something went wrong with init third number";
    }

    // Проверка суммы
    Twelve sumOfTheTwo = number1;
    sumOfTheTwo += number2;
    std::cout << "Summ of the number1 and number2: ";
    sumOfTheTwo.repr();

    Twelve diffOfTheTwo = number1;
    try{
        diffOfTheTwo -= number2;
        std::cout << "Difference between number 1 and number 2: ";
        diffOfTheTwo.repr();
    } catch(...){
        std::cout << "Troubles with the diffenerce encount. Check if number 1 is more than number 2";
        return 1;
    }

    std::cout << "Equatation of number1 and number2: " << (number1 == number2) << "\n" << "Is number1 more than number3?" << (number1 > number3) << "\n" << "Is the number2 less than number3" << (number2 < number3) << "\n";
    return 0;

}

#include "../include/to32Binary.hpp"

std::string to32Binary(int number){
    std::string result = "";
    std::string f = "";
    if (number < 0){
        f = "-";
        number *= -1;
    }
    for (int i = 31; i >= 0; i--){
        result += std::to_string(number%2);
        number /=2;
    }
    result += f;
    reverse(result.begin(), result.end());
    return result;
}


#include "include/to32Binary.hpp"

using namespace std;
int main(){
    int number;
    std::cin >> number;

    std::string res = to32Binary(number);
    std::cout << "Result:" << endl;
    std::cout <<res<< endl;
    return 0;
}
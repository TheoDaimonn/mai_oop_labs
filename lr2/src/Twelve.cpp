#include <iostream>
#include "../include/Twelve.hpp"
#include <stdexcept>
#include <unordered_map>

const char digits[12] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B'};
const std::unordered_map<unsigned char, int> convert = {
    {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5},
    {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}
};

void isDigit(unsigned char digit) {
    if (!(digit >= '0' && digit <= '9') && !(digit == 'A' || digit == 'B')) {
        throw std::logic_error("Contains a wrong number");
    }
}

unsigned char* allocateMemory(size_t size) {
    unsigned char* ptr = new(std::nothrow) unsigned char[size]{0};
    if (!ptr) {
        throw std::runtime_error("Cannot create a ptr");
    }
    return ptr;
}

Twelve::Twelve() : size{1}, data{allocateMemory(1)} {
    data[0] = '0';
}

Twelve::Twelve(const size_t& n, unsigned char t) {
    isDigit(t);
    size = n;
    data = allocateMemory(n);

    for (size_t i = 0; i < n; ++i) {
        data[i] = t;
    }
}

Twelve::Twelve(const std::initializer_list<unsigned char>& t) {
    size = t.size();
    data = allocateMemory(size);

    size_t i = size - 1;
    for (unsigned char digit : t) {
        isDigit(digit);
        data[i--] = digit;
    }
}

Twelve::Twelve(const std::string& t) {
    size = t.size();
    data = allocateMemory(size);

    for (size_t i = 0; i < size; i++) {
        isDigit(t[size - 1 - i]);
        data[i] = t[size - 1 - i];
    }
}

Twelve::Twelve(const Twelve& other) {
    if (this == &other) {
        throw std::runtime_error("Object already exists");
    }
    size = other.size;
    data = allocateMemory(size);

    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

Twelve::Twelve(Twelve&& other) noexcept {
    size = other.size;
    data = other.data;
    other.data = nullptr;  // Это безопасно, так как другой объект станет недействительным
    other.size = 0;        // Устанавливаем в 0, чтобы предотвратить двойное освобождение памяти
}

Twelve& Twelve::operator=(const Twelve& other) {
    if (this == &other) {
        throw std::runtime_error("Same elements are included");
    }
    delete[] data;

    size = other.size;
    data = allocateMemory(size);

    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
    return *this;
}

// Добавлена реализация оператора перемещения
Twelve& Twelve::operator=(Twelve&& other) noexcept {
    if (this != &other) {
        delete[] data; // Освобождаем текущую память

        size = other.size;
        data = other.data;

        other.data = nullptr; // Безопасное обнуление для предотвращения двойного освобождения
        other.size = 0;       // Сбрасываем размер
    }
    return *this;
}

Twelve& Twelve::operator+=(const Twelve& other) {
    size_t maxSize = std::max(getSize(), other.getSize());
    unsigned char* newData = allocateMemory(maxSize + 1);
    int carry = 0; 
    size_t i;

    for (i = 0; i < maxSize; ++i) {
        int sum = carry; 
        if (i < size) {
            sum += convert.at(data[i]);
        }
        if (i < other.size) {
            sum += convert.at(other.data[i]);
        }

        newData[i] = digits[sum % 12];
        carry = sum / 12; 
    }

    if (carry > 0) {
        newData[i] = digits[carry];
        ++i;
    }

    delete[] data; 
    data = newData;
    size = i; 
    return *this;
}

Twelve& Twelve::operator-=(const Twelve& other) {
    if (size < other.size) {
        throw std::runtime_error("Result must be >= 0");
    }

    int borrow = 0;
    for (size_t i = 0; i < size; ++i) {
        int otherDigit = (i < other.size) ? convert.at(other.data[i]) : 0;
        int diff = convert.at(data[i]) - otherDigit - borrow;

        if (diff < 0) {
            diff += 12; 
            borrow = 1; 
        } else {
            borrow = 0; 
        }

        data[i] = digits[diff];
    }

    if (borrow != 0) {
        throw std::runtime_error("Result must be >= 0");
    }

    return *this;
}

bool Twelve::operator==(const Twelve& other) const {
    if (size != other.size) {
        return false;
    }

    for (size_t i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }

    return true;
}

bool Twelve::operator<(const Twelve& other) const {
    if (size != other.size) {
        return size < other.size;
    }

    for (size_t i = size; i-- > 0;) {
        if (convert.at(data[i]) != convert.at(other.data[i])) {
            return convert.at(data[i]) < convert.at(other.data[i]);
        }
    }

    return false;
}

bool Twelve::operator>(const Twelve& other) const {
    return other < *this;
}

bool Twelve::operator!=(const Twelve& other) const {
    return !(*this == other);
}

size_t Twelve::getSize() const {
    return size;
}

unsigned char* Twelve::getData() const {
    return data;
}

void Twelve::repr() const {
    for (int i = size - 1; i >= 0; --i) {
        std::cout << data[i];
    }
    std::cout << std::endl;
}

// Изменен деструктор: убрано зануление
Twelve::~Twelve() noexcept {
    delete[] data; // Просто очищаем память, но не обнуляем указатель
}


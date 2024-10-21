#pragma once

#include <vector>
#include <memory>
#include <stdexcept>

namespace lab4 {

template <typename T>
class Array {
private:
    std::vector<T> data;

public:
    Array() = default;
    Array(std::initializer_list<T> list) : data(list) {}

    void pushBack(const T& item) {
        data.push_back(item);
    }

    void erase(size_t index) {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        data.erase(data.begin() + index);
    }

    size_t size() const {
        return data.size();
    }

    T& operator[](size_t index) {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
};

}
#include "queue.hpp"

template <typename T>
void PmrQueue<T>::push(const T& value) {
    data_.push_back(value);
}

template <typename T>
void PmrQueue<T>::pop() {
    if (!data_.empty()) {
        data_.erase(data_.begin());
    }
}

template <typename T>
T& PmrQueue<T>::front() {
    return data_.front();
}

template <typename T>
const T& PmrQueue<T>::front() const {
    return data_.front();
}

template class PmrQueue<int>;
template class PmrQueue<std::string>;


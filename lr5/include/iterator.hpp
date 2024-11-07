#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>

template <typename T>
class PmrQueueIterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using difference_type = std::ptrdiff_t;

    explicit PmrQueueIterator(pointer ptr) : ptr_(ptr) {}

    reference operator*() const { return *ptr_; }
    pointer operator->() { return ptr_; }
    PmrQueueIterator& operator++() { ++ptr_; return *this; }
    PmrQueueIterator operator++(int) { PmrQueueIterator temp = *this; ++(*this); return temp; }

    bool operator==(const PmrQueueIterator& other) const { return ptr_ == other.ptr_; }
    bool operator!=(const PmrQueueIterator& other) const { return !(*this == other); }

private:
    pointer ptr_;
};

#endif // ITERATOR_HPP

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <memory_resource>
#include <vector>
#include <iterator>

template <typename T>
class PmrQueue {
public:
    using allocator_type = std::pmr::polymorphic_allocator<T>;
    using iterator = typename std::vector<T, allocator_type>::iterator;
    using const_iterator = typename std::vector<T, allocator_type>::const_iterator;

    explicit PmrQueue(std::pmr::memory_resource* resource) 
        : data_(resource) {}

    void push(const T& value);
    void pop();
    T& front();
    const T& front() const;

    iterator begin() { return data_.begin(); }
    iterator end() { return data_.end(); }
    const_iterator begin() const { return data_.begin(); }
    const_iterator end() const { return data_.end(); }

private:
    std::vector<T, allocator_type> data_; 
};

#endif 

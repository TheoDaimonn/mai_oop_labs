#include "memory_resource.hpp"
#include <new>

PoolMemoryResource::~PoolMemoryResource() {
    for (void* block : freed_blocks_) {
        std::free(block);
    }
}
void* PoolMemoryResource::do_allocate(std::size_t bytes, std::size_t alignment) {
    void* ptr = nullptr;
    if (!freed_blocks_.empty()) {
        ptr = freed_blocks_.front();
        freed_blocks_.pop_front();
    } else {
        ptr = std::aligned_alloc(alignment, bytes);
    }

    if (!ptr) {
        throw std::bad_alloc();
    }

    return ptr;
}

void PoolMemoryResource::do_deallocate(void* p, std::size_t bytes, std::size_t alignment) {
    freed_blocks_.push_back(p);
}

bool PoolMemoryResource::do_is_equal(const std::pmr::memory_resource& other) const noexcept {
    return this == &other;
}

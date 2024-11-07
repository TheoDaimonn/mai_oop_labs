#ifndef MEMORY_RESOURCE_HPP
#define MEMORY_RESOURCE_HPP

#include <memory_resource>
#include <list>
#include <cstdlib>

class PoolMemoryResource : public std::pmr::memory_resource {
public:
    PoolMemoryResource() = default;
    ~PoolMemoryResource();

//должны быть protected, но публичны для тестов
    void* do_allocate(std::size_t bytes, std::size_t alignment) override;
    void do_deallocate(void* p, std::size_t bytes, std::size_t alignment) override;
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override;

private:
    std::list<void*> freed_blocks_;  // Список освобожденных блоков памяти
};

#endif

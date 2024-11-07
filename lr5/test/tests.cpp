#include <gtest/gtest.h>
#include "../include/memory_resource.hpp"
#include "../include/queue.hpp"

class PoolMemoryResourceTest : public ::testing::Test {
protected:
    PoolMemoryResource pool;

};

TEST_F(PoolMemoryResourceTest, TestAllocateDeallocate) {
    void* ptr1 = pool.do_allocate(100, alignof(std::max_align_t));
    void* ptr2 = pool.do_allocate(200, alignof(std::max_align_t));
    EXPECT_NE(ptr1, nullptr);
    EXPECT_NE(ptr2, nullptr);

    pool.do_deallocate(ptr1, 100, alignof(std::max_align_t));
    pool.do_deallocate(ptr2, 200, alignof(std::max_align_t));

    void* ptr3 = pool.do_allocate(100, alignof(std::max_align_t));
    EXPECT_EQ(ptr1, ptr3); 
}

class PmrQueueTest : public ::testing::Test {
protected:
    PoolMemoryResource pool;

    template <typename T>
    PmrQueue<T> createQueue() {
        return PmrQueue<T>(&pool);
    }
};

TEST_F(PmrQueueTest, TestPushPop) {
    PmrQueue<int> queue = createQueue<int>();

    queue.push(10);
    queue.push(20);
    queue.push(30);

    EXPECT_EQ(queue.front(), 10);  // Должен быть первый добавленный элемент
    queue.pop();
    EXPECT_EQ(queue.front(), 20);  // После pop должен быть второй элемент
    queue.pop();
    EXPECT_EQ(queue.front(), 30);  // Теперь должен остаться третий элемент
}

TEST_F(PmrQueueTest, TestIterator) {
    PmrQueue<int> queue = createQueue<int>();

    queue.push(10);
    queue.push(20);
    queue.push(30);

    // Проверка итератора
    int index = 0;
    for (int value : queue) {
        if (index == 0) EXPECT_EQ(value, 10);
        else if (index == 1) EXPECT_EQ(value, 20);
        else if (index == 2) EXPECT_EQ(value, 30);
        index++;
    }
}

TEST_F(PmrQueueTest, TestComplexType) {
    PmrQueue<std::string> queue = createQueue<std::string>();

    // Добавляем строковые элементы
    queue.push("mrr");
    queue.push("meow");

    // Проверка элементов очереди
    EXPECT_EQ(queue.front(), "mrr");
    queue.pop();
    EXPECT_EQ(queue.front(), "meow");
}



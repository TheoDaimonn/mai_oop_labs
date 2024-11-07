#include <iostream>
#include "include/memory_resource.hpp"
#include "include/queue.hpp"

int main() {
    // Создаем память с помощью PoolMemoryResource
    PoolMemoryResource pool;

    // Создаем контейнер, который использует нашу память
    PmrQueue<int> queue(&pool);

    // Добавляем несколько элементов
    queue.push(10);
    queue.push(20);
    queue.push(30);

    // Выводим элементы
    std::cout << "Queue front: " << queue.front() << std::endl;

    // Используем итераторы для вывода содержимого очереди
    std::cout << "Queue contents: ";
    for (int value : queue) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Удаляем элемент из очереди
    queue.pop();
    std::cout << "After pop, front: " << queue.front() << std::endl;

    // Пример с более сложным типом
    PmrQueue<std::string> stringQueue(&pool);
    stringQueue.push("mrrr");
    stringQueue.push("meow");

    for (const std::string& str : stringQueue) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}

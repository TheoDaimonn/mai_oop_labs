#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <string>
#include <iostream>
#include <fstream>

// Интерфейс наблюдателя
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const std::string& message) = 0;
};

class ConsoleObserver : public Observer {
public:
    void update(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class FileObserver : public Observer {
private:
    std::string filename;
public:
    explicit FileObserver(const std::string& filename) : filename(filename) {}
    void update(const std::string& message) override {
        std::ofstream file(filename, std::ios::app);
        if (file) {
            file << message << std::endl;
        }
    }
};

#endif 

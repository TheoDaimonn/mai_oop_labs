#ifndef NPC_HPP
#define NPC_HPP

#include <string>
#include <iostream>

class NPC {
protected:
    std::string name;
    int x, y;
public:
    NPC(const std::string& name, int x, int y) : name(name), x(x), y(y) {}
    virtual ~NPC() = default;

    virtual std::string getType() const = 0;
    const std::string& getName() const { return name; }
    int getX() const { return x; }
    int getY() const { return y; }

    void print() const {
        std::cout << getType() << " [" << name << "] (" << x << ", " << y << ")\n";
    }
    //Битву опрелелим в .cpp файле для каждого из классов
    virtual bool canDefeat(NPC* other) const = 0;
};

class Knight : public NPC {
public:
    Knight(const std::string& name, int x, int y) : NPC(name, x, y) {}
    std::string getType() const override { return "Knight"; }
    bool canDefeat(NPC* other) const override;
};

class Squirrel : public NPC {
public:
    Squirrel(const std::string& name, int x, int y) : NPC(name, x, y) {}
    std::string getType() const override { return "Squirrel"; }
    bool canDefeat(NPC* other) const override;
};

class Pegasus : public NPC {
public:
    Pegasus(const std::string& name, int x, int y) : NPC(name, x, y) {}
    std::string getType() const override { return "Pegasus"; }
    bool canDefeat(NPC* other) const override;
};

#endif 

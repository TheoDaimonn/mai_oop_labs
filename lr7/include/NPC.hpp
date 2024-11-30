#ifndef NPC_HPP
#define NPC_HPP

#include <string>
#include <iostream>
#include <random>

class NPC {
protected:
    std::string name;
    int x, y;
    bool alive;

public:
    NPC(const std::string& name, int x, int y)
        : name(name), x(x), y(y), alive(true) {}

    virtual ~NPC() = default;

    virtual std::string getType() const = 0;

    const std::string& getName() const { return name; }
    int getX() const { return x; }
    int getY() const { return y; }
    bool isAlive() const { return alive; }
    void kill() { alive = false; }

    void move(int dx, int dy, int mapWidth, int mapHeight) {
        if (alive) {
            x = std::max(0, std::min(mapWidth - 1, x + dx));
            y = std::max(0, std::min(mapHeight - 1, y + dy));
        }
    }

    void setPosition(int newX, int newY) {
        x = newX;
        y = newY;
    }

    virtual bool canDefeat(NPC* other) const = 0;
    virtual int getMoveDistance() const = 0;
    virtual int getKillDistance() const = 0;

    void print() const {
        std::cout << getType() << " [" << name << "] (" << x << ", " << y << ")\n";
    }
};

class Knight : public NPC {
public:
    Knight(const std::string& name, int x, int y) : NPC(name, x, y) {}

    std::string getType() const override { return "Knight"; }
    bool canDefeat(NPC* other) const override { return other->getType() == "Squirrel"; }
    int getMoveDistance() const override { return 30; }
    int getKillDistance() const override { return 10; }
};

class Squirrel : public NPC {
public:
    Squirrel(const std::string& name, int x, int y) : NPC(name, x, y) {}

    std::string getType() const override { return "Squirrel"; }
    bool canDefeat(NPC* other) const override { return other->getType() == "Pegasus"; }
    int getMoveDistance() const override { return 5; }
    int getKillDistance() const override { return 5; }
};

class Pegasus : public NPC {
public:
    Pegasus(const std::string& name, int x, int y) : NPC(name, x, y) {}

    std::string getType() const override { return "Pegasus"; }
    bool canDefeat(NPC* other) const override { return false; }
    int getMoveDistance() const override { return 30; }
    int getKillDistance() const override { return 10; }
};

#endif
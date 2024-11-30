#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "NPC.hpp"
#include <vector>
#include <memory>
#include <random>

class Factory {
public:
    static std::unique_ptr<NPC> createNPC(const std::string& type, const std::string& name, int x, int y);
    static std::vector<std::unique_ptr<NPC>> createRandomNPCs(int count, int mapWidth, int mapHeight);
};

#endif
#include "Factory.hpp"

std::unique_ptr<NPC> Factory::createNPC(const std::string& type, const std::string& name, int x, int y) {
    if (type == "Knight") return std::make_unique<Knight>(name, x, y);
    if (type == "Squirrel") return std::make_unique<Squirrel>(name, x, y);
    if (type == "Pegasus") return std::make_unique<Pegasus>(name, x, y);
    throw std::invalid_argument("Unknown NPC type: " + type);
}

std::vector<std::unique_ptr<NPC>> Factory::createRandomNPCs(int count, int mapWidth, int mapHeight) {
    std::vector<std::unique_ptr<NPC>> npcs;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> xDist(0, mapWidth - 1);
    std::uniform_int_distribution<> yDist(0, mapHeight - 1);
    std::uniform_int_distribution<> typeDist(0, 2);

    for (int i = 0; i < count; ++i) {
        int x = xDist(gen);
        int y = yDist(gen);
        std::string name = "NPC_" + std::to_string(i);
        std::string type = (typeDist(gen) == 0) ? "Knight" : (typeDist(gen) == 1) ? "Squirrel" : "Pegasus";

        npcs.push_back(createNPC(type, name, x, y));
    }

    return npcs;
}
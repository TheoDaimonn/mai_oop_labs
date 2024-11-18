#include "Factory.hpp"

std::unique_ptr<NPC> Factory::createNPC(const std::string& type, const std::string& name, int x, int y) {
    if (type == "Knight") return std::make_unique<Knight>(name, x, y);
    if (type == "Squirrel") return std::make_unique<Squirrel>(name, x, y);
    if (type == "Pegasus") return std::make_unique<Pegasus>(name, x, y);
    throw std::invalid_argument("Unknown NPC type: " + type);
}

std::vector<std::unique_ptr<NPC>> Factory::loadFromFile(const std::string& filename) {
    std::vector<std::unique_ptr<NPC>> npcs;
    std::ifstream file(filename);
    if (!file) throw std::ios_base::failure("Failed to open file: " + filename);

    std::string type, name;
    int x, y;
    while (file >> type >> name >> x >> y) {
        npcs.push_back(createNPC(type, name, x, y));
    }
    return npcs;
}

void Factory::saveToFile(const std::string& filename, const std::vector<std::unique_ptr<NPC>>& npcs) {
    std::ofstream file(filename);
    if (!file) throw std::ios_base::failure("Failed to open file: " + filename);

    for (const auto& npc : npcs) {
        file << npc->getType() << " " << npc->getName() << " " << npc->getX() << " " << npc->getY() << "\n";
    }
}

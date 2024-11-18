#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "NPC.hpp"
#include <memory>
#include <vector>
#include <fstream>

class Factory {
public:
    static std::unique_ptr<NPC> createNPC(const std::string& type, const std::string& name, int x, int y);
    static std::vector<std::unique_ptr<NPC>> loadFromFile(const std::string& filename);
    static void saveToFile(const std::string& filename, const std::vector<std::unique_ptr<NPC>>& npcs);
};

#endif 

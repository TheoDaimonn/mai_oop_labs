#include "include/Factory.hpp"
#include "include/Visitor.hpp"
#include "include/Observer.hpp"

int main() {
    std::vector<std::unique_ptr<NPC>> npcs;

    ConsoleObserver consoleObserver;
    FileObserver fileObserver("log.txt");

    npcs.push_back(Factory::createNPC("Knight", "Oleg", 50, 50));
    npcs.push_back(Factory::createNPC("Squirrel", "Wendy", 100, 100));
    npcs.push_back(Factory::createNPC("Pegasus", "Hippie", 300, 300));

    std::cout << "Initial NPCs:\n";
    for (const auto& npc : npcs) {
        npc->print();
    }

    BattleVisitor battleVisitor(150.0);
    battleVisitor.addObserver(&consoleObserver);
    battleVisitor.addObserver(&fileObserver);
    battleVisitor.execute(npcs);

    std::cout << "\nRemaining NPCs:\n";
    for (const auto& npc : npcs) {
        npc->print();
    }

    return 0;
}

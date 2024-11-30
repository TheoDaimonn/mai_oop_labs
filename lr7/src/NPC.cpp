#include "NPC.hpp"

// Utility function to calculate the distance between two NPCs
double calculateDistance(const NPC* npc1, const NPC* npc2) {
    return std::sqrt(std::pow(npc1->getX() - npc2->getX(), 2) + std::pow(npc1->getY() - npc2->getY(), 2));
}

// Utility function to check if two NPCs are within a certain range
bool areWithinRange(const NPC* npc1, const NPC* npc2, double range) {
    return calculateDistance(npc1, npc2) <= range;
}
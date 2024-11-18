#include "NPC.hpp"

bool Knight::canDefeat(NPC* other) const {
    return other->getType() == "Squirrel";
}
bool Squirrel::canDefeat(NPC* other) const {
    return other->getType() == "Pegasus";
}
bool Pegasus::canDefeat(NPC* other) const {
    return false; // т.к. никого не атакует
}

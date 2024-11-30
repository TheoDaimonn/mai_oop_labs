#ifndef GAME_HPP
#define GAME_HPP

#include "NPC.hpp"
#include "Factory.hpp"
#include <vector>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <condition_variable>
#include <atomic> 

class Game {
private:
    std::vector<std::unique_ptr<NPC>> npcs;
    const int mapWidth, mapHeight;
    const int durationInSeconds;
    std::shared_mutex npcMutex;
    std::mutex coutMutex;
    std::atomic<bool> running; 

    void moveNPCs();
    void handleBattles();
    void printMap();

public:
    Game(int mapWidth, int mapHeight, int durationInSeconds);
    void start();
};

#endif
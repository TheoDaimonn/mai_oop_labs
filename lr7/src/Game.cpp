#include "Game.hpp"
#include <iostream>
#include <cmath>
#include <chrono>
#include <random>

Game::Game(int mapWidth, int mapHeight, int durationInSeconds)
    : mapWidth(mapWidth), mapHeight(mapHeight), durationInSeconds(durationInSeconds), running(false) {
    npcs = Factory::createRandomNPCs(50, mapWidth, mapHeight);
}

void Game::start() {
    running = true;

    std::thread moveThread(&Game::moveNPCs, this);
    std::thread battleThread(&Game::handleBattles, this);

    auto startTime = std::chrono::steady_clock::now();

    while (std::chrono::steady_clock::now() - startTime < std::chrono::seconds(durationInSeconds)) {
        printMap();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    running = false;
    moveThread.join();
    battleThread.join();

    std::cout << "\nGame Over. Survivors:\n";
    for (const auto& npc : npcs) {
        if (npc->isAlive()) npc->print();
    }
}

void Game::moveNPCs() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> moveDist(-5, 5);

    while (running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        std::unique_lock lock(npcMutex);
        for (auto& npc : npcs) {
            if (npc->isAlive()) {
                int dx = moveDist(gen);
                int dy = moveDist(gen);
                npc->move(dx, dy, mapWidth, mapHeight);
            }
        }
    }
}

void Game::handleBattles() {
    while (running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        std::unique_lock lock(npcMutex);
        for (size_t i = 0; i < npcs.size(); ++i) {
            if (!npcs[i]->isAlive()) continue;

            for (size_t j = i + 1; j < npcs.size(); ++j) {
                if (!npcs[j]->isAlive()) continue;

                double distance = std::sqrt(
                    std::pow(npcs[i]->getX() - npcs[j]->getX(), 2) + std::pow(npcs[i]->getY() - npcs[j]->getY(), 2));

                if (distance <= npcs[i]->getKillDistance() && npcs[i]->canDefeat(npcs[j].get())) {
                    std::lock_guard<std::mutex> coutLock(coutMutex);
                    std::cout << npcs[i]->getName() << " killed " << npcs[j]->getName() << "\n";
                    npcs[j]->kill();
                } else if (distance <= npcs[j]->getKillDistance() && npcs[j]->canDefeat(npcs[i].get())) {
                    std::lock_guard<std::mutex> coutLock(coutMutex);
                    std::cout << npcs[j]->getName() << " killed " << npcs[i]->getName() << "\n";
                    npcs[i]->kill();
                }
            }
        }
    }
}

void Game::printMap() {
    std::shared_lock lock(npcMutex);
    std::lock_guard<std::mutex> coutLock(coutMutex);

    std::cout << "Map:\n";
    for (const auto& npc : npcs) {
        if (npc->isAlive()) {
            npc->print();
        }
    }
    std::cout << "----------\n";
}
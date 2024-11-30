#include "gtest/gtest.h"
#include "../include/Factory.hpp"
#include "../include/Visitor.hpp"
#include "../include/Observer.hpp"
#include "../include/NPC.hpp"

// Подключение необходимых заголовков
#include <vector>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <random>

// ==================== Тесты NPCFactory ====================

// создание NPC через Factory
TEST(FactoryTest, CreateNPCTest) {
    auto knight = Factory::createNPC("Knight", "Arthur", 50, 50);
    EXPECT_EQ(knight->getType(), "Knight");
    EXPECT_EQ(knight->getName(), "Arthur");
    EXPECT_EQ(knight->getX(), 50);
    EXPECT_EQ(knight->getY(), 50);

    auto squirrel = Factory::createNPC("Squirrel", "Chippy", 100, 100);
    EXPECT_EQ(squirrel->getType(), "Squirrel");
    EXPECT_EQ(squirrel->getName(), "Chippy");
    EXPECT_EQ(squirrel->getX(), 100);
    EXPECT_EQ(squirrel->getY(), 100);

    auto pegasus = Factory::createNPC("Pegasus", "Windy", 300, 300);
    EXPECT_EQ(pegasus->getType(), "Pegasus");
    EXPECT_EQ(pegasus->getName(), "Windy");
    EXPECT_EQ(pegasus->getX(), 300);
    EXPECT_EQ(pegasus->getY(), 300);
}

// создание случайных NPC
TEST(FactoryTest, CreateRandomNPCTest) {
    auto npcs = Factory::createRandomNPCs(50, 100, 100);
    ASSERT_EQ(npcs.size(), 50);

    for (const auto& npc : npcs) {
        EXPECT_TRUE(npc->getType() == "Knight" || npc->getType() == "Squirrel" || npc->getType() == "Pegasus");
        EXPECT_TRUE(npc->getX() >= 0 && npc->getX() < 100);
        EXPECT_TRUE(npc->getY() >= 0 && npc->getY() < 100);
    }
}

// ==================== Тесты BattleVisitor ====================

// боевой режим
TEST(VisitorTest, BattleExecutionTest) {
    std::vector<std::unique_ptr<NPC>> npcs;
    npcs.push_back(Factory::createNPC("Knight", "Oleg", 50, 50));
    npcs.push_back(Factory::createNPC("Squirrel", "Sandy", 100, 100));
    npcs.push_back(Factory::createNPC("Pegasus", "Hippie", 200, 200));

    BattleVisitor battleVisitor(150.0);

    ConsoleObserver consoleObserver;
    battleVisitor.addObserver(&consoleObserver);

    battleVisitor.execute(npcs);

    ASSERT_EQ(npcs.size(), 2);
    EXPECT_EQ(npcs[0]->getType(), "Knight");
    EXPECT_EQ(npcs[1]->getType(), "Pegasus");
}

// битва на большой дистанции (сражения не будет)
TEST(VisitorTest, NoBattleDueToDistanceTest) {
    std::vector<std::unique_ptr<NPC>> npcs;
    npcs.push_back(Factory::createNPC("Knight", "Arthur", 50, 50));
    npcs.push_back(Factory::createNPC("Squirrel", "Chippy", 400, 400));

    BattleVisitor battleVisitor(100.0); 

    ConsoleObserver consoleObserver;
    battleVisitor.addObserver(&consoleObserver);

    battleVisitor.execute(npcs);

    ASSERT_EQ(npcs.size(), 2);
    EXPECT_EQ(npcs[0]->getType(), "Knight");
    EXPECT_EQ(npcs[1]->getType(), "Squirrel");
}

// ==================== Тесты Observer ====================

// запись событий в лог-файл
TEST(ObserverTest, FileLogTest) {
    FileObserver fileObserver("test_log.txt");

    fileObserver.update("Knight Arthur defeated Squirrel Chippy");
    fileObserver.update("Squirrel Chippy defeated Pegasus Windy");

    std::ifstream logFile("test_log.txt");
    ASSERT_TRUE(logFile.is_open());

    std::string line;
    std::getline(logFile, line);
    EXPECT_EQ(line, "Knight Arthur defeated Squirrel Chippy");
    std::getline(logFile, line);
    EXPECT_EQ(line, "Squirrel Chippy defeated Pegasus Windy");

    logFile.close();
}

// вывод событий в консоль
TEST(ObserverTest, ConsoleLogTest) {
    ConsoleObserver consoleObserver;

    testing::internal::CaptureStdout(); // перехват вывода в консоль
    consoleObserver.update("Knight Arthur defeated Squirrel Chippy");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Knight Arthur defeated Squirrel Chippy\n");
}

// ==================== Тесты NPC ====================

// тест на передвижение NPC
TEST(NPCTest, MoveNPCTest) {
    auto knight = Factory::createNPC("Knight", "Arthur", 50, 50);
    knight->setPosition(60, 60);
    EXPECT_EQ(knight->getX(), 60);
    EXPECT_EQ(knight->getY(), 60);
}

// тест на убийство NPC
TEST(NPCTest, KillNPCTest) {
    auto knight = Factory::createNPC("Knight", "Arthur", 50, 50);
    knight->kill();
    EXPECT_FALSE(knight->isAlive());
}

// тест на расстояние хода и убийства
TEST(NPCTest, DistanceTest) {
    auto knight = Factory::createNPC("Knight", "Arthur", 50, 50);
    EXPECT_EQ(knight->getMoveDistance(), 30);
    EXPECT_EQ(knight->getKillDistance(), 10);

    auto squirrel = Factory::createNPC("Squirrel", "Chippy", 100, 100);
    EXPECT_EQ(squirrel->getMoveDistance(), 5);
    EXPECT_EQ(squirrel->getKillDistance(), 5);

    auto pegasus = Factory::createNPC("Pegasus", "Windy", 300, 300);
    EXPECT_EQ(pegasus->getMoveDistance(), 30);
    EXPECT_EQ(pegasus->getKillDistance(), 10);
}
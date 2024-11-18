#include "gtest/gtest.h"
#include "../include/Factory.hpp"
#include "../include/Visitor.hpp"
#include "../include/Observer.hpp"

// Подключение необходимых заголовков
#include <vector>
#include <memory>

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

// сохранение и загрузка NPC из файла
TEST(FactoryTest, SaveAndLoadNPCTest) {
    std::vector<std::unique_ptr<NPC>> npcs;
    npcs.push_back(Factory::createNPC("Knight", "Arthur", 50, 50));
    npcs.push_back(Factory::createNPC("Squirrel", "Chippy", 100, 100));
    npcs.push_back(Factory::createNPC("Pegasus", "Windy", 300, 300));

    const std::string filename = "test_npcs.txt";
    Factory::saveToFile(filename, npcs);

    auto loadedNPCs = Factory::loadFromFile(filename);
    ASSERT_EQ(loadedNPCs.size(), 3);
    EXPECT_EQ(loadedNPCs[0]->getType(), "Knight");
    EXPECT_EQ(loadedNPCs[1]->getType(), "Squirrel");
    EXPECT_EQ(loadedNPCs[2]->getType(), "Pegasus");
}

// ==================== Тесты BattleVisitor ====================

// боевой    режим
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

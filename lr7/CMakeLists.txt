cmake_minimum_required(VERSION 3.10)
project(lr7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем флаги компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

# Подключаем FetchContent для загрузки Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
  TLS_VERIFY false
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Добавляем исходные файлы
set(SOURCES
    src/NPC.cpp
    src/Factory.cpp
    src/Game.cpp
    main.cpp
)

# Добавляем библиотеку из исходных файлов
add_library(lr7_lib ${SOURCES})

# Указываем, что используем заголовочные файлы из директории include/
target_include_directories(lr7_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Добавляем исполняемый файл
add_executable(lr7 main.cpp)
target_link_libraries(lr7 lr7_lib)

# Добавляем исходные файлы для тестов
set(TEST_SOURCES
    test/tests.cpp
)

# Добавляем исполняемый файл для тестов
add_executable(lr7Tests ${TEST_SOURCES})

# Указываем, что используем заголовочные файлы из директории include/
target_include_directories(lr7Tests PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Линкуем тесты с библиотекой и Google Test
target_link_libraries(lr7Tests lr7_lib gtest_main gtest)

# Включаем тестирование
enable_testing()

# Добавляем тесты в систему тестирования (например, CTest)
add_test(NAME lr7Tests COMMAND lr7Tests)
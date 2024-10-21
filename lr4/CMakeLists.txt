cmake_minimum_required(VERSION 3.10)
project(lab4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление опций компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

# Установка Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
  TLS_VERIFY false
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Добавление библиотеки
add_library(lab4_lib
    src/figure.cpp
)

# Добавление путей к заголовочным файлам
target_include_directories(lab4_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)


# Создание исполняемого файла (main.cpp)
add_executable(lab4_exe main.cpp)

# Линковка библиотеки с исполняемым файлом
target_link_libraries(lab4_exe PRIVATE lab4_lib)

# Добавление тестов
enable_testing()

# Добавление тестов (test/test.cpp)
add_executable(lab4_tests test/test.cpp)
target_link_libraries(lab4_tests lab4_lib gtest_main)

# Добавление тестов в тестовый набор
add_test(NAME Lab4Tests COMMAND lab4_tests)
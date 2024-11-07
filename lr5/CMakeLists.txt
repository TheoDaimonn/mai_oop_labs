cmake_minimum_required(VERSION 3.10)
project(memory_resource_lab)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
  TLS_VERIFY false
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(memory_resource_lib
    src/memory_resource.cpp
    src/queue.cpp
)

target_include_directories(memory_resource_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(memory_resource_exe main.cpp)

target_link_libraries(memory_resource_exe PRIVATE memory_resource_lib)

enable_testing()

add_executable(memory_resource_tests test/tests.cpp)
target_link_libraries(memory_resource_tests memory_resource_lib gtest_main)

add_test(NAME MemoryResourceTests COMMAND memory_resource_tests)


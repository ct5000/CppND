cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(Capstone)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

file(GLOB project_SRCS src/*.cpp) #src/*.h

add_executable(Capstone ${project_SRCS})
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(Capstone ${SDL2_LIBRARIES})
cmake_minimum_required(VERSION 3.10)
project(Jackal)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
include_directories(data)
include_directories(include/events)
add_executable(Jackal main.cpp src/event.cpp src/game.cpp src/field.cpp src/player.cpp src/pirate.cpp)

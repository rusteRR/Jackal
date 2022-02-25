cmake_minimum_required(VERSION 3.10)
project(Jackal)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(include)
include_directories(data)
include_directories(include/events)

set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64")

find_package(Qt5Widgets REQUIRED)

add_executable(Jackal main.cpp src/event.cpp src/game.cpp src/field.cpp src/player.cpp src/pirate.cpp)

target_link_libraries(Jackal Qt5::Widgets)

cmake_minimum_required(VERSION 3.10)
project(JackalServer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "C://Qt//5.15.2//mingw81_64")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C://Qt//5.15.2//mingw81_64//bin")

find_package(Qt5Widgets REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)

include_directories(
        include
        src
        src/events
        include/events
)

set(SOURCE_LOGIC
        src/event.cpp
        src/field.cpp
        src/game.cpp
        src/pirate.cpp
        src/player.cpp
        src/settings.cpp
        src/ship.cpp
        src/handler.cpp
        src/events/fortress.cpp
        src/events/horse.cpp
        src/events/ice.cpp
        src/events/ogre.cpp
        src/events/simplePointer.cpp
        src/events/spinner.cpp
        src/events/coins.cpp
        src/events/rum.cpp
        src/events/water.cpp
        src/events/crocodile.cpp
        src/events/jungle.cpp
        src/events/balloon.cpp
        src/events/cannon.cpp
        src/events/treasure.cpp
        src/events/barrel.cpp
        src/events/multiPointer.cpp)

add_executable(JackalLogicOnly ../main.cpp ${SOURCE_LOGIC})
add_executable(JackalServer src/main.cpp include/server.h src/server.cpp src/thread.cpp include/thread.h ${SOURCE_LOGIC})
add_executable(LogicTest test/logic_test.cpp ${SOURCE_LOGIC})

target_link_libraries(JackalServer Qt5::Widgets)
target_link_libraries(JackalServer Qt5::Network)
target_link_libraries(JackalLogicOnly Qt5::Network)
target_link_libraries(LogicTest Qt5::Network)

cmake_minimum_required(VERSION 3.10)
project(JackalUI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "C://Qt//5.15.2//mingw81_64")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C://Qt//5.15.2//mingw81_64//bin")

set(CMAKE_SOURCE_DIR src)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)
include_directories(server/include server/src client/src client/include server/include/events client/include client/src)

set(HEADERS_CLIENT client/include/EventWidget.h client/include/FieldWidget.h client/include/MainMenuWidget.h client/include/client.h client/include/GameStartLabel.h client/include/ExitLabel.h client/include/PirateWidget.h client/include/ShipWidget.h client/include/PirateContainer.h client/include/contoller.h)
#set(HEADERS_LOGIC include/pirate.h include/ship.h include/events/simplePointer.h)
set(SOURCE_CLIENT client/src/main.cpp client/src/FieldWidget.cpp client/src/MainMenuWidget.cpp client/src/MainGame.cpp client/src/controller.cpp)
#set(SOURCE_LOGIC src/events/horse.cpp src/events/simplePointer.cpp src/events/spinner.cpp src/main.cpp src/event.cpp src/game.cpp src/field.cpp src/player.cpp src/pirate.cpp src/ship.cpp src/settings.cpp src/events/ice.cpp src/events/ogre.cpp src/events/fortress.cpp)

add_executable(JackalClient ${HEADERS_CLIENT} ${SOURCE_CLIENT})
#add_executable(JackalUI ${HEADERS_LOGIC} ${HEADERS_GUI} ${SOURCE_LOGIC} ${SOURCE_GUI})
target_link_libraries(JackalClient Qt5::Widgets)
target_link_libraries(JackalClient Qt5::Network)

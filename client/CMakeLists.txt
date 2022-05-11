cmake_minimum_required(VERSION 3.10)
project(JackalClient)

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
)

set(SOURCE_CLIENT
        src/main.cpp
        src/FieldWidget.cpp
        src/EventWidget.cpp
        src/MainMenuWidget.cpp
        src/MainGame.cpp
        src/controller.cpp
        src/client.cpp
        src/ShipWidget.cpp)

set(HEADERS_CLIENT
        include/client.h
        include/controller.h
        include/EventWidget.h
        include/ExitLabel.h
        include/FieldWidget.h
        include/GameStartLabel.h
        include/MainMenuWidget.h
        include/PirateWidget.h
        include/ShipWidget.h)

add_executable(JackalClient ${HEADERS_CLIENT} ${SOURCE_CLIENT})

target_link_libraries(JackalClient Qt5::Widgets)
target_link_libraries(JackalClient Qt5::Network)

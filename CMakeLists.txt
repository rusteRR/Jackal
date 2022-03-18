cmake_minimum_required(VERSION 3.10)
project(JackalUI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "C://Qt//5.15.2//mingw81_64")

set(CMAKE_SOURCE_DIR src)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5 COMPONENTS Widgets)
include_directories(include)
include_directories(src)
include_directories(data)
include_directories(include/events)
include_directories(include/gui)
set(HEADERS_GUI include/gui/EventWidget.h include/gui/FieldWidget.h include/gui/MainMenuWidget.h include/gui/MainGame.h include/gui/GameStartLabel.h include/gui/ExitLabel.h include/gui/PirateWidget.h include/gui/ShipWidget.h include/gui/PirateContainer.h)
set(HEADERS_LOGIC include/pirate.h include/ship.h include/events/simplePointer.h)
set(SOURCE_GUI src/EventWidget.cpp src/FieldWidget.cpp src/MainMenuWidget.cpp src/MainGame.cpp)
set(SOURCE_LOGIC src/events/horse.cpp src/events/simplePointer.cpp src/events/spinner.cpp src/main.cpp src/event.cpp src/game.cpp src/field.cpp src/player.cpp src/pirate.cpp src/ship.cpp src/settings.cpp)
add_executable(JackalUI ${HEADERS_LOGIC} ${HEADERS_GUI} ${SOURCE_LOGIC} ${SOURCE_GUI})
target_link_libraries(JackalUI Qt5::Widgets)

if (WIN32)
    set(DEBUG_SUFFIX)
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()

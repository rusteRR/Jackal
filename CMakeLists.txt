cmake_minimum_required(VERSION 3.10)
project(Jackal)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_subdirectory(server)
add_subdirectory(client)
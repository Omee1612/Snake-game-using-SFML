cmake_minimum_required(VERSION 3.27)
project(snakegame)

set(CMAKE_CXX_STANDARD 23)
include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)
add_executable(snakegame main.cpp
        Snake.h
        Snake.cpp)
target_link_libraries(snakegame sfml-graphics sfml-window)

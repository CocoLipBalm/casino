cmake_minimum_required(VERSION 4.2)
project(casino)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(casino
        deck.cpp
        deck.h
        Card.cpp
        Card.h
        main.cpp)

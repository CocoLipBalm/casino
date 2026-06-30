cmake_minimum_required(VERSION 4.2)
project(casino)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)

add_executable(casino
        deck.cpp
        deck.h
        Card.cpp
        Card.h
        main.cpp
        Hand.cpp
        Hand.h
        blackjack_controller.cpp
        blackjack_controller.h)

cmake_minimum_required(VERSION 3.12)
project(Lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab3 main.cpp Battleships.cpp Battleships.h
        externalLib/optionparser.h Gamer.h GamerTypes/ConsoleGamer.cpp GamerTypes/ConsoleGamer.h GamerTypes/RandomGamer.cpp
        GamerTypes/RandomGamer.h GamerTypes/OptimalGamer.cpp GamerTypes/OptimalGamer.h GameView.h
        ViewTypes/ConsoleView.cpp ViewTypes/ConsoleView.h Board.cpp Board.h)
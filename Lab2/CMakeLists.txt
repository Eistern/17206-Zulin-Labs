cmake_minimum_required(VERSION 3.10)
project(Lab2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Lab2 main.cpp Calc.cpp Calc.h basicCommands.cpp basicCommands.h basicCreators.h Parser.cpp Parser.h CommandExeptions.h cmdFactory.h)
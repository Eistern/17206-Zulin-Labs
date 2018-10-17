cmake_minimum_required(VERSION 3.10)
project(Lab1)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(googleLib/googletest)

include_directories(googleLib/googletest/googletest/include)
set(SOURCE_FILES Tests.cpp tritSet/Trit.cpp tritSet/tritSet.cpp)
add_executable(Lab1 ${SOURCE_FILES})
target_link_libraries(Lab1 gtest gtest_main)
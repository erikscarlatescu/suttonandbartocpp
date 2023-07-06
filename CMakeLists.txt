cmake_minimum_required(VERSION 3.25)
project(SuttonBarto)

set(CMAKE_CXX_STANDARD 17)

include_directories(/Users/eriksca/boost/boost_1_82_0)

add_executable(SuttonBarto main.cpp ch2/Exercise_2_5.cpp ch2/Exercise_2_5.h ch2/ArmedTestbed.cpp ch2/ArmedTestbed.h ch2/ArmedTestbedNonstationary.cpp ch2/ArmedTestbedNonstationary.h ch2/EpsilonGreedyAgent.cpp ch2/EpsilonGreedyAgent.h)

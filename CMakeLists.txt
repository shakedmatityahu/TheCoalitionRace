cmake_minimum_required(VERSION 3.23)
project(TheCoalitionRace)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)

add_executable(TheCoalitionRace
        include/Agent.h
        include/Graph.h
        include/JoinPolicy.h
        include/Parser.h
        include/Party.h
        include/SelectionPolicy.h
        include/Simulation.h
        src/Agent.cpp
        src/Graph.cpp
        src/main.cpp
        src/Parser.cpp
        src/Party.cpp
        src/Simulation.cpp
        json.hpp src/test.cpp)

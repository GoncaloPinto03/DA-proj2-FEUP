cmake_minimum_required(VERSION 3.25)
project(Proj2DA)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proj2DA src/main.cpp src/Manager.cpp src/Manager.h data_structures/Graph.h data_structures/Graph.cpp data_structures/VertexEdge.cpp data_structures/VertexEdge.h)

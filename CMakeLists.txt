cmake_minimum_required(VERSION 3.25)
project(Proj2DA)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proj2DA src/main.cpp  data_structures/Graph.h data_structures/Graph.cpp data_structures/VertexEdge.cpp data_structures/VertexEdge.h data_structures/UFDS.h data_structures/Heap.h data_structures/Heap.h src/Read_files.cpp src/Manager.cpp src/Manager.h data_structures/MutablePriorityQueue.h)

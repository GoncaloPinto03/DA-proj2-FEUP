#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "../data_structures/Graph.h"

using namespace std;
#ifndef PROJ2_READ_FILES_H
#define PROJ2_READ_FILES_H

class Read_files {
private:
    Graph graph;

public:
    Read_files();
    Read_files(int input);

    Graph get_graph();
    void read_extrafully(int input);
    void read_realworld(int input);
    void read_toygraphs(int input);
};

#endif //PROJ2_READ_FILES_H
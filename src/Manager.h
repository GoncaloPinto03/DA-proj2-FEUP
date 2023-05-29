#ifndef PROJ2DA_MANAGER_H
#define PROJ2DA_MANAGER_H

#include "../data_structures/Graph.h"
#include "../data_structures/VertexEdge.h"


class Manager {
public:

    Manager();

    Manager(int input);

    Graph graph;

    Graph getGraph();

    void readExtraFullyConnected(int input);

    void readToyGraphs(int input);

    void readRealWorld(int input);


};


#endif //PROJ2DA_MANAGER_H

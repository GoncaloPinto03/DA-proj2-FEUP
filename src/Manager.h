//
// Created by Gonçalo Pinto on 29/05/2023.
//

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "../data_structures/Graph.h"

#ifndef PROJ2DA_MANAGER_H
#define PROJ2DA_MANAGER_H


class Manager {
public:
    Manager();
    Graph get_graph();
    void set_graph(Graph newGraph);

    // 4.1
    void ex4_1();

    void tspBacktrackBruteforce(Vertex* current, double current_cost, int num_visited, double& min_cost, std::vector<Vertex *>& tsp_path);
    std::vector<Vertex *> tspBruteforce();


    void tsp();
    void tspBTRec(const unsigned int **dists, unsigned int n, unsigned int curIndex, unsigned int curDist, unsigned int curPath[], unsigned int &minDist, unsigned int path[]);
    unsigned int tspBT(const unsigned int **dists, unsigned int n, unsigned int path[]);



private:
    Graph graph;


    void tspBacktrackBruteforce(Vertex *current, double current_cost, int num_visited, double &min_cost,
                                vector<Vertex *> &tsp_path, vector<int> &current_path);
};


#endif //PROJ2DA_MANAGER_H

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
    void tspBacktrackBruteforce(Vertex* current, double current_cost, int num_visited, double& min_cost, std::vector<Vertex *>& tsp_path);
    void tspBruteforce();

    // 4.2
    std::vector<Vertex *> prim();
    std::vector<Vertex *> prim2();
    void primMST(vector<Edge*>& mst);
    void preorderTraversal(const vector<Edge*>& mst, Vertex* node, vector<bool>& visited,vector<int>& preorder);
    void findMinMSTAndPreorderTraversal(vector<int>& preorder);


private:
    Graph graph;
};


#endif //PROJ2DA_MANAGER_H

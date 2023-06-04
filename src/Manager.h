#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "../data_structures/Graph.h"

/**
 * @file Manager.h
 * @brief Defines the Manager class for handling the main functions of the project.
 */

#ifndef PROJ2DA_MANAGER_H
#define PROJ2DA_MANAGER_H

/**
 * @brief The Manager class processes the main functions.
 */
class Manager {
public:

    /**
     * @brief Construct a new Manager object
     */
    Manager();

    Graph graph; /**< The graph we are working with. */

    /**
     * @brief This function returns our graph.
     */
    Graph get_graph();

    /**
     * @brief This function sets our graph.
     * @param newGraph The new graph.
     */
    void set_graph(Graph newGraph);

    // 4.1
    /**
     * @brief This function is responsible for the Backtracking Algorithm (4.1).
     * @param current The current vertex.
     * @param current_cost The current cost.
     * @param num_visited The number of visited vertexes.
     * @param min_cost The minimum cost read.
     * @param tsp_path The vector of Vertex objects that represent the path being followed.
     */
    void tspBacktrack(Vertex* current, double current_cost, int num_visited, double& min_cost, std::vector<Vertex *>& tsp_path);

    /**
     * @brief This function calls the previous function tspBacktrack() and returns the final path, minimum cost and prints its time of execution.
     */
    void tspMain();

    // 4.2
    /**
     * @brief This function is responsible for the Triangular Approximation Heuristic Algorithm (4.2).
     */
    void triangular();
};

#endif //PROJ2DA_MANAGER_H

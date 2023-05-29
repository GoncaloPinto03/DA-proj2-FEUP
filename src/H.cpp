#include "Read_files.h"
#include "../data_structures/Graph.h"
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <list>
#include <set>
#include <fstream>
#include <sstream>
#include <string>

/*void Graph::tsp_backtrack(std::vector<int>& path, std::vector<bool>& visited, double &min_cost, double cost_so_far) {
    // Base case: if all vertices have been visited, check if the current cycle is a Hamiltonian cycle
    if (path.size() == vertices.size()) {
        // Check if the last vertex is adjacent to the starting vertex
        int start_vertex = path.front();
        int last_vertex = path.back();
        for (auto edge : vertices[last_vertex].adj) {
            if (edge.vertex == start_vertex) {
                // If it is, this is a Hamiltonian cycle; update the minimum cost if necessary
                double cycle_cost = cost_so_far + edge.distance;
                if (cycle_cost < min_cost) {
                    min_cost = cycle_cost;
                }
                break;
            }
        }
        return;
    }

    // Recursively consider all unvisited neighbors of the last vertex in the current path
    int last_vertex = path.back();
    for (auto edge : vertices[last_vertex].adj) {
        if (!visited[edge.vertex]) {
            // Add the next vertex to the current path
            path.push_back(edge.vertex);
            visited[edge.vertex] = true;
            // Recursively explore the updated path
            tsp_backtrack(path, visited, min_cost, cost_so_far + edge.distance);
            // Remove the last vertex from the path and mark it as unvisited for the next iteration
            path.pop_back();
            visited[edge.vertex] = false;
        }
    }
}

double Graph::triangularApproximation() {
    // Create the MST using Prim's algorithm
    std::vector<int> parent(vertices.size(), -1);
    primMST(parent);

    // Perform DFS traversal to obtain the order of visited cities
    std::vector<bool> visited(vertices.size(), false);
    std::vector<int> path;
    std::stack<int> cityStack;
    dfs(0, parent, visited, cityStack, path);

    // Print the order of visited cities
    std::cout << "Order of visited cities: ";
    for (int i = 0; i < path.size(); ++i) {
        std::cout << path[i];
        if (i != path.size() - 1)
            std::cout << " -> ";
    }
    std::cout << " -> 0"<< std::endl;

    double total_distance = calculateTotalDistance(path);

    return total_distance;
}
*/



//
// Created by Gonçalo Pinto on 29/05/2023.
//

#include "Manager.h"
#include "Read_files.h"
#include <iostream>
#include "vector"
#include "../data_structures/Graph.h"
#include "../data_structures/VertexEdge.h"

using namespace std;

Manager::Manager() {

}

Graph Manager::get_graph() {
    return this->graph;
}

void Manager::set_graph(Graph newGraph) {
    this->graph = newGraph;
}

void Manager::ex4_1() {

}
void Manager::tspBacktrackBruteforce(Vertex* current, double current_cost, int num_visited, double& min_cost, std::vector<Vertex *>& tsp_path) {
    if (num_visited == graph.getNumVertex()) {
        // refactor later (use dijkstra to find minimum between current and start[findVertex(0)])
        // for real world graphs use latitude and logitude for distance instead of dijkstra
        double cost = current_cost + current->getPath()->getWeight();
        if (cost < min_cost) {
            min_cost = cost;
            tsp_path.clear();
            tsp_path.push_back(current);
            //? id may not be needed
            for (Edge* e = current->getPath(); e->getSource()->getId() != graph.findVertex(0)->getId(); e = e->getSource()->getPath()) {
                tsp_path.push_back(e->getSource());
            }

            std::reverse(tsp_path.begin(), tsp_path.end());
        }
        return;
    }

    for (Edge* e: current->getAdj()) { // may need refactor
        Vertex* w = e->getDest();
        if (!w->isVisited()) {
            w->setVisited(true);
            w->setPath(e);
            tspBacktrackBruteforce(w, current_cost + e->getWeight(), num_visited + 1, min_cost, tsp_path);
            w->setVisited(false);
            w->setPath(nullptr);
        }
    }
}

std::vector<Vertex *> Manager::tspBruteforce() {
    std::vector<Vertex *> tsp_path;

    for (auto& v: graph.getVertexSet()) {
        v->setVisited(false);
        v->setPath(nullptr);
    }

    double min_cost = std::numeric_limits<double>::max();

    auto init = graph.findVertex(0);
    init->setVisited(true);
    tspBacktrackBruteforce(init, 0, 1, min_cost, tsp_path);

    return tsp_path;
}




void Manager::tspBTRec(const unsigned int **dists, unsigned int n, unsigned int curIndex, unsigned int curDist, unsigned int curPath[], unsigned int &minDist, unsigned int path[]) {
    if(curIndex == n) {
        // add the distance back to the initial node
        curDist += dists[curPath[n - 1]][curPath[0]];
        if(curDist < minDist) {
            minDist = curDist;
            // Copy the current state to the array storing the best state found so far
            for(unsigned int i = 0; i < n; i++) {
                path[i] = curPath[i];
            }
        }
        return;
    }
    // Try to move to the i-th vertex if the total distance does not exceed the best distance found and the vertex is not yet visited in curPath
    for(unsigned int i = 1; i < n; i++) { // i starts at 1 and not 0 since it is assumed that node 0 is the initial node so it will not be in the middle of the path
        if(curDist + dists[curPath[curIndex - 1]][i] < minDist) {
            bool isNewVertex = true;
            for(unsigned int j = 1; j < curIndex; j++) {
                if(curPath[j] == i) {
                    isNewVertex = false;
                    break;
                }
            }
            if(isNewVertex) {
                curPath[curIndex] = i;
                tspBTRec(dists,n,curIndex+1,curDist + dists[curPath[curIndex - 1]][curPath[curIndex]],curPath,minDist,path);
            }
        }
    }
}

unsigned int Manager::tspBT(const unsigned int **dists, unsigned int n, unsigned int path[]) {
    unsigned int curPath[10000]; // static memory allocation is faster :)
    unsigned int minDist = std::numeric_limits<unsigned int>::max();

    // Assumes path starts at node 0 ...
    curPath[0] = 0;
    // ... so in the first recursive call curIndex starts at 1 rather than 0
    tspBTRec(dists, n, 1, 0, curPath, minDist, path);
    return minDist;
}


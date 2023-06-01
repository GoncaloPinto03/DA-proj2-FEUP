#include "Manager.h"
#include "Read_files.h"
#include <iostream>
#include "vector"
#include <limits>
#include "../data_structures/Graph.h"
#include "../data_structures/VertexEdge.h"
#include "../data_structures/MutablePriorityQueue.h"

using namespace std;

Manager::Manager() {

}

Graph Manager::get_graph() {
    return this->graph;
}

void Manager::set_graph(Graph newGraph) {
    this->graph = newGraph;
}

// 4.1
void Manager::tspBacktrackBruteforce(Vertex* current, double current_cost, int num_visited, double& min_cost, std::vector<Vertex *>& tsp_path) {

    bool vi=false;
    double costt=0;
    if (num_visited == graph.getNumVertex()) {

        for(Edge* e: current->getAdj()){
            Vertex* w = e->getDest();
            if(w==graph.findVertex(0)){
                costt = e->getWeight();
                vi=true;
            }

        }

        if(vi==false) return;

        double cost = current_cost + costt;
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

    for (Edge* e: current->getAdj()) {
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

// 4.1
void Manager::tspBruteforce() {

    clock_t start = clock();

    std::vector<Vertex *> tsp_path;

    for (auto& i: graph.getVertexSet()) {
        i.second->setVisited(false);
        i.second->setPath(nullptr);
    }

    double min_cost = std::numeric_limits<double>::max();

    auto init = graph.findVertex(0);

    init->setVisited(true);

    tspBacktrackBruteforce(init, 0, 1, min_cost, tsp_path);

    cout << "Minimum Cost: "<< min_cost << endl;

    clock_t end = clock();

    cout << '0'<< " -> ";

    for (auto e : tsp_path) {
        cout << e->getId() << " -> ";
    }
    cout << '0' << endl;

    cout << "Execution Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
}

// 4.2
void Manager::triangular() {
    clock_t start = clock();
    double total  = this->graph.triangularApproximation();
    clock_t end = clock();

    cout << "Triangular Approximation: " << total << endl;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
}

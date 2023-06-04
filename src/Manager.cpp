#include "Manager.h"
#include "Read_files.h"
#include <iostream>
#include "vector"
#include <limits>

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
void Manager::tspBacktrack(Vertex* current_vertex, double current_cost, int num_visited, double& min_cost, std::vector<Vertex *>& tsp_path) {

    bool vi = false;
    double costt = 0;

    if (num_visited == graph.getNumVertex()) {

        for(Edge* edge: current_vertex->getAdj()){
            Vertex* w = edge->getDest();

            if(w==graph.findVertex(0)){
                costt = edge->getWeight();
                vi=true;
            }
        }

        if(vi==false) return;

        double cost = current_cost + costt;

        if (cost < min_cost) {

            min_cost = cost;
            tsp_path.clear();
            tsp_path.push_back(current_vertex);

            for (Edge* e = current_vertex->getPath(); e->getSource()->getId() != graph.findVertex(0)->getId(); e = e->getSource()->getPath()) {
                tsp_path.push_back(e->getSource());
            }

            std::reverse(tsp_path.begin(), tsp_path.end());
        }
        return;
    }

    for (Edge* edge: current_vertex->getAdj()) {

        Vertex* w = edge->getDest();

        if (!w->isVisited()) {
            w->setVisited(true);
            w->setPath(edge);
            tspBacktrack(w, current_cost + edge->getWeight(), num_visited + 1, min_cost, tsp_path);
            w->setVisited(false);
            w->setPath(nullptr);
        }
    }
}

// 4.1
void Manager::tspMain() {

    clock_t start = clock();

    std::vector<Vertex *> tsp_path;

    for (auto& i: graph.getVertexSet()) {
        i.second->setVisited(false);
        i.second->setPath(nullptr);
    }

    double min_cost = std::numeric_limits<double>::max();

    auto init = graph.findVertex(0);

    init->setVisited(true);

    tspBacktrack(init, 0, 1, min_cost, tsp_path);

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
    this->graph.triangularApproximationHeuristic();
    clock_t end = clock();

    //cout << "Triangular Approximation: " << total << endl;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
}

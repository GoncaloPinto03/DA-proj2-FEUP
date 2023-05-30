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
        bool vi=false;
        double costt=0;
        for(Edge* e: current->getAdj()){
            if(e->getDest()->getId()==0){
                vi=true;
                costt  += e->getWeight();
                break;
            }

        }
        if(vi==false) return;

         /*if (!vi) {
            dijkstra(current);
            cost += findVertex(0)->getDistance(); // use dijkstra to get the distance between current and 0
            // for real world graph use latitude and longitude (maybe haversine algorithm)
        }*/

        double cost = current_cost + costt;
        if (cost < min_cost) {
            min_cost = cost;
            tsp_path.clear();
            tsp_path.push_back(current);
            //? id may not be needed
            for (Edge* e = current->getPath(); e->getSource()->getId() != graph.findVertex(0)->getId(); e = e->getSource()->getPath()) {
                tsp_path.push_back(e->getSource());
            }

            std::reverse(tsp_path.begin(), tsp_path.end()-1);


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

double Manager::tspBruteforce() {
    std::vector<Vertex *> tsp_path;

    for (auto& v: graph.getVertexSet()) {
        v->setVisited(false);
        v->setPath(nullptr);
    }

    double min_cost = std::numeric_limits<double>::max();

    auto init = graph.findVertex(0);
    init->setVisited(true);
    tspBacktrackBruteforce(init, 0, 1, min_cost, tsp_path);

    return min_cost;
}





/*
int Graph::getNumVertex() const {
    return this->vertexSet.size();
}

std::vector<Vertex *> Graph::getVertexSet() const {
    return this->vertexSet;
}*/





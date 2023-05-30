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

    cout << min_cost << endl;

    return tsp_path;

}

// 4.2
void Manager::primMST(vector<Edge*>& mst) {
    int V = graph.getNumVertex();

    // Priority queue to store edges with minimum weight
    priority_queue<Edge*, vector<Edge*>, CompareWeight> pq;

    // Start with vertex 0 as the source
    Vertex* source = graph.findVertex(0);

    // Create a vector to track visited vertices
    vector<bool> visited(V, false);

    // Add the edges connected to the source vertex to the priority queue
    for (const auto& edge : source->getAdj()) {
        if (edge->getSource() == source)
            pq.push(edge);
    }

    visited[source->getId()] = true;

    while (!pq.empty()) {
        Edge* edge = pq.top();
        pq.pop();

        Vertex* u = edge->getSource();
        Vertex* v = edge->getDest();

        if (visited[v->getId()])
            continue;

        visited[v->getId()] = true;

        mst.push_back(edge);

        for (const auto& neighbor : graph.getVertexSet()) {
            if (neighbor == v) {
                for (auto edge : neighbor->getAdj()){
                    if(!visited[edge->getDest()->getId()]){
                        pq.push(edge);
                    }
                }
            }
        }
    }
}

// 4.2
// Function to perform preorder traversal of MST
void Manager::preorderTraversal(const vector<Edge*>& mst, Vertex* node, vector<bool>& visited,vector<int>& preorder) {
    visited[node->getId()] = true;
    cout << node->getId() << " ";
    preorder.push_back(node->getId());

    for (const auto& edge : mst) {
        if (edge->getSource() == node && !visited[edge->getDest()->getId()])
            preorderTraversal(mst, edge->getDest(), visited,preorder);
    }
}

// 4.2
// Function to find the minimum spanning tree and perform preorder traversal
void Manager::findMinMSTAndPreorderTraversal(vector<int>& preorder) {
    vector<Edge*> mst;
    primMST(mst);

    cout << "Minimum Spanning Tree (MST) connections:" << endl;
    for (const auto& edge : mst) {
        cout << edge->getSource()->getId() << " -> " << edge->getDest()->getId() << " Distance: " << edge->getWeight() << endl;
    }

    cout << "Preorder Traversal of MST (Left to Right): ";
    vector<bool> visited(graph.getNumVertex(), false);
    preorderTraversal(mst, mst[0]->getSource(), visited,preorder);
    cout << endl;
}







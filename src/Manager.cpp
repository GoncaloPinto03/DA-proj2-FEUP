//
// Created by Gonçalo Pinto on 29/05/2023.
//

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

    for (auto& v: graph.getVertexSet()) {
        v->setVisited(false);
        v->setPath(nullptr);
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
 /*
std::vector<Vertex *> Manager::prim2() {
    if (graph.getVertexSet2().empty()) {
        return this->graph.getVertexSet2();
    }

    // Reset auxiliary info
    for(auto v : graph.getVertexSet2()) {
        v->setDist(std::numeric_limits<int>::max());
        v->setPath(nullptr);
        v->setVisited(false);
    }

    // start with an arbitrary vertex
    Vertex* s = graph.getVertexSet2().front();
    s->setDist(0);

    // initialize priority queue
    MutablePriorityQueue<Vertex> q;
    q.insert(s);
    // process vertices in the priority queue
    while( ! q.empty() ) {
        auto v = q.extractMin();
        v->setVisited(true);
        for(auto &e : v->getAdj()) {
            Vertex* w = e->getDest();
            if (!w->isVisited()) {
                auto oldDist = w->getDist();
                if(e->getWeight() < oldDist) {
                    w->setDist(e->getWeight());
                    w->setPath(e);
                    if (oldDist == std::numeric_limits<int>::max()) {
                        q.insert(w);
                    }
                    else {
                        q.decreaseKey(w);
                    }
                }
            }
        }
    }

    return this->graph.getVertexSet2();
}
*/

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

        if (visited[v->getId()] && visited[u->getId()])
            continue;

        visited[v->getId()] = true;
        visited[u->getId()] = true;

        if (edge->getSource()->isVisited() && edge->getDest()->isVisited())
            continue;
        else
            mst.push_back(edge);

        for (auto edge : v->getAdj()){
            if(!visited[edge->getDest()->getId()]){
                pq.push(edge);
            }
        }
    }
}

// 4.2
// Function to perform preorder traversal of MST
void Manager::preorderTraversal(const vector<Edge *> &mst, Vertex *node, vector<bool> &visited, vector<int> &preorder) {
    visited[node->getId()] = true;
    cout << node->getId() << " ";
    preorder.push_back(node->getId());

    /*
    vector<int> aux;
    for (const auto& edge : mst) {
        if (edge->getSource() == node)
            aux.push_back(edge->getDest()->getId());
            //preorderTraversal(mst, edge->getDest(), visited,preorder);
    }
    double min_cost = std::numeric_limits<int>::max();
    for (auto i : aux) {
        auto v = graph.findVertex(i);
        for (auto e : v->getAdj()) {
            if (e->getWeight() < min_cost)
                min_cost = e->getWeight();
        }
    }
     */

    for (const auto& edge : mst) {
        if (edge->getSource() == node && !visited[edge->getDest()->getId()])
            preorderTraversal(mst, edge->getDest(), visited,preorder);
    }

}

// 4.2
// Function to find the minimum spanning tree and perform preorder traversal
void Manager::findMinMSTAndPreorderTraversal(vector<int>& preorder) {

    clock_t start = clock();

    vector<Edge*> mst;
    primMST(mst);

    cout << "Preorder Traversal of MST (Left to Right): ";
    vector<bool> visited(graph.getNumVertex(), false);
    preorderTraversal(mst, mst[0]->getSource(), visited,preorder);
    cout << endl;

    double total_dist = 0;
    /*
    for (const auto& i : preorder) {
        for (auto e : graph.findVertex(i)->getAdj()) {
            if (e->getDest()->getId() == preorder[i + 1]) {
                total_dist += e->getWeight();
            }
        }
    }
     */


    //preorder.push_back(0);
    for (int i =0 ; i < preorder.size() - 1;i++) {
        for (auto e : graph.findVertex(i)->getAdj()) {
            if (e->getDest()->getId() == preorder[i + 1]) {
                total_dist += e->getWeight();
            }
        }
    }

    cout << "Total Distance: "<< total_dist << endl;
    clock_t end = clock();
    cout << "Execution Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

}







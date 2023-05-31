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

void Manager::TSP_TriangularApproximation(Graph* Graph) {
    vector<Vertex *> nodes;
    vector<Edge *> edges;
    for (auto vertex: Graph->getVertexSet()) {
        nodes.push_back(vertex);
        for (auto edge: vertex->getAdj()) {
            edges.push_back(edge);
        }
    }
    int num_nodes = nodes.size();

    for (auto node: nodes) {
        node->setVisited(false);
    }

    Vertex *start_node = Graph->findVertex(0);
    start_node->setVisited(true);

    vector<Vertex *> path;
    path.push_back(start_node);

    vector<tuple<int, int>> pathShow;
    int orig_path;

    vector<int> visited_nodes;
    visited_nodes.push_back(start_node->getId());

    double total_distance = 0.0;

    while (visited_nodes.size() < num_nodes) {
        double min_distance = 999999.0;
        Vertex *next_node = nullptr;

        Vertex *curr_node = path.back();
        curr_node->setVisited(true);

        for (Edge *edge: curr_node->getAdj()) {
            if (!edge->getDest()->isVisited()) {
                double distance = edge->getWeight();
                if (distance < min_distance) {
                    orig_path = curr_node->getId();
                    min_distance = distance;
                    next_node = edge->getDest();
                }
            }
        }

        if (next_node == nullptr) {
            pathShow.push_back(make_tuple(path.back()->getId(), path[path.size() - 2]->getId()));
            for (auto e: path.back()->getAdj()) {
                if (e->getDest() == path[path.size() - 2]) {
                    total_distance += e->getWeight();
                    break;
                }
            }
            path.pop_back();
        } else {
            pathShow.push_back(make_tuple(orig_path, next_node->getId()));
            path.push_back(next_node);
            visited_nodes.push_back(next_node->getId());
            total_distance += min_distance;
        }
    }

    for (auto e: path.back()->getAdj()) {
        if (e->getDest() == start_node) {
            total_distance += e->getWeight();
            pathShow.push_back(make_tuple(path.back()->getId(), start_node->getId()));
        }
    }

    cout << "Approximated minimum weight: " << total_distance << std::endl;
    for (auto p: pathShow) {
        if (p == pathShow.back()) cout << get<0>(p) << " -> " << get<1>(p) << " ";
        else cout << get<0>(p) << " -> " << get<1>(p) << " | ";
    }
    cout << std::endl;
}
/*
    void Manager::primMST(vector<Edge *> &mst) {

        int V = graph.getNumVertex();

        // Priority queue to store edges with minimum weight
        priority_queue<Vertex *, vector<Vertex *>> pq;

        // Start with vertex 0 as the source
        Vertex *source = graph.findVertex(0);

        // Create a vector to track visited vertices
        vector<bool> visited(V, false);

        vector<Edge *> edges;

        // Add the edges connected to the source vertex to the priority queue
        for (const auto &vertex: graph.getVertexSet()) {
            pq.push(vertex);
            for (auto edge: vertex->getAdj()) {
                edges.push_back(edge);
            }
        }

        //visited[source->getId()] = true;

        double min_cost_edge = INT_MAX;
        while (!pq.empty()) {

            Vertex *vertex = pq.top();
            visited[vertex->getId()] = true;
            pq.pop();


            Vertex *u = edge->getSource();
            Vertex *v = edge->getDest();

            if (visited[v->getId()] && visited[u->getId()])
                continue;

            visited[v->getId()] = true;
            visited[u->getId()] = true;

            if (edge->getSource()->isVisited() && edge->getDest()->isVisited())
                continue;
            else
                mst.push_back(edge);

            for (auto edge: v->getAdj()) {
                if (!visited[edge->getDest()->getId()]) {
                    pq.push(edge);
                }
            }


            for (auto edge: vertex->getAdj()) {
                if (edge->getWeight() < min_cost_edge)
                    min_cost_edge = edge->getWeight();
            }

            for (auto edge: vertex->getAdj()) {
                if (edge->getWeight() == min_cost_edge) {
                    mst.push_back(edge);
                    break;
                }
            }
            min_cost_edge = INT_MAX;
        }
    }

// 4.2
// Function to perform preorder traversal of MST
    void
    Manager::preorderTraversal(const vector<Edge *> &mst, Vertex *node, vector<bool> &visited, vector<int> &preorder) {
        visited[node->getId()] = true;
        cout << node->getId() << " ";
        preorder.push_back(node->getId());

        for (const auto &edge: mst) {
            if (edge->getSource() == node && !visited[edge->getDest()->getId()])
                preorderTraversal(mst, edge->getDest(), visited, preorder);
        }

    }

// 4.2
// Function to find the minimum spanning tree and perform preorder traversal
    void Manager::findMinMSTAndPreorderTraversal(vector<int> &preorder) {

        clock_t start = clock();

        vector<Edge *> mst;
        primMST(mst);

        cout << "Preorder Traversal of MST (Left to Right): ";
        vector<bool> visited(graph.getNumVertex(), false);
        preorderTraversal(mst, mst[0]->getSource(), visited, preorder);
        cout << endl;

        double total_dist = 0;

        for (const auto &i: preorder) {
            for (auto e: graph.findVertex(i)->getAdj()) {
                if (e->getDest()->getId() == preorder[i + 1]) {
                    total_dist += e->getWeight();
                }
            }
        }


        cout << "Total Distance: " << total_dist << endl;
        clock_t end = clock();
        cout << "Execution Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    }


*/
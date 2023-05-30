
#include <iostream>
#include "Read_files.h"
#include "Manager.h"
#include "../data_structures/Graph.h"




int main() {
    Read_files readfiles = Read_files();
    Manager manager = Manager();
    Graph graph1=Graph();
    readfiles.read_toygraphs(1);
    //readfiles.read_extrafully(2);

    Graph graph = readfiles.get_graph();
    manager.set_graph(graph);


    /*for (auto itr : graph.getVertexSet()) {
        cout << itr->getAdj().size()<<"//";
    }

    for (auto vertex: graph.getVertexSet()) {
        for(auto edge : vertex->getAdj()){
            cout << edge->getSource()->getId() << " -> " << edge->getDest()->getId() << " " << edge->getWeight()<<endl;
        }
    }*/
    /*std::vector<Vertex *> tsp_path;
    auto v = graph.tspBruteforce();
    for (auto e : v) {
        cout << e->getId() << " -> ";
    }
    cout << endl;
*/
    std::vector<Vertex *> tsp_path;
    double cost = graph1.tspBruteforce(tsp_path);

    std::cout << "Path: ";
    for (Vertex* v: tsp_path) {
        std::cout << v->getId() << " -> ";
    }
    std::cout << '\n';
    std::cout << "Cost: " << cost << '\n';


    return 0;
}

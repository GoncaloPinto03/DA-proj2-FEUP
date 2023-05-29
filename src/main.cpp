
#include <iostream>
#include "Read_files.h"
#include "Manager.h"




int main() {
    Read_files readfiles = Read_files();
    Manager manager = Manager();
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



    auto v = manager.tspBruteforce();

    for (auto itr2 : v) {
        cout << itr2->getId()<<' ';
    }

    return 0;
}

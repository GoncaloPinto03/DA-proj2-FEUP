
#include <iostream>
#include "Read_files.h"
#include "Manager.h"




int main() {
    Read_files readfiles = Read_files();
    Manager manager = Manager();
    readfiles.read_toygraphs(3);
    //manager.read_extrafully(11);

    Graph graph = readfiles.get_graph();
    manager.set_graph(graph);

    /*
    for (auto itr : graph.getVertexSet()) {
        cout << itr->getId()<<endl;
    }
     */

    auto v = manager.tspBruteforce();

    for (auto itr2 : v) {
        cout << itr2->getId()<<endl;
    }






    return 0;
}

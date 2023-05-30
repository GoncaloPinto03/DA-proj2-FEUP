
#include <iostream>
#include "Read_files.h"
#include "Manager.h"




int main() {
    Read_files readfiles = Read_files();
    Manager manager = Manager();
    readfiles.read_toygraphs(3);
    //readfiles.read_extrafully(2);

    Graph graph = readfiles.get_graph();
    manager.set_graph(graph);

    std::vector<Vertex *> tsp_path;
    auto v = manager.tspBruteforce();
    cout << '0'<< " -> ";

    for (auto e : v) {
        cout << e->getId() << " -> ";
    }
    cout << '0';




    return 0;
}

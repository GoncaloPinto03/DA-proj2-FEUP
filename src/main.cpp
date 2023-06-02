#include <iostream>
#include "Read_files.h"
#include "Manager.h"
#include "vector"

int main() {

    Read_files readfiles = Read_files();
    Manager manager = Manager();

    //readfiles.read_extrafully(12);
    //readfiles.read_realworld(2);
    readfiles.read_toygraphs(2);

    Graph graph = readfiles.get_graph();
    manager.set_graph(graph);

    // 4.1
    //manager.tspBruteforce();

    // 4.2
    manager.triangular();

    return 0;
}

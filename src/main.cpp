
#include <iostream>
#include "Read_files.h"
#include "Manager.h"
#include "vector"




int main() {
    Read_files readfiles = Read_files();
    Manager manager = Manager();
    readfiles.read_toygraphs(1);
    //readfiles.read_extrafully(2);

    Graph graph = readfiles.get_graph();
    manager.set_graph(graph);

    // 4.1
    //manager.tspBruteforce();

    // 4.2
    vector<int> preorder;
    manager.findMinMSTAndPreorderTraversal(preorder);




    return 0;
}

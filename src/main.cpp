
#include <iostream>
#include "Read_files.h"
#include "Manager.h"
#include "vector"




int main() {
    Read_files readfiles = Read_files();
    Manager manager = Manager();
    //readfiles.read_toygraphs(2);

    clock_t start = ::clock();
    readfiles.read_realworld(2);
    clock_t end = ::clock();

    cout << (double)(end-start)/CLOCKS_PER_SEC << endl;



    Graph graph = readfiles.get_graph();
    manager.set_graph(graph);

    // 4.1
    //manager.tspBruteforce();

    // 4.2
    vector<int> preorder;
    //manager.findMinMSTAndPreorderTraversal(preorder);
    //manager.TSP_TriangularApproximation(&graph);




    return 0;
}

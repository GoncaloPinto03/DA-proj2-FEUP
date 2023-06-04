#include <iostream>
#include "Read_files.h"
#include "Manager.h"
#include "menu.h"

int main() {

    
    Menu menu;
    bool run = true;
    while (run) {
        run = menu.nextState(0);
    }

    /*

    Read_files readfiles = Read_files();
    Manager manager = Manager();

    //readfiles.read_extrafully(1);
    //eadfiles.read_realworld(3);

    readfiles.read_toygraphs(2);


    Graph graph = readfiles.get_graph();
    manager.set_graph(graph);

    // 4.1
    //manager.tspBruteforce();

    // 4.2
    //manager.triangular();

    // 4.3
    //manager.ourHeuristic();

    */

    return 0;
}
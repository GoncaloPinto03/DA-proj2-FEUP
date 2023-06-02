#include <iostream>
#include "Read_files.h"
#include "Manager.h"
#include "menu.h"

int main() {
    Read_files readfiles = Read_files();
    Manager manager = Manager();

    Graph graph = readfiles.get_graph();
    manager.set_graph(graph);

    Menu menu;
    bool run = true;
    while (run) {
        run = menu.nextState(0);
    }

    return 0;
}
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

    //Vertex* initialNode, Vertex* currentNode, vector<Edge*>& path, int graphSize, double distance
    auto initialNode = manager.graph.getVertexSet()[0];
    auto currentNode = manager.graph.getVertexSet()[0];
    vector<Edge*> path;
    int graphSize = manager.graph.getNumVertex();
    double distance = 0;
    manager.graph.nearestNeighbor(initialNode, currentNode, path, graphSize,distance);

    */

    return 0;
}
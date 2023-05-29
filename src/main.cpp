
#include <iostream>
#include "Read_files.h"




int main() {
    Read_files manager = Read_files();
    manager.read_toygraphs(1);
    //manager.read_extrafully(3);

    Graph graph = manager.get_graph();

    for (auto itr : graph.getVertexSet()) {
        cout << itr->getId()<<endl;
    }





    return 0;
}

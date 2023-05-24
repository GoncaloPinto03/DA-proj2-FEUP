#include <limits>
#include "menu.h"
#include "auxiliar.h"
#include "Manager.h"
#include "../data_structures/Graph.h"
#include "../data_structures/Heap.h"
#include "../data_structures/MutablePriorityQueue.h"
#include "../data_structures/UFDS.h"
#include "../data_structures/VertexEdge.h"
using namespace std;

void Menu::mainMenu() {
    title("Main Menu");
    showMenu(menuOptions);

    int key = getInt("Choose an option");
    while (key < 1 || key > 4) key = getInt("Not a valid option. Choose a valid option.");

    switch (key) {
        case 1:
            state = 1;
            break;
        case 2:
            state = 2;
            break;
        case 3:
            state = 3;
            break;
        default:
            state = 4;
    }
}

bool Menu::nextState(vector<Network> &networks, vector<Station> &stations) {
    clearSCR();
    std::string option;
    switch (state) {
        case 0:
            mainMenu();
            return true;
        case 1:
            first(networks, stations);
            state = 4;
            return true;
        case 2:
            second(networks, stations);
            state = 4;
            return true;
        case 3:
            third(networks, stations);
            state = 4;
            return true;
        default:
            return false;
    }}

void Menu::first(vector<Network> &networks, vector<Station> &stations) {
    Manager manager = Manager();
    manager.read_stations(stations);
    manager.read_networks(networks);

    Graph graph = manager.graph;

    for (auto v : manager.graph.getVertexSet()) {
        double cap = 0;
        for (auto e : v->getAdj()) {
            cap += e->getWeight();
        }
        v->setCapacity(cap);
    }

    manager.maxTrainBetweenStations(manager.graph);

    cout << "Thanks for using our program!" << endl;
    cout << "Click Enter!";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}

void Menu::second(vector<Network> &networks, vector<Station> &stations) {
    Manager manager = Manager();
    manager.read_stations(stations);
    manager.read_networks(networks);

    Graph graph = manager.graph;

    for (auto v : manager.graph.getVertexSet()) {
        double cap = 0;
        for (auto e : v->getAdj()) {
            cap += e->getWeight();
        }
        v->setCapacity(cap);
    }

    manager.maxTrainBetweenStationsPairs();

    cout << "Thanks for using our program!" << endl;
    cout << "Click Enter!";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}

void Menu::third(vector<Network> &networks, vector<Station> &stations) {
    Manager manager = Manager();
    manager.read_stations(stations);
    manager.read_networks(networks);

    Graph graph = manager.graph;

    for (auto v : manager.graph.getVertexSet()) {
        double cap = 0;
        for (auto e: v->getAdj()) {
            cap += e->getWeight();
        }
        v->setCapacity(cap);
    }

    manager.managementByMunicipalities();

    cout << "Thanks for using our program!" << endl;
    cout << "Click Enter!";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}

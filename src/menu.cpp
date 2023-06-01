#include <limits>
#include "menu.h"
#include "auxiliar.h"
#include "Manager.h"
#include "Read_files.h"
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

bool Menu::nextState(int key) {
    Read_files readfiles = Read_files();
    clearSCR();

    std::string option;
    switch (state) {
        case 0:
            mainMenu();
            return true;
        case 1:
            firstOption();
            return true;
        case 2:
            secondOption();
            return true;
        case 3:
            state = 5;
            return true;
        case 4:
            second();
            state = 5;
            return true;
        default:
            return false;
    }
}

void Menu::firstOption() {
    Read_files readfiles = Read_files();
    Manager manager = Manager();

    Graph graph = readfiles.get_graph();
    manager.set_graph(graph);

    title("Choose the number of the file you wish to run (1-3).");
    showMenu(firstOptions);

    int key = getInt("Choose an option.");
    while (key < 1 || key > 3) {
        key = getInt("Not a valid option. Choose a valid option.");
    }

    readfiles.read_toygraphs(key);

    manager.tspBruteforce();

    cout << "Thanks for using our program!" << endl;
    cout << "Click Enter!";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}

bool Menu::secondOption() {
    Read_files readfiles = Read_files();
    title("Choose the folder of files you wish to test:");
    showMenu(secondOptions);

    int key = getInt("Choose an option");
    while (key < 1 || key > 3) {
        key = getInt("Not a valid option. Choose a valid option.");
    }

    switch (key) {
        case 1:
            readfiles.read_extrafully(key);
            state = 4;
            return true;
        case 2:
            readfiles.read_realworld(key);
            state = 4;
            return true;
        case 3:
            readfiles.read_toygraphs(key);
            state = 4;
            return true;
        default:
            return false;
    }
}

void Menu::second() {
    Read_files readfiles = Read_files();
    Manager manager = Manager();

    Graph graph = readfiles.get_graph();
    manager.set_graph(graph);

    manager.triangular();

    cout << "Thanks for using our program!" << endl;
    cout << "Click Enter!";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}

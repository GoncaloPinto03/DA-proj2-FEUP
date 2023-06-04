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
            state = 7;
            return true;
        case 2:
            secondOption();
            return true;
        case 3:
            state = 7;
            return true;
        case 4:
            first();
            state = 7;
            return true;
        case 5:
            second();
            state = 7;
            return true;
        case 6:
            third();
            state = 7;
            return true;
        default:
            return false;
    }
}

void Menu::firstOption() {
    title("Choose the number of the file you wish to run.");
    showMenu(firstOptions);

    int key = getInt("Choose an option.");
    while (key < 1 || key > 3) {
        key = getInt("Not a valid option. Choose a valid option.");
    }

    Read_files readfiles = Read_files();
    Manager manager = Manager();

    readfiles.read_toygraphs(key);

    Graph graph = readfiles.get_graph();
    manager.set_graph(graph);

    manager.tspMain();

    cout << "Thanks for using our program!" << endl;
    cout << "Click Enter!";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}

bool Menu::secondOption() {
    title("Choose the folder of files you wish to test:");
    showMenu(secondOptions);

    int key = getInt("Choose an option");
    while (key < 1 || key > 3) {
        key = getInt("Not a valid option. Choose a valid option.");
    }

    switch (key) {
        case 1:
            state = 4;
            return true;
        case 2:
            state = 5;
            return true;
        case 3:
            state = 6;
            return true;
        default:
            return false;
    }
}

void Menu::first() {
    title("Choose the number of the file you wish to run.");
    showMenu(thirdOptions);

    int key = getInt("Choose an option.");
    while (key < 1 || key > 12) {
        key = getInt("Not a valid option. Choose a valid option.");
    }

    Read_files readfiles = Read_files();
    Manager manager = Manager();

    readfiles.read_extrafully(key);

    Graph graph = readfiles.get_graph();
    manager.set_graph(graph);

    manager.triangular();

    cout << "Thanks for using our program!" << endl;
    cout << "Click Enter!";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}

void Menu::second() {
    title("Choose the graph you wish to run.");
    showMenu(fourthOptions);

    int key = getInt("Choose an option.");
    while (key < 1 || key > 3) {
        key = getInt("Not a valid option. Choose a valid option.");
    }

    Read_files readfiles = Read_files();
    Manager manager = Manager();

    readfiles.read_realworld(key);

    Graph graph = readfiles.get_graph();
    manager.set_graph(graph);

    manager.triangular();

    cout << "Thanks for using our program!" << endl;
    cout << "Click Enter!";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}

void Menu::third() {
    title("Choose the number of the file you wish to run.");
    showMenu(firstOptions);

    int key = getInt("Choose an option.");
    while (key < 1 || key > 3) {
        key = getInt("Not a valid option. Choose a valid option.");
    }

    Read_files readfiles = Read_files();
    Manager manager = Manager();

    readfiles.read_toygraphs(key);

    Graph graph = readfiles.get_graph();
    manager.set_graph(graph);

    manager.triangular();

    cout << "Thanks for using our program!" << endl;
    cout << "Click Enter!";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}
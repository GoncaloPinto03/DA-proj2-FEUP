/**
 * @file Menu.h
 * @brief Defines the Menu class and its member functions
 */

#ifndef PROJ2_MENU_H
#define PROJ2_MENU_H

#include "vector"
#include "string"
#include "Manager.h"

using namespace std;

/**
 * @brief A class representing the menu of the train network system
 */
class Menu {
private:
    vector<string> menuOptions = {"Backtracking Algorithm", "Triangular Approximation Heuristic", "Other Heuristics", "Exit"}; /**< An array containing the main menu options */
    vector<string> firstOptions = {"Shipping(1), Stadiums(2), Tourism(3)"}; /**< An array containing the file options for the 4.1 exercise */
    vector<string> secondOptions = {"Extra Fully Connected Graphs, Real World Graphs, Toy Graphs"};

    int state = 0; /**< An integer representing the current state of the menu */
    /**
    * @brief Displays the main menu
    */
    void mainMenu();
    /**
    * @brief Displays the second option menu
    */
    void firstOption();
    /**
     * @brief Runs the first scenario
     * @param packages A vector of Network objects representing the network of the train system
     * @param stations A vector of Station objects representing the stations of the train system
     */
    bool secondOption();
    /**
     * @brief Runs the second scenario
     * @param packages A vector of Network objects representing the network of the train system
     * @param stations A vector of Station objects representing the stations of the train system
     */
    void second();
    /**
    * @brief Runs the second scenario
    * @param packages A vector of Network objects representing the network of the train system
    * @param stations A vector of Station objects representing the stations of the train system
    */

public:
    /**
     * @brief Helps connecting the main function and the rest of the program
     * @param packages A vector of Network objects representing the network of the train system
     * @param stations A vector of Station objects representing the stations of the train system
     * @return A boolean value indicating whether the program should continue running or not
     */
    bool nextState(int key);
};

#endif //PROJ2_MENU_H
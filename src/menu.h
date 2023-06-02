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
    vector<string> firstOptions = {"Shipping", "Stadiums", "Tourism"}; /**< An array containing the file options for the 4.1 exercise */
    vector<string> secondOptions = {"Extra Fully Connected Graphs", "Real World Graphs", "Toy Graphs"}; /**< An array containing the folder options for the 4.2 exercise */
    vector<string> thirdOptions = {"25 edges", "50 edges", "75 edges", "100 edges", "200 edges", "300 edges", "400 edges", "500 edges", "600 edges", "700 edges", "800 edges", "900 edges"}; /**< An array containing the file options for the 4.2 exercise */
    vector<string> fourthOptions = {"Graph 1", "Graph 2", "Graph 3"}; /**< An array containing the graph options for the 4.2 exercise */

    int state = 0; /**< An integer representing the current state of the menu */
    /**
    * @brief Displays the main menu
    */
    void mainMenu();
    /**
    * @brief Displays the first option menu
    */
    void firstOption();
    /**
    * @brief Displays the second option menu
    */
    bool secondOption();
    /**
    * @brief Runs the first scenario
    */
    void first();
    /**
    * @brief Runs the second scenario
    */
    void second();
    /**
    * @brief Runs the third scenario
    */
    void third();

public:
    /**
     * @brief Helps connecting the main function and the rest of the program
     * @return A boolean value indicating whether the program should continue running or not
     */
    bool nextState(int key);
};

#endif //PROJ2_MENU_H
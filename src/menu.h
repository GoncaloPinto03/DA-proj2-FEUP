/**
 * @file Menu.h
 * @brief Defines the Menu class and its member functions
 */

#ifndef PROJ2_MENU_H
#define PROJ2_MENU_H

#include "vector"
#include "string"
#include "Network.h"
#include "Station.h"
#include "Manager.h"

using namespace std;

/**
 * @brief A class representing the menu of the train network system
 */
class Menu {
private:
    vector<string> menuOptions = {"Backtracking Algorithm", "Triangular Approximation Heuristic", "Other Heuristics", "Exit"}; /**< An array containing the main menu options */

    int state = 0; /**< An integer representing the current state of the menu */
     /**
     * @brief Displays the main menu
     */
    void mainMenu();
    /**
     * @brief Runs the first scenario
     * @param packages A vector of Network objects representing the network of the train system
     * @param stations A vector of Station objects representing the stations of the train system
     */
    void first(vector<Network>& packages, vector<Station>& stations);
    /**
     * @brief Runs the second scenario
     * @param packages A vector of Network objects representing the network of the train system
     * @param stations A vector of Station objects representing the stations of the train system
     */
    void second(vector<Network>& packages, vector<Station>& stations);
    /**
    * @brief Runs the second scenario
    * @param packages A vector of Network objects representing the network of the train system
    * @param stations A vector of Station objects representing the stations of the train system
    */
    void third(vector<Network>& packages, vector<Station>& stations);
    /**
    * @brief Runs the third scenario
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
    bool nextState(vector<Network>& packages, vector<Station>& stations);
};

#endif //PROJ2_MENU_H
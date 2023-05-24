#ifndef PROJ2_AUXILIAR_H
#define PROJ2_AUXILIAR_H
#include "string"
#include "vector"

using namespace std;

/**
    @brief Clears the screen.
*/
void clearSCR(); //Clears the screen

/**
    @brief Displays the program's title.
    @param string Optional parameter to specify a custom title.
*/
void title(const string& string = ""); //Displays title

/**
    @brief Displays a menu with the provided options.
    @param options A vector containing the menu options as strings.
    @param settingsOp An optional integer representing the default option to be highlighted.
*/
void showMenu(const vector<string>& options, int settingsOp = 0); //Displays menu options

/**
    @brief Gets the user's input as an integer.
    @param text Optional text to be displayed before the user's input prompt.
    @param text2 Optional text to be displayed after the user's input prompt.
    @return The user's input as an integer.
*/
int getInt(const string& text = "", const string& text2 = ""); //Gets the user's option as an integer

/**
    @brief Gets the user's input as a double.
    @param text Optional text to be displayed before the user's input prompt.
    @param text2 Optional text to be displayed after the user's input prompt.
    @return The user's input as a double.
*/
double getDouble(const string& text = "", const string& text2 = ""); //Gets the user's option as a double

#endif //PROJ2_AUXILIAR_H
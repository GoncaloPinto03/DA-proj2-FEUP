#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "../data_structures/Graph.h"

using namespace std;

/**
 * @file Read_files.h
 * @brief Defines the Read_files class for reading all the files.
 */


#ifndef PROJ2_READ_FILES_H
#define PROJ2_READ_FILES_H

/**
 * @brief The Read_files class reads all the files.
 */
class Read_files {
private:
    Graph graph; /**< The graph we are working with. */

public:
    /**
     * @brief Construct a new Read_files object.
     */
    Read_files();

    /**
     * @brief This function returns our graph.
     */
    Graph get_graph();

    /**
     * @brief This function reads a graph from the Extra Fully Connected Graphs directory.
     * @param input The input that corresponds to a file.
     */
    void read_extrafully(int input);

    /**
     * @brief This function reads a graph from the Real World Graphs directory.
     * @param input The input that corresponds to a file.
     */
    void read_realworld(int input);

    /**
     * @brief This function reads a graph from the Toy Graphs directory.
     * @param input The input that corresponds to a file.
     */
    void read_toygraphs(int input);
};

#endif //PROJ2_READ_FILES_H
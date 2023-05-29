#include "Manager.h"
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <list>
#include <set>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

Manager::Manager() {
    this->graph = Graph();
}
Manager::Manager(int input){
    readExtraFullyConnected(input);
}

Graph Manager::getGraph() {
    return this->graph;
}


void Manager::readExtraFullyConnected(int input) {
    string filename;
    switch(input){
        case 1:
            filename = "dataset/Extra_Fully_Connected_Graphs/edges_25.csv";
            break;
        case 2:
            filename = "dataset/Extra_Fully_Connected_Graphs/edges_50.csv";
            break;
        case 3:
            filename = "dataset/Extra_Fully_Connected_Graphs/edges_75.csv";
            break;
        case 4:
            filename = "dataset/Extra_Fully_Connected_Graphs/edges_100.csv";
            break;
        case 5:
            filename = "dataset/Extra_Fully_Connected_Graphs/edges_200.csv";
            break;
        case 6:
            filename = "dataset/Extra_Fully_Connected_Graphs/edges_300.csv";
            break;
        case 7:
            filename = "dataset/Extra_Fully_Connected_Graphs/edges_400.csv";
            break;
        case 8:
            filename = "dataset/Extra_Fully_Connected_Graphs/edges_500.csv";
            break;
        case 9:
            filename = "dataset/Extra_Fully_Connected_Graphs/edges_600.csv";
            break;
        case 10:
            filename = "dataset/Extra_Fully_Connected_Graphs/edges_700.csv";
            break;
        case 11:
            filename = "dataset/Extra_Fully_Connected_Graphs/edges_800.csv";
            break;
        case 12:
            filename = "dataset/Extra_Fully_Connected_Graphs/edges_900.csv";
            break;
        default:
            cout << "Invalid input" << endl;
            return;
    }
    ifstream file(filename);
    string line;
    int i = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        int node1 = stoi(tokens[0]);
        int node2 = stoi(tokens[1]);
        int weight = stoi(tokens[2]);
        this->graph.addVertex(node1);
        this->graph.addVertex(node2);
        this->graph.addEdge(node1, node2, weight);
    }
    file.close();
}
/*
void Manager::readRealWorld(int input) {
    string filename_edges;
    string filename_nodes;
    switch (input) {
        case 1:
            filename_edges = "dataset/Real-world Graphs/graph1/edges.csv";
            filename_nodes = "/dataset/Real-world Graphs/graph1/nodes.csv";
            break;
        case 2:
            filename_edges = "dataset/Real_World_Graphs/graph2/edges.csv";
            filename_nodes = "dataset/Real_World_Graphs/graph2/nodes.csv";
            break;
        case 3:
            filename_edges = "dataset/Real_World_Graphs/graph3/edges.csv";
            filename_nodes = "dataset/Real_World_Graphs/graph3/nodes.csv";
            break;
        default:
            cout << "Invalid input" << endl;
            return;
    }
    ifstream file_nodes(filename_nodes);
    string line_nodes;
    int i = 0;
    getline(file_nodes, line_nodes);
    while (getline(file_nodes, line_nodes)) {
        stringstream ss(line_nodes);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        int node = stoi(tokens[0]);
        double lat = stod(tokens[2]);
        double lon = stod(tokens[1]);
        cout << node << " " << lat << " " << lon << endl;
        this->graph.addVertex(node, lat, lon);

    }
    ifstream file_edges(filename_edges);
    string line_edges;
    i = 0;
    while (getline(file_edges, line_edges)) {
        stringstream ss(line_edges);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        int node1 = stoi(tokens[0]);
        int node2 = stoi(tokens[1]);
        double weight = stod(tokens[2]);
        this->graph.addEdge(node1, node2, weight);

    }
    file_nodes.close();
    file_edges.close();

}
*/
/*
void Manager::readToyGraphs(int input) {
    string filename;
    switch(input){
        case 1:
            filename = "dataset/Toy_Graphs/shipping.csv";
            break;
        case 2:
            filename = "dataset/Toy_Graphs/stadiums.csv";
            break;
        case 3:
            filename = "dataset/Toy_Graphs/airports.csv";
            break;
    }
    ifstream file(filename);
    string line;
    int i = 0;
    if(input == 3){
        while (getline(file, line)) {
            stringstream ss(line);
            string token;
            vector<string> tokens;
            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }
            int node1 = stoi(tokens[0]);
            int node2 = stoi(tokens[1]);
            int weight = stoi(tokens[2]);
            string name1 = tokens[3];
            string name2 = tokens[4];
            this->graph.addVertex(node1, name1);
            this->graph.addVertex(node2, name2);
            this->graph.addEdge(node1, node2, weight);
        }
    }
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        int node1 = stoi(tokens[0]);
        int node2 = stoi(tokens[1]);
        int weight = stoi(tokens[2]);
        this->graph.addVertex(node1);
        this->graph.addVertex(node2);
        this->graph.addEdge(node1, node2, weight);
    }
    file.close();

}
*/


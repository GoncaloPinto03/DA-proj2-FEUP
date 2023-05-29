//
// Created by gpinto03 on 13-03-2023.
//


#include "Read_files.h"
#include "../data_structures/Graph.h"
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

Read_files::Read_files(){
    this->graph=Graph();
}

Read_files::Read_files(int input) {
    read_extrafully(input);
}

Graph Read_files::get_graph() {
    return this->graph;
}

void Read_files::read_extrafully(int input) {
    string filename;
    switch (input) {
        case 1:
            filename="../dataset/Extra_Fully_Connected_Graphs/edges_25.csv";
            break;
        case 2:
            filename="../dataset/Extra_Fully_Connected_Graphs/edges_50.csv";
            break;
        case 3:
            filename="../dataset/Extra_Fully_Connected_Graphs/edges_75.csv";
            break;
        case 4:
            filename="../dataset/Extra_Fully_Connected_Graphs/edges_100.csv";
            break;
        case 5:
            filename="../dataset/Extra_Fully_Connected_Graphs/edges_200.csv";
            break;
        case 6:
            filename="../dataset/Extra_Fully_Connected_Graphs/edges_300.csv";
            break;
        case 7:
            filename="../dataset/Extra_Fully_Connected_Graphs/edges_400.csv";
            break;
        case 8:
            filename="../dataset/Extra_Fully_Connected_Graphs/edges_500.csv";
            break;
        case 9:
            filename="../dataset/Extra_Fully_Connected_Graphs/edges_600.csv";
            break;

        case 10:
            filename="../dataset/Extra_Fully_Connected_Graphs/edges_700.csv";
            break;

        case 11:
            filename="../dataset/Extra_Fully_Connected_Graphs/edges_800.csv";
            break;

        case 12:
            filename="../dataset/Extra_Fully_Connected_Graphs/edges_900.csv";
            break;

        default:
            cout<<"Invalid input";
            return;
    }
    ifstream file(filename);
    string line;
    int i = 0;
    while(getline(file, line)){
        stringstream ss(line);
        string t;
        vector<string> aux;
        while (getline(ss, t, ',')){
            aux.push_back(t);
        }

        int node_1= stoi(aux[0]);
        int node_2= stoi(aux[1]);
        int w=stoi(aux[2]);
        this->graph.addVertex(node_1);
        this->graph.addVertex(node_2);
        this->graph.addEdge(node_1,node_2, w);
    }
    file.close();
}
/*
void read_files::read_realworld(int input) {
    string filename_n;
    string filename_e;
    switch (input) {
        case 1:
            filename_e = "dataset/Real-world Graphs/graph1/edges.csv";
            filename_n = "dataset/Real-world Graphs/graph1/nodes.csv";
            break;
        case 2:
            filename_e = "dataset/Real-world Graphs/graph2/edges.csv";
            filename_n = "dataset/Real-world Graphs/graph2/nodes.csv";
            break;
        case 3:
            filename_e = "dataset/Real-world Graphs/graph3/edges.csv";
            filename_n = "dataset/Real-world Graphs/graph3/nodes.csv";
            break;
        default:
            cout << "Invalid input" << endl;
            return;
    }
    ifstream file_nodes(filename_n);
    string line_n;
    int i = 0;
    getline(file_nodes, line_n);
    while (getline(file_nodes,line_n)){
        stringstream ss(line_n);
        string t;
        vector<string> aux;
        while (getline(ss, t, ',')) {
            aux.push_back(t);
        }
        int node = stoi(aux[0]);
        double lat = stod(aux[2]);
        double lon = stod(aux[1]);
        cout << node << " " << lat << " " << lon << endl;
        this->graph.addVertex(node, lat, lon);
    }

    ifstream file_edges(filename_e);
    string line_e;
    int j = 0;
    getline(file_edges, line_e);
    while (getline(file_edges,line_e)){
        stringstream ss(line_e);
        string t;
        vector<string> aux;
        while (getline(ss, t, ',')) {
            aux.push_back(t);
        }
        int node_1 = stoi(aux[0]);
        int node_2= stod(aux[1]);
        double w = stod(aux[2]);
        this->graph.addEdge(node_1, node_2, w);
    }
    file_nodes.close();
    file_edges.close();
}
*/

void Read_files::read_toygraphs(int input) {
    string filename;
    switch (input) {
        case 1:
            filename= "../dataset/Toy-Graphs/shipping.csv";
            break;
        case 2:
            filename= "../dataset/Toy-Graphs/stadiums.csv";
            break;
        case 3:
            filename= "../dataset/Toy-Graphs/tourism.csv";
            break;

    }

    ifstream file(filename);

    if(!file.is_open())cout<<"errado!";
    string line;
    int i= 0;
    getline(file,line);
    if (input == 3){
        while(getline(file,line)){
            stringstream ss(line);
            string t;
            vector<string>aux;
            while(getline(ss,t,',')){
                aux.push_back(t);
            }
            int node_1= stoi(aux[0]);
            int node_2= stoi(aux[1]);
            int w= stoi (aux[2]);
            string name1= aux[3];
            string name2= aux[4];
            this->graph.addVertex(node_1, name1);
            this->graph.addVertex(node_2, name2);
            this->graph.addEdge(node_1, node_2, w);

        }

    }
    else{
        while (getline(file, line)) {
            stringstream ss(line);
            string t;
            vector<string> aux;
            while (getline(ss, t, ',')) {
                aux.push_back(t);
            }
            int node_1 = stoi(aux[0]);
            int node_2 = stoi(aux[1]);
            int w = stoi(aux[2]);
            this->graph.addVertex(node_1);
            this->graph.addVertex(node_2);
            this->graph.addEdge(node_1, node_2, w);
        }
    }


    file.close();
}










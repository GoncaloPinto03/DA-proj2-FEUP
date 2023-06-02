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
#include "Read_files.h"
#include "menu.h"
#include "auxiliar.h"
#include "../data_structures/Graph.h"

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
        while (getline(ss, t, ',')) {
            aux.push_back(t);
        }

        int node_1= stoi(aux[0]);
        int node_2= stoi(aux[1]);
        int w=stoi(aux[2]);
        this->graph.addVertex(node_1);
        this->graph.addVertex(node_2);
        this->graph.addEdge(node_1,node_2, w);
        this->graph.addEdge(node_2,node_1, w);
    }
    file.close();
}

void Read_files::read_realworld(int input) {
    string filename_edges;
    string filename_nodes;
    switch (input) {
        case 1:
            filename_edges = "../dataset/Real-world Graphs/graph1/edges.csv";
            filename_nodes = "../dataset/Real-world Graphs/graph1/nodes.csv";
            break;
        case 2:
            filename_edges = "../dataset/Real-world Graphs/graph2/edges.csv";
            filename_nodes = "../dataset/Real-world Graphs/graph2/nodes.csv";
            break;
        case 3:
            filename_edges = "../dataset/Real-world Graphs/graph3/edges.csv";
            filename_nodes = "../dataset/Real-world Graphs/graph3/nodes.csv";
            break;
        default:
            cout << "Invalid input" << endl;
            return;
    }

    ifstream file_nodes(filename_nodes);
    string line_nodes;

    getline(file_nodes, line_nodes);
    while (getline(file_nodes, line_nodes)) {
        stringstream ss(line_nodes);

        string nodeId, lon, lat;
        getline(ss, nodeId, ',');
        getline(ss, lon, ',');
        getline(ss, lat, '\0');

        int id1 = stoi(nodeId);
        double lat2 = stod(lat);
        double lon2 = stod(lon);
        this->graph.addVertex(id1, lon2, lat2);
        // cout << id1 << ' ' << lat2 << ' ' << lon2 << endl;
    }

    ifstream file_edges(filename_edges);
    string line_edges;

    getline(file_edges, line_edges);
    while (getline(file_edges, line_edges)) {
        stringstream ss(line_edges);

        string node1;
        string node2;
        string weight;
        getline(ss, node1, ',');
        getline(ss, node2, ',');
        getline(ss, weight, '\0');

        int node1_ = stoi(node1);
        int node2_ = stoi(node2);
        double weight_ = stod(weight);
        this->graph.addEdge(node1_, node2_, weight_);
        this->graph.addEdge(node2_, node1_, weight_);
        //cout << "origem: " << node1_ << ' ' << "destino: " << node2_ << ' ' << "distance: " << weight_ << endl;
    }

    file_nodes.close();
    file_edges.close();

}

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

    if(!file.is_open())cout<<"Couldn't open the file!";
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

            int node_1 = stoi(aux[0]);
            int node_2 = stoi(aux[1]);
            double w = stod (aux[2]);
            string name1 = aux[3];
            string name2 = aux[4];
            this->graph.addVertex(node_1, name1);
            this->graph.addVertex(node_2, name2);
            this->graph.addEdge(node_1, node_2, w);
            this->graph.addEdge(node_2, node_1, w);

            //cout << node_1 << ' '<< node_2 << ' '<<w <<' ' << name1<<' ' << name2 << endl;

        }
    }
    else{
        while (getline(file, line)) {
            stringstream ss(line);
            string token;
            vector<string> tokens;
            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }
            int node1 = stoi(tokens[0]);
            int node2 = stoi(tokens[1]);
            double weight = stod(tokens[2]);

            this->graph.addVertex(node1);

            this->graph.addVertex(node2);

            this->graph.addEdge(node1, node2, weight);

            this->graph.addEdge(node2, node1, weight);

        }
    }

    file.close();

}

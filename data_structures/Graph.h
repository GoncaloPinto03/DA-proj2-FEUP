#ifndef DA_TP_CLASSES_GRAPH
#define DA_TP_CLASSES_GRAPH

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <list>
#include "stack"
#include <set>
#include "VertexEdge.h"
using namespace std;

struct CompareVertex
{
    bool operator()(const Vertex* lhs, const Vertex* rhs) const  { return lhs->getId() < rhs->getId(); }
};

struct CompareWeight
{
    bool operator()(const Edge* lhs, const Edge* rhs) const  { return lhs->getWeight() < rhs->getWeight(); }
};

class Graph {
public:
    Graph();
    explicit Graph(int nrVertex);

    bool addVertex(const int &id);
    bool addVertex(const int &id, double longitude, double latitude);
    bool addVertex(const int &id, string name);
    bool addEdge(const int &sourc, const int &dest, double w) const;
    bool addEdge(const int &sourc, const int &dest);
    bool removeVertex(const int &id);

    int getNumVertex() const;
    unordered_map<int, Vertex*> getVertexSet() const;
    vector<Vertex *> getVertexSet2() const;


    Vertex * findVertex(const int &id) const;
    int findVertexIdx(const int &id) const;

    Edge * findEdge(const Vertex &source, const Vertex &dest);

    vector<Vertex *> getVertexes();
    void setVertexes (vector<Vertex *> vertexes);


    void resetVisited();
    void resetDist();
    void resetPath();

    void dijkstra(Vertex* source);
    vector<Vertex *> vertexes;
    void dfs(int id, const vector<int> &parent_, vector<bool> &visited, stack<int> &stack, vector<int> &path);
    vector<pair<int,int>> prim(vector<int> &parents);
    int minWeight(vector<double> &weights, vector<bool> &visited);
    bool haveEdge(int id1, int id2);
    double haversine(double lat1, double lon1, double lat2, double lon2);
    double getDistance(const vector<int> &path);
    double triangularApproximation();

protected:
    int numVertex;
    vector<Vertex *> vertexSet2;
    set<Vertex*, CompareVertex> vertexSet;

    unordered_map<int, Vertex *> vertexmap;



    vector<Edge *> edges;
};

#endif
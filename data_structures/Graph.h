#ifndef DA_TP_CLASSES_GRAPH
#define DA_TP_CLASSES_GRAPH

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <list>
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
    set<Vertex *, CompareVertex> getVertexSet() const;


    Vertex * findVertex(const int &id) const;
    int findVertexIdx(const int &id) const;

    Edge * findEdge(const Vertex &source, const Vertex &dest);

    void resetVisited();
    void resetDist();
    void resetPath();

    void dijkstra(Vertex* source);


protected:
    int numVertex;
    //set<Vertex *> vertexSet;
    set<Vertex*, CompareVertex> vertexSet;
};

#endif
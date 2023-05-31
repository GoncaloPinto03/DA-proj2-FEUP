#ifndef UNTITLED1_VERTEXEDGE_H
#define UNTITLED1_VERTEXEDGE_H

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Edge;

class Vertex{
public:
    Vertex();
    Vertex(int id);
    Vertex(int id, double longitude, double latitude);
    Vertex(int id, string name);

    int getId() const;
    string getName() const;
    double getDist() const;
    double getLatitude() const;
    double getLongitude() const;
    bool isVisited() const;
    Edge* getPath() const;
    list<Edge*> getAdj() const ;
    void setId(int id);
    void setName(string name);
    void setDist(double dist2);
    void setLatitude(double lat);
    void setLongitude(double lon);
    void setVisited(bool visited);
    void setPath(Edge *path);


    void addAdj(Vertex *v1, Vertex *v2, double w);
    bool operator<(Vertex & vertex) const;

protected:
    int id;
    string name;
    double dist = 0;
    double longitude = 0.0;
    double latitude = 0.0;
    bool visited = false;
    list<Edge*> adj;
    Edge *path = nullptr;


    void addAdj(Vertex *v1, Vertex *v2, double w) const;

};

class Edge {
public:
    Edge();
    Edge(Vertex* source, Vertex* dest);
    Edge(Vertex* source, Vertex* dest, double weight);

    Vertex* getDest() const;
    Vertex* getSource() const;
    double getWeight() const;
    void setDest(Vertex* dest);
    void setSource(Vertex* source);
    void setWeight(double weight);
private:
    Vertex* source;
    Vertex* dest;
    double weight;


};


#endif //UNTITLED1_VERTEXEDGE_H
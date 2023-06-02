#include "Graph.h"
using namespace std;

Vertex::Vertex() {
    this->id = 0;
    this->dist = 0;
    this->visited = false;
    this->path = nullptr;
}
Vertex::Vertex(int id) {
    this->id = id;
    this->visited = false;
    this->path = nullptr;
}
Vertex::Vertex(int id, double longitude, double latitude) {
    this->id = id;
    this->longitude = longitude;
    this->latitude = latitude;
    this->visited = false;
    this->path = nullptr;
}
Vertex::Vertex(int id, string name) {
    this->id = id;
    this->name = std::move(name);
    this->visited = false;
    this->path = nullptr;
}
bool Vertex::operator<(Vertex & vertex) const {
    return this->id < vertex.id;
}

int Vertex::getId() const {
    return this->id;
}
string Vertex::getName() const {
    return this->name;
}
double Vertex::getDist() const {
    return this->dist;
}
double Vertex::getLatitude() const {
    return this->latitude;
}
double Vertex::getLongitude() const {
    return this->longitude;
}
bool Vertex::isVisited() const {
    return this->visited;
}
Edge* Vertex::getPath() const {
    return this->path;
}
vector<Edge*> Vertex::getAdj() const {
    return this->adj;
}


void Vertex::setId(int id) {
    this->id = id;
}
void Vertex::setName(string name) {
    this->name = name;
}
void Vertex::setDist(double dist2) {
    this->dist = dist2;
}
void Vertex::setLatitude(double lat) {
    this->latitude = lat;
}
void Vertex::setLongitude(double lon) {
    this->longitude = lon;
}
void Vertex::setVisited(bool visited) {
    this->visited = visited;
}
void Vertex::setPath(Edge *path) {
    this->path = path;
}

Edge::Edge() {
    this->dest = nullptr;
    this->weight = 0;
}
Edge::Edge(Vertex* source, Vertex* dest, double weight) {
    this->source = source;
    this->dest = dest;
    this->weight = weight;
}
Edge::Edge(Vertex* source, Vertex* dest) {
    this->source = source;
    this->dest = dest;
    this->weight = 0;
}
Edge::Edge(Vertex* dest, double weight){
    this->dest = dest;
    this->weight = weight;
}
Vertex* Edge::getDest() const {
    return dest;
}
Vertex* Edge::getSource() const {
    return source;
}
double Edge::getWeight() const {
    return weight;
}
void Edge::setDest(Vertex* dest) {
    this->dest = dest;
}
void Edge::setSource(Vertex* source) {
    this->source = source;
}
void Edge::setWeight(double weight) {
    this->weight = weight;
}

void Vertex::addEdge(Vertex *dest, double weight) {
    auto newEdge = new Edge(this, dest, weight);
    this->adj.push_back(newEdge);
}
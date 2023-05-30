#include "Graph.h"
#include <limits>
#include <algorithm>
#include <utility>

using namespace std;

Graph::Graph() {
    this->numVertex = 0;
}

Graph::Graph(int nrVertex) {
    this->numVertex = nrVertex;
}

bool Graph::addVertex(const int &id) {
    if (findVertex(id) != nullptr)
        return false;
    auto *v1 = new Vertex(id);
    vertexSet.insert(v1);
    return true;
}
bool Graph::addVertex(const int &id, double longitude, double latitude) {
    if (findVertex(id) != nullptr)
        return false;
    auto *v1 = new Vertex(id, longitude, latitude);
    vertexSet.insert(v1);
    return true;
}

bool Graph::addVertex(const int &id, string name) {
    if (findVertex(id) != nullptr)
        return false;
    auto *v1 = new Vertex(id, std::move(name));
    vertexSet.insert(v1);
    return true;
}

bool Graph::addEdge(const int &sourc, const int &dest, double w) const {
    Vertex *v1 = findVertex(sourc);
    Vertex *v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;

    //v1->getAdj().insert(v2->getAdj().end(), new Edge(v1, v2, w));
    v1->addAdj(v1,v2,w);
    return true;
}


bool Graph::removeVertex(const int &id) {
    for (auto it = vertexSet.begin(); it != vertexSet.end(); ++it) {
        if ((*it)->getId() == id) {
            vertexSet.erase(it);
            return true;
        }
    }
    return false;
}


int Graph::getNumVertex() const {
    return vertexSet.size();
}

set<Vertex *, CompareVertex> Graph::getVertexSet() const {
    return vertexSet;
}

vector<Vertex *> Graph::getVertexSet2() const {
    return vertexSet2;
}

Vertex * Graph::findVertex(const int &id) const {
    for (auto v : vertexSet)
        if (v->getId() == id)
            return v;
    return nullptr;
}

int Graph::findVertexIdx(const int &id) const {
    int i = 0;
    for (auto it = vertexSet.begin(); it != vertexSet.end(); ++it, ++i)
        if ((*it)->getId() == id)
            return i;
    return -1;
}


void Graph::resetVisited() {
    for (auto v : vertexSet)
        v->setVisited(false);
}

void Graph::resetDist() {
    for (auto v : vertexSet)
        v->setDist(0);
}

void Graph::resetPath() {
    for (auto v : vertexSet)
        v->setPath(nullptr);
}

void Graph::dijkstra(Vertex* source) {
    auto cmp = [](Vertex* a, Vertex* b) {
        return a->getDist() < b->getDist();
    };
    std::priority_queue<Vertex *, std::vector<Vertex *>, decltype(cmp)> pq(cmp);

    for (Vertex* v: vertexSet) {
        v->setVisited(false);
        v->setDist(std::numeric_limits<double>::max());
    }

    source->setDist(0);
    pq.push(source);
    while (!pq.empty()) {
        Vertex* u = pq.top(); pq.pop();
        u->setVisited(true);

        for (Edge* e: u->getAdj()) {
            Vertex* v = e->getDest();
            double w = e->getWeight();
            if (!v->isVisited() && u->getDist() != std::numeric_limits<double>::max() && u->getDist() + w < v->getDist()) {
                v->setDist(u->getDist() + w);
                pq.push(v);
            }
        }
    }
}

Edge * Graph::findEdge(const Vertex &source, const Vertex &dest) {
    for (auto v : getVertexSet()) {
        for (auto e : v->getAdj()) {
            if (e->getSource()->getId() == source.getId() && e->getDest()->getId() == dest.getId()) {
                return e;
            }
        }
    }
    return nullptr;
}


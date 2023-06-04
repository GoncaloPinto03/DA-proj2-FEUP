#include "Graph.h"
#include <math.h>
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
    vertexmap[id] = v1;
    return true;
}
bool Graph::addVertex(const int &id, double longitude, double latitude) {
    if(findVertex(id) != nullptr)
        return false;
    auto *v1 = new Vertex(id, longitude, latitude);
    vertexmap.insert(make_pair(id, v1));
    return true;
}
bool Graph::addVertex(const int &id, string name) {
    if(findVertex(id) != nullptr)
        return false;
    auto *v1 = new Vertex(id, name);
    vertexmap[id] = v1;
    return true;
}

bool Graph::addEdge(const int &sourc, const int &dest, double w) const {
    Vertex *v1 = findVertex(sourc);
    Vertex *v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;

    v1->addEdge(v2, w);
    return true;
}


bool Graph::removeVertex(const int &id) {
    for (auto it = vertexmap.begin(); it != vertexmap.end(); ++it) {
        if (it->second->getId() == id) {
            vertexmap.erase(it);
            return true;
        }
    }
    return false;
}


int Graph::getNumVertex() const {
    return vertexmap.size();
}

unordered_map<int, Vertex*> Graph::getVertexSet() const {
    return vertexmap;
}

Vertex *Graph::findVertex(const int &id) const {
    auto it = vertexmap.find(id);
    if (it == vertexmap.end())
        return nullptr;
    return it->second;
}

void Graph::dfs(const vector<Edge*> &mst, Vertex* v, vector<bool> &visited, vector<int> &path) {

    visited[v->getId()] = true;

    cout << v->getId() << " -> ";

    path.push_back(v->getId());

    for (const auto &e: mst) {
        if (!visited[e->getDest()->getId()] && e->getSource()->getId() == v->getId()) {
            dfs(mst, e->getDest(), visited, path);
        }
    }

}

vector<Edge*> Graph::prim_MST() {

    vector<Edge*> aux;
    priority_queue<Edge*, vector<Edge*>, CompareWeight> pq;

    vector<bool> visited(vertexmap.size(), false);

    Vertex* vertex = this->vertexmap[0];
    visited[vertex->getId()] = true;

    for (const auto& e : vertex->getAdj()) {
        pq.push(e);
    }

    while (!pq.empty()) {
        Edge* edge = pq.top();
        pq.pop();
        Vertex* v = edge->getDest();

        if (visited[v->getId()]) {
            continue;
        }

        visited[v->getId()] = true;
        aux.push_back(edge);

        for (auto e : v->getAdj()) {
            if (!visited[e->getDest()->getId()]) {
                pq.push(e);
            }
        }
    }

    return aux; // mst
}

bool Graph::haveEdge(int source, int dest) {

    for (const auto& vertex : vertexmap) {

        if (vertex.second->getId() == source) {

            for (auto edge : vertex.second->getAdj()) {

                if (edge->getDest()->getId() == dest) {
                    return true;
                }

            }

            break;
        }
    }

    return false;

}

double Graph::haversine(double lat1, double lon1, double lat2, double lon2) {

    double R = 6371e3;

    double phi1 = lat1 * M_PI/180;
    double phi2 = lat2 * M_PI/180;

    double deltaPhi = (lat2-lat1) * M_PI/180;
    double deltaLambda = (lon2-lon1) * M_PI/180;

    double a = sin(deltaPhi/2) * sin(deltaPhi/2) +
               cos(phi1) * cos(phi2) *
               sin(deltaLambda/2) * sin(deltaLambda/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    double d = R * c;

    return d;
}

double Graph::calculate_total_distance(const vector<int> &path) {
    double result = 0.0;
    int n = path.size();
    for (int i = 0; i < n - 1 ;i++) {
        int ve1 = path[i];
        int ve2 = path[i+1];
        if(!haveEdge(ve1, ve2)){
            result += haversine(vertexmap[ve1]->getLatitude(), vertexmap[ve1]->getLongitude(),vertexmap[ve2]->getLatitude(),vertexmap[ve2]->getLongitude());
            continue;
        }
        else {
            Vertex *v = vertexmap[ve1];
            for(auto edge: v->getAdj()){
                if(edge->getDest()->getId() == ve2){
                    result += edge->getWeight();
                    break;
                }
            }
        }
    }
    int f = path.back();
    if(!haveEdge(f,path[0])){
        result += haversine(vertexmap[f]->getLatitude(), vertexmap[f]->getLongitude(),vertexmap[path[0]]->getLatitude(),vertexmap[path[0]]->getLongitude());
    }
    else{
        Vertex *v = vertexmap[f];
        if (v != nullptr){
            for(auto edge: v->getAdj()){
                if(edge->getDest()->getId() == path[0]){
                    result += edge->getWeight();
                }
            }
        }
    }
    return result;
}


void Graph::triangularApproximationHeuristic() {

    double total_distance = 0;

    vector<Edge*>aux = prim_MST();

    cout<< "Preorder is: ";

    vector<bool> visited(vertexmap.size(), false);
    vector<int> preorder (vertexmap.size());

    dfs(aux, aux[0]->getSource(), visited, preorder);

    cout << '0' <<endl;

    total_distance = calculate_total_distance(preorder);

    cout << "Distance: " << total_distance <<endl;

}

double Graph::nearestNeighbor(Vertex* initialNode, Vertex* currentNode, vector<Edge*>& path, int graphSize, double distance) {

    if (currentNode == initialNode && path.size() == graphSize) {
        return distance;
    }

    currentNode->setVisited(true);

    Edge* minEdge = findMinEdge(currentNode);
    if (minEdge) {
        path.push_back(minEdge);
        return nearestNeighbor(initialNode, minEdge->getDest(), path, graphSize, distance + minEdge->getWeight());
    }
    cout << "0 -> ";
    for (auto e : path) {
        cout << e->getSource() << " -> ";
    }
    cout << "0" << endl;

    cout << "Distance: " << distance << endl;
    return distance;

}

Edge* Graph::findMinEdge(Vertex* currentNode) {
    Edge* minEdge = nullptr;
    double minEdgeWeight = numeric_limits<double>::max();

    for (auto edge : currentNode->getAdj()) {
        if (!edge->getDest()->isVisited() && edge->getWeight() < minEdgeWeight) {
            minEdge = edge;
            minEdgeWeight = edge->getWeight();
        }
    }

    return minEdge;
}
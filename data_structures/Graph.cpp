#include "Graph.h"
#include <math.h>
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
    vertexmap.insert(make_pair(id, v1));
    return true;
}

bool Graph::addVertex(const int &id, double longitude, double latitude) {
    if(findVertex(id) != nullptr)
        return false;
    auto *v1 = new Vertex(id, longitude, latitude);
    vertexmap.insert(make_pair(id, v1));
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

bool Graph::addVertex(const int &id, string name) {
    if(findVertex(id) != nullptr)
        return false;
    auto *v1 = new Vertex(id, name);
    vertexmap.insert(make_pair(id, v1));
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
    return vertexmap.size();
}

unordered_map<int, Vertex*> Graph::getVertexSet() const {
    return vertexmap;
}

vector<Vertex *> Graph::getVertexSet2() const {
    return vertexSet2;
}

Vertex * Graph::findVertex(const int &id) const {
    for (auto v : vertexmap)
        if (v.second->getId() == id)
            return v.second;
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
        for (auto e : v.second->getAdj()) {
            if (e->getSource()->getId() == source.getId() && e->getDest()->getId() == dest.getId()) {
                return e;
            }
        }
    }
    return nullptr;
}

void Graph::dfs(int id, const vector<int> &parent_, vector<bool> &visited, stack<int> &stack, vector<int> &path) {
    visited[id] = true;
    stack.push(id);
    while(!stack.empty()){
        int top = stack.top();
        stack.pop();
        path.push_back(top);
        for(int i = 0; i < parent_.size(); i++){
            if(parent_[i] == top && !visited[i]){
                visited[i] = true;
                stack.push(i);
            }
        }
    }
}

int Graph::minWeight(vector<double> &weights, vector<bool> &visited) {
    double min = numeric_limits<double>::max();
    int min_index = -1;
    for(int i = 0; i<weights.size(); i++){
        if(!visited[i] && weights[i] < min){
            min = weights[i];
            min_index = i;
        }
    }
    return min_index;
}

vector<pair<int,int>> Graph::prim(vector<int> &parents) {
    vector<double> weights(vertexmap.size(), numeric_limits<double>::max());
    vector<bool> visited(vertexmap.size(), false);
    int top = 0;
    weights[top] = 0.0;
    for(int i = 0; i<vertexmap.size()-1; i++ ){
        int min = minWeight(weights, visited);
        visited[min] = true;
        for(auto edge: vertexmap[min]->getAdj()){
            if(!visited[edge->getDest()->getId()] && edge->getWeight() < weights[edge->getDest()->getId()]){
                parents[edge->getDest()->getId()] = min;
                weights[edge->getDest()->getId()] = edge->getWeight();
            }
        }
    }
    vector<pair<int,int>> result;
    for(int i = 1; i< vertexmap.size(); i++){
        result.push_back(make_pair(parents[i], i));
    }
    return result;
}

bool Graph::haveEdge(int id1, int id2) {
    for(int i = 0; i<vertexmap[id1]->getAdj().size(); i++){
        if(vertexmap[id1]->getAdj()[i]->getDest()->getId() == id2) {

            return true;
        }
    }
    return false;
}

double Graph::haversine(double lat1, double lon1, double lat2, double lon2) {
    double R = 6371e3; // metres
    double phi1 = lat1 * M_PI/180; // φ, λ in radians
    double phi2 = lat2 * M_PI/180;
    double deltaPhi = (lat2-lat1) * M_PI/180;
    double deltaLambda = (lon2-lon1) * M_PI/180;

    double a = sin(deltaPhi/2) * sin(deltaPhi/2) +
               cos(phi1) * cos(phi2) *
               sin(deltaLambda/2) * sin(deltaLambda/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    double d = R * c; // in metres
    return d;
}

double Graph::getDistance(const vector<int> &path) {
    double result = 0.0;
    for(int i = 0; i < path.size() - 1 ;i++){
        int v1 = path[i];
        int v2 = path[i+1];
        if(!haveEdge(v1, v2)){
            result += haversine(vertexmap[v1]->getLatitude(), vertexmap[v1]->getLongitude(),vertexmap[v2]->getLatitude(),vertexmap[v2]->getLongitude());
            continue;
        }
        else {
            Vertex *v = vertexmap[v1];
            for(auto edge: v->getAdj()){
                if(edge->getDest()->getId() == v2){
                    result += edge->getWeight();
                    break;
                }
            }
        }
    }
    int final = path.back();
    if(!haveEdge(final,path[0])){
        result += haversine(vertexmap[final]->getLatitude(), vertexmap[final]->getLongitude(),vertexmap[path[0]]->getLatitude(),vertexmap[path[0]]->getLongitude());
    }
    else{
        Vertex *v = vertexmap[final];
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


double Graph::triangularApproximation() {
    vector<int> parent_ (vertexmap.size(), -1);
    prim(parent_);
    vector<bool> visited(vertexmap.size(), false);
    stack<int> stack;
    vector<int> path;
    dfs(0, parent_, visited, stack, path);
    for(int i =0; i< path.size();i++){
        cout << path[i] << " ";
    }
    double distance = getDistance(path);
    cout <<"0" << endl << distance << endl;
    return distance;
}


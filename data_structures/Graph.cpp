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

vector<Vertex *> Graph::getVertexSet2() const {
    return vertexSet2;
}

Vertex * Graph::findVertex(const int &id) const {
    for (auto v : vertexmap)
        if (v.second->getId() == id)
            return v.second;
    return nullptr;
}
/*
int Graph::findVertexIdx(const int &id) const {
    int i = 0;
    for (auto it = vertexSet.begin(); it != vertexSet.end(); ++it, ++i)
        if ((*it)->getId() == id)
            return i;
    return -1;
}


void Graph::resetVisited() {
    for (auto v : vertexmap)
        v->setVisited(false);
}

void Graph::resetDist() {
    for (auto v : vertexmap)
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
*/


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

vector<Edge*> Graph::prim() {
    vector<Edge*> mst;

    priority_queue<Edge*, vector<Edge*>, CompareWeight> q;

    vector<bool> visited(vertexmap.size(), false);

    // mst starts on node with id = 0
    Vertex* v1 = this->vertexmap[0];

    for(const auto &e: v1->getAdj()){
        q.push(e);
    }
    visited[v1->getId()] = true;


    while (!q.empty()) {
        Edge* e = q.top();
        q.pop();
        Vertex* v = e->getDest();
        Vertex* u = e->getSource();
        if (visited[v->getId()]) {
            continue;
        }
        visited[v->getId()] = true;
        mst.push_back(e);
        for (const auto &parent: vertexmap) {
            if (parent.second == v) {
                for(auto edge: parent.second->getAdj()){
                    if(!visited[edge->getDest()->getId()]){
                        q.push(edge);
                    }
                }
            }
        }

    }
    return mst;
}

bool Graph::haveEdge(int id1, int id2) {
    int i;
    for(int j = 0; j < vertexmap.size(); j++){
        if(vertexmap[j]->getId() == id1){
            i = j;
        }
    }
    for(auto edge: vertexmap[i]->getAdj()){
        if(edge->getDest()->getId() == id2){
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
    for (int i = 0; i < path.size() - 1 ;i++) {
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
    double res=0.0;
    vector<Edge*>mst = prim();

    cout<< "Preorder is: \n";
    vector<bool> visited(vertexmap.size(), false);
    vector<int> preorder (vertexmap.size());
    dfs(mst, mst[0]->getSource(), visited, preorder);
    cout << '0' <<endl;
    res= getDistance(preorder);
    cout<<"Distance: "<<res<<endl;
}   


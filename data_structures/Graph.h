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

/**
 * @file Graph.h
 * @brief Defines the Graph class.
 */

/**
 * @brief Defines the Compare Weight struct for comparing 2 edges by its weight.
 */
struct CompareWeight
{
    bool operator()(const Edge* lhs, const Edge* rhs) const  { return lhs->getWeight() > rhs->getWeight(); }
};

class Graph {
public:

    /**
     * @brief Construct a new Graph object
     */
    Graph();

    explicit Graph(int nrVertex);

    /**
     * @brief This function adds a new vertex to the graph. If there's a vertex with that id already the function return false. True otherwise.
     * @param id Id of the vertex to be added.
     */
    bool addVertex(const int &id);

    /**
     * @brief This function adds a new vertex to the graph (Real World Graphs). If there's a vertex with that id already the function return false. True otherwise.
     * @param id Id of the vertex to be added.
     * @param longitude Longitude of the vertex to be added.
     * @param latitude Latitude of the vertex to be added.
     */
    bool addVertex(const int &id, double longitude, double latitude);

    /**
    * @brief This function adds a new vertex to the graph. If there's a vertex with that id already the function return false. True otherwise.
    * @param id Id of the vertex to be added.
    * @param name Name of the vertex to be added.
    */
    bool addVertex(const int &id, string name);

    /**
    * @brief This function adds a new edge to the graph. If any of the source or the destiny is a nullptr the function return false. True otherwise.
    * @param sourc Source vertex.
    * @param dest Destiny vertex.
    * @param w Weight of the edge.
    */
    bool addEdge(const int &sourc, const int &dest, double w) const;

    /**
    * @brief This function removes a vertex from the graph. If there's not a vertex with that id the function return false. True otherwise.
    * @param id Id of the vertex to be removed.
    */
    bool removeVertex(const int &id);

    /**
    * @brief This function returns the number of vertexes from the graph.
    */
    int getNumVertex() const;

    /**
    * @brief This function returns a unordered map with all the vertexes from the graph.
    */
    unordered_map<int, Vertex*> getVertexSet() const;

    /**
    * @brief Find a vertex in the graph with the given id, if it does not exist return nullptr.
    * @param id The id of the vertex to find.
    * @return The vertex with the given id, or nullptr if it does not exist.
    */
    Vertex * findVertex(const int &id) const;

    /**
    * @brief Checks if there's an edge between to vertexes given 2 ids. Returns true if so and false otherwise.
    * @param id1 The id of the source vertex to find.
    * @param id2 The id of the dest vertex to find.
    * @return True if there's an edge between those two vertexes. False otherwise.
    */
    bool haveEdge(int id1, int id2);

    /**
    * @brief Computes the distance between two given points (longitude and latitude).
    * @param lat1 The latitude of the first point.
    * @param lon1 The longitude of the first point.
    * @param lat2 The latitude of the second point.
    * @param lon2 The longitude of the second point.
    * @return Returns the distance between those 2 points.
    */
    double haversine(double lat1, double lon1, double lat2, double lon2);

    /**
    * @brief This function calculates the total distance given a certain path (vertexes).
    * @param path The vector of ints, where each int corresponds to a vertex.
    * @return Returns the total distance of tha path.
    */
    double calculate_total_distance(const vector<int> &path);

    /**
    * @brief This function prints the path ans the distance of the triangular approximation algorithm.
    */
    void triangularApproximationHeuristic();

    /**
 * @brief Perform a Depth-First Search (DFS) traversal on a graph starting from a given vertex.
 * @param mst The minimum spanning tree of the graph.
 * @param v   The starting vertex for the DFS traversal.
 * @param visited A vector indicating whether a vertex has been visited.
 * @param path A vector that stores the path traversed during the DFS traversal.
 * @return void
 */
    void dfs(const vector<Edge *> &mst, Vertex *v, vector<bool> &visited, vector<int> &path);

    /**
    * @brief This function computes the Prim Algorithm to find the MST of the graph.
    * @return Returns the MST as a vector of Edges.
    */
    vector<Edge *> prim_MST();

    double nearestNeighbor(Vertex* initialNode, Vertex* currentNode, vector<Edge*>& path, int graphSize, double distance);

    Edge* findMinEdge(Vertex* currentNode);

protected:

    int numVertex; /**< Number of vertexes from the graph we are working with. */

    unordered_map<int, Vertex *> vertexmap; /**< Unordered Map that stores all the vertexes from the graph.*/

    vector<Edge *> edges; /**< Vector that stores all the edges from the graph.*/

    vector<Vertex *> vertexes; /**< Vector that stores all the vertexes from the graph.*/

};

#endif
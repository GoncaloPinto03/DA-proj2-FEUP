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
     * Check if there is an edge between two vertices.
     *
     * @param source The ID of the source vertex.
     * @param dest The ID of the destination vertex.
     *
     * @return True if there is an edge between the vertices, False otherwise.
     *
     * @complexity O(|V| + |E|), where |V| is the number of vertices and |E| is the number of edges.
     */
    bool haveEdge(int source, int dest);

    /**
     * Calculate the haversine distance between two sets of latitude and longitude coordinates.
     *
     * @param lat1 The latitude of the first point.
     * @param lon1 The longitude of the first point.
     * @param lat2 The latitude of the second point.
     * @param lon2 The longitude of the second point.
     *
     * @return The haversine distance between the points.
     *
     * @complexity O(1)
     */
    double haversine(double lat1, double lon1, double lat2, double lon2);


    /**
     * Calculate the total distance of a given path (tour) in the graph.
     *
     * @param path The vector of vertices representing the path.
     *
     * @return The total distance of the path.
     *
     * @complexity O(|V| + |E|), where |V| is the number of vertices and |E| is the number of edges.
     */
    double calculate_total_distance(const vector<int> &path);

    /**
    * @brief This function prints the path ans the distance of the triangular approximation algorithm.
    * @complexity O(|V| + |E| log |V|), where |V| is the number of vertices and |E| is the number of edges.
    */
    void triangularApproximationHeuristic();


    /**
    * Perform Depth-First Search (DFS) traversal starting from the given vertex,
    * while recording the traversal order in the preorder vector and marking visited vertices.
    *
    * @param mst The minimum spanning tree.
    * @param v The current vertex being visited.
    * @param visited A vector to mark visited vertices.
    * @param path A vector to store the traversal order (preorder).
    *
    * @complexity O(|V| + |E|), where |V| is the number of vertices and |E| is the number of edges.
    */
    void dfs(const vector<Edge *> &mst, Vertex *v, vector<bool> &visited, vector<int> &path);

    /**
     * Generate the Minimum Spanning Tree (MST) of the graph using Prim's algorithm.
     *
     * @return The vector of edges representing the minimum spanning tree.
     *
     * @complexity O(|E| log |V|), where |V| is the number of vertices and |E| is the number of edges.
     */
    vector<Edge *> prim_MST();

    /**
     * Find the approximate solution to the Traveling Salesman Problem (TSP)
     * using the Nearest Neighbor heuristic.
     *
     * @param initialNode The starting node for the tour.
     * @param currentNode The current node being visited.
     * @param path The vector to store the edges of the tour.
     * @param graphSize The number of nodes in the graph.
     * @param distance The current distance of the tour.
     *
     * @return The approximate distance of the TSP tour.
     *
     * @complexity O(n^2) where n is the number of nodes in the graph.
     */
    double nearestNeighbor(Vertex* initialNode, Vertex* currentNode, vector<Edge*>& path, int graphSize, double distance);

    /**
    * @brief This function gets the edge with the minimum weight of a given vertex.
    * @param currentNode The current vertex
    * @return Returns the edge with the minimum weight.
    */
    Edge* findMinEdge(Vertex* currentNode);

protected:

    int numVertex; /**< Number of vertexes from the graph we are working with. */

    unordered_map<int, Vertex *> vertexmap; /**< Unordered Map that stores all the vertexes from the graph.*/

    vector<Edge *> edges; /**< Vector that stores all the edges from the graph.*/

    vector<Vertex *> vertexes; /**< Vector that stores all the vertexes from the graph.*/

};

#endif
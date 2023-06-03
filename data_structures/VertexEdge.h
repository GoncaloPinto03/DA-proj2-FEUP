#ifndef UNTITLED1_VERTEXEDGE_H
#define UNTITLED1_VERTEXEDGE_H

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Edge;

/**
 * @class Vertex
 * @brief Class representing a vertex in a graph.
 */
class Vertex{
public:
    /**
     * @brief Vertex constructor.
     */
    Vertex();

    /**
     * @brief Vertex constructor.
     * @param id Id of the vertex.
     */
    Vertex(int id);

    /**
     * @brief Vertex constructor.
     * @param id Id of the vertex.
     * @param longitude Longitude of the vertex.
     * @param latitude Latitude of the vertex.
     */
    Vertex(int id, double longitude, double latitude);

    /**
     * @brief Vertex constructor.
     * @param id Id of the vertex.
     * @param name Name of the vertex.
     */
    Vertex(int id, string name);

    int getId() const;
    string getName() const;
    double getDist() const;
    double getLatitude() const;
    double getLongitude() const;

    /**
    * @brief Check if the vertex has been visited.
    * @return True if the vertex has been visited, false otherwise.
    */
    bool isVisited() const;
    Edge* getPath() const;
    vector<Edge*> getAdj() const ;

    /**
     * @brief Set the id of the vertex.
     * @param id The id to set.
    */
    void setId(int id);

    /**
     * @brief Set the name of the vertex.
     * @param name The name to set.
    */
    void setName(string name);

    /**
     * @brief Set the dist of the vertex.
     * @param id The dist to set.
    */
    void setDist(double dist2);

    /**
     * @brief Set the latitude of the vertex.
     * @param lat The latitude to set.
    */
    void setLatitude(double lat);

    /**
     * @brief Set the longitude of the vertex.
     * @param lon The longitude to set.
    */
    void setLongitude(double lon);

    /**
     * @brief Set the visited status of the vertex.
     * @param visited The visited status to set.
    */
    void setVisited(bool visited);

    /**
     * @brief Set the edge path of the vertex.
     * @param path The edge path to set.
    */
    void setPath(Edge *path);

    /**
     * @brief Add an edge to the vertex's adjacency list.
     * @param dest The dest of the edge.
     * @param weight The weight of the edge.
    */
    void addEdge(Vertex *dest, double weight);

    bool operator<(Vertex & vertex) const;

protected:
    int id;
    string name;
    double dist = 0;
    double longitude = 0.0;
    double latitude = 0.0;
    bool visited = false;
    vector<Edge*> adj;
    Edge *path = nullptr;

};
/**
 * @class Edge
 * @brief Represents an edge in a graph.
 *
 * This class represents an edge in a graph, connecting two vertices.
 * Each edge has a weight that can be used in various graph algorithms.
 */
class Edge {
public:
    /**
    * @brief Edge constructor.
    */
    Edge();

    /**
    * @brief Constructor with specified source and destination.
    * @param source Pointer to the origin vertex.
    * @param dest Pointer to the destination vertex.
    */
    Edge(Vertex* source, Vertex* dest);

    /**
    * @brief Constructor with specified source, destination, and weight.
    * @param source Pointer to the origin vertex.
    * @param dest Pointer to the destination vertex.
    * @param w Weight of the edge.
    */
    Edge(Vertex* source, Vertex* dest, double weight);

    /**
    * @brief Constructor with specified destination, and weight.
    * @param dest Pointer to the destination vertex.
    * @param w Weight of the edge.
    */
    Edge(Vertex *dest, double weight);

    /**
    * @brief This function gets the destination of an edge.
    * @return This function returns the destination of an edge.
    */
    Vertex* getDest() const;

    /**
    * @brief This function gets the source of an edge.
    * @return This function returns the source of an edge.
    */
    Vertex* getSource() const;

    /**
    * @brief This function gets the weight of an edge.
    * @return This function returns the weight of an edge.
    */
    double getWeight() const;

    /**
     * @brief Set the destination of the edge.
     * @param dest The destination to set.
    */
    void setDest(Vertex* dest);

    /**
     * @brief Set the source of the edge.
     * @param dest The source to set.
    */
    void setSource(Vertex* source);

    /**
     * @brief Set the weight of the edge.
     * @param dest The weight to set.
    */
    void setWeight(double weight);
private:
    Vertex* source;
    Vertex* dest;
    double weight;


};


#endif //UNTITLED1_VERTEXEDGE_H
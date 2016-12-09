#pragma once
#include <vector>
#include <queue>

class Graph {
public:
	// TO DO
	// initialize an undirected graph that can store at most n vertices
	Graph(const int n) {
		this -> numberVertices = n;
		adjVector = new std::vector<int>[numberVertices];
	
	}

	// TO DO
	// insert an edge between vertices u and v
	void insertEdge(int u, int v) {
		adjVector[u].push_back(v);
	}

	// TO DO
	// return the set of vertices that are adjacent to v
	std::vector<int> adjacentVertices(int v) {
		std::vector<int> vertices;
		for (int j = 0; j < numberVertices; j++) {
            		if(adjVector[v][j] == true)
			vertices.push_back(j+1);
		  }

		return vertices;
	}

	// TO DO
	// return a list of vertices that appear between v and w, starting with v and ending with w
	// vertices should not be repeated

	bool getPath(int v, int w) {

    // Base case
    if (v == w)
        return true;
 
    // Mark all the vertices as not visited
    bool *visited = new bool[numberVertices];
    for (int i = 0; i < numberVertices; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    std::queue<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[v] = true;
    queue.push(v);
 
    // it will be used to get all adjacent vertices of a vertex
    std::vector<int>::iterator i;
 
    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        v = queue.front();
        queue.pop();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adjVector[v].begin(); i != adjVector[v].end(); ++i)
        {
            // If this adjacent node is the destination node, then return true
            if (*i == w)
                return true;
 
            // Else, continue to do BFS
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push(*i);
            }
        }
    }
 
    return false;
}

private:
	// TO DO
	// member variables and functions to implement the public member functions
	int numberVertices;
	std::vector<int> *adjVector;
	std::vector<int> from;
};

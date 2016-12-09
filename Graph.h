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
	
	void dfs(int s) {
		std::vector <bool> visited;
		visited[s] = true;
		for (int i = 0; i < adjVector[s].size(); i++)
			if (!visited[adjVector[s][i]])
				dfs(adjVector[s][i]);
	}
	
	std::vector<int> getPath(int v, int w) {
		std::vector<int> path;
		for (int i =0; i < adjVector[v].size(); i++) {
			for (int j =0; j < adjVector[w].size(); j++){
				if(adjVector[v][i] == adjVector[w][j])
				path.push_back(adjVector[v][i]);
			}
		}
		return path;
	}

private:
	// TO DO
	// member variables and functions to implement the public member functions
	int numberVertices;
	std::vector<int> *adjVector;
};

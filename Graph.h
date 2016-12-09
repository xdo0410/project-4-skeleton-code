#pragma once
#include <vector>


class Graph {
public:
	// TO DO
	// initialize an undirected graph that can store at most n vertices
	Graph() {}

	// TO DO
	// insert an edge between vertices u and v
	void insertEdge(int u, int v) {
		if (u >= adjVector.size()) {
			adjVector.resize(u+1);
		}
		if (v >= adjVector.size()) {
			adjVector.resize(v + 1);
		}
		adjVector[u].push_back(v);
		adjVector[v].push_back(u);
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
	
	std::vector<int> getPath(int v, int w) {
		std::vector<int> getPath(int v, int w) {
		isVisited.resize(adjVector.size());
		for (int i = 0; i < adjVector.size(); i++) {
			isVisited[i] = false;
		} // for

		path.clear();

		bool isFoundPath = getToTarget(v, w);
		if (isFoundPath)
			path.push_back(v);


		std::vector<int> pathTrailToReturn;
		for (auto rit = path.crbegin(); rit != path.crend(); ++rit)
			pathTrailToReturn.push_back(*rit);

		return pathTrailToReturn;
	}

	bool getToTarget(int source, int target) {
		bool targetFound = false;
		isVisited[source] = true;
		if (source == target) {
			targetFound = true;
		}
		else {
			for (int i = 0; i < adjVector[source].size(); i++) {
				int nextSourceToVisit = adjVector[source][i];
				if (!isVisited[nextSourceToVisit]) {
					targetFound = getToTarget(nextSourceToVisit, target);
					if (targetFound) {
						// Only add to the trail path if not already there.
						if (!isAlreadyInTrailPath(nextSourceToVisit))
							path.push_back(nextSourceToVisit);
						break; // Found the path to target so no need to continue. Exit immediately.
					} // if						
				} // if
			} // for
		} // else
		return targetFound;
	}

	bool isAlreadyInTrailPath(int source) {
		for (int i = 0; i < path.size(); i++) {
			if (path[i] == source)
				return true;
		} // for
		return false;
	}
	


private:
	// TO DO
	// member variables and functions to implement the public member functions
	int numberVertices;
	std::vector<std::vector<int>> adjVector;
	
	std::vector<bool> isVisited;
	std::vector<int> path;
	
};

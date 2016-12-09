#pragma once
#include <vector>
#include <stdexcept>

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
		if ((v < 1) || (v > adjVector.size()))
			throw out_of_range("The param v is out of range.");

		return buildPathTrail(v, w);
	}
	


private:
	// TO DO
	// member variables and functions to implement the public member functions
	int numberVertices;
	std::vector<std::vector<int>> adjVector;
	
	std::vector<bool> isVisited;
	std::vector<int> pathTrail;

	std::vector<int> buildPathTrail(int startingSource, int target) {
		// Initially, mark all the source vertices as not yet visited.
		isVisited.resize(adjVector.size());
		for (int i = 0; i < adjVector.size(); i++) {
			isVisited[i] = false;
		} // for

		// Reset pathTrail in case it was built from previously iteration.
		pathTrail.clear();
		bool isFoundPath = getToTarget(startingSource, target);
		if (isFoundPath)
			pathTrail.push_back(startingSource);
		// TODO: maybe throw an exception if path is not found y checking the returned isFoundPath param.

		// The path is built in reverse order, i.e. target back to starting point, because the nature of using vector<int>.
		// We just need to reverse it for the program caller to work naturally.
		std::vector<int> pathTrailToReturn;
		for (auto rit = pathTrail.crbegin(); rit != pathTrail.crend(); ++rit)
			pathTrailToReturn.push_back(*rit);

		return pathTrailToReturn;
	}

	// This function resursively trying to find the first path by travel from the source to target by visiting 
	// every adjacent nodes and their adjacent ones until hitting the target.
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
							pathTrail.push_back(nextSourceToVisit);
						break; // Found the path to target so no need to continue. Exit immediately.
					} // if						
				} // if
			} // for
		} // else
		return targetFound;
	}

	bool isAlreadyInTrailPath(int source) {
		for (int i = 0; i < pathTrail.size(); i++) {
			if (pathTrail[i] == source)
				return true;
		} // for
		return false;
	}
};

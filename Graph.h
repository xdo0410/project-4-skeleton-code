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
	
		std::vector<int> getPath(int v, int w) {
		std::vector<int> path;
		int cur = w;
		while(cur!= -1){
			path.push_back(cur);
			cur = from[cur];	
		}

		return path;
	}

	int BFS(int v, int w){ // source and destination, returns the length of the shortest path between src and dest if reachable, otherwise returns -1
		std::vector <bool> visited;
		
		std::queue<int>q;
		int level=0,nextLevelNodes=0,curLevelNodes=1;
		q.push(v); visited[v]=true;

		while(!q.empty()){
			int cur = q.front(); q.pop();
			curLevelNodes--;
			for(int i = 0 ; i < adjVector[cur].size();i++){
				if(!visited[adjVector[cur][i]]){
				q.push(adjVector[cur][i]);
				from[adjVector[cur][i]]=cur;
				visited[adjVector[cur][i]]=true;
				nextLevelNodes++;
				if(adjVector[cur][i]==w) 
					return level+1;
       }
     }

			if(!curLevelNodes){
			curLevelNodes=nextLevelNodes;
			nextLevelNodes=0;
			level++;
			}
		}
		return -1;
	}

	

private:
	// TO DO
	// member variables and functions to implement the public member functions
	int numberVertices;
	std::vector<int> *adjVector;
	std::vector<int> from;
};

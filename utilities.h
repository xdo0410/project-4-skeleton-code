#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Graph.h"

using namespace std;

// TO DO
// Read a list of integer, string pairs representing a station name and its identifier from a text file
// return a vector of strings containing the stations names indexed by their identifiers
// throw an exception if there was a problem opening or reading the file
std::vector<string> readStationNames(const std::string& filename) {
	ifstream fin;
	fin.open(filename);
	
	if(!fin.is_open())
		throw invalid_argument("Unable to open file " + filename);
	
	int id;
	string station;
	std::vector<string>station_names;
	std::vector<string>::iterator it;

	while (fin)
	{
		fin >> station >> id;

		if (id >= station_names.size())
			station_names.resize(id+1);

		//it = station_names.begin();
		station_names[id] = station;
		//station_names.push_back(station);
	}

	return station_names;
}

// TO DO
// Read a list of (integer, integer) pairs representing station identifiers that are next to each other
// return a graph representing these station links
// throw an exception if there was a problem opening or reading the file
Graph *buildGraphfromDatafile(const std::string& filename) {
	ifstream fin;
	fin.open(filename);
	
	if(!fin.is_open())
		throw invalid_argument("Unable to open file " + filename);
	
	int station, adjacentStation;
	Graph *stationGraph = new Graph();

	while (fin)
	{
		fin >> station >> adjacentStation;
		stationGraph->insertEdge(station, adjacentStation);
	} // while

	return stationGraph;
	//return NULL;
}

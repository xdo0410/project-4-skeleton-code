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

	throw invalid_argument("Unable to open file " + filename);
	return std::vector<string>();
}

// TO DO
// Read a list of (integer, integer) pairs representing station identifiers that are next to each other
// return a graph representing these station links
// throw an exception if there was a problem opening or reading the file
Graph *buildGraphfromDatafile(const std::string& filename) {

	throw invalid_argument("Unable to open file " + filename);
	return NULL;
}
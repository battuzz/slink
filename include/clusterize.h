/*
	This is an abstract class that will implement one of the clustering algorithm
*/

#include <vector>
#include "Utils.h"

using namespace std;

#ifndef CLUSTERIZE
#define CLUSTERIZE

class Clusterize {
public:
	virtual void clusterize(const vector<vector<float>> &data, vector< vector<float>> &linkageMatrix, distance_func d) = 0;
};


#endif

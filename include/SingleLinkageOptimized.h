/*
	Optimized naive method, using Segment Trees
*/

#include <iostream>
#include <limits>
#include <list>
#include <stdio.h>
#include <ctime>


#include "Utils.h"
#include "clusterize.h"

using namespace std;

class SingleLinkageOptimized : public Clusterize {
private:
	void computeDissimilarityMatrix(vector<vector<float>> &D, const vector<vector<float>> &data, distance_func dist);
public:
	void clusterize(const vector<vector<float>> &data, vector< vector<float>> &linkageMatrix, distance_func d) override;
};

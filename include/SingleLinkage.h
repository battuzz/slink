/*
	Naive implementation
*/

#include <iostream>
#include <limits>
#include <ctime>


#include "Utils.h"
#include "clusterize.h"

using namespace std;

class SingleLinkage : public Clusterize {
private:
	void computeDissimilarityMatrix(vector<vector<float>> &D, const vector<vector<float>> &data, distance_func dist);
public:
	void clusterize(const vector<vector<float>> &data, vector< vector<float>> &linkageMatrix, distance_func d) override;
};

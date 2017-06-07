#include <iostream>

#include "Utils.h"
#include "clusterize.h"

using namespace std;

class SingleLinkage : public Clusterize {
public:
	void clusterize(const vector<vector<float>> &data, vector< vector<float>> &linkageMatrix, distance_func d) override;
};
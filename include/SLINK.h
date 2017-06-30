/*
	SLINK implementation from Sibson paper.
*/

#include <vector>
#include <limits>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>

#include "Utils.h"
#include "clusterize.h"

using namespace std;

struct index_value {
	int index;
	float value;
};

class SLINK : public Clusterize {
public:
	void clusterize(const vector<vector<float>> &data, vector< vector<float>> &linkageMatrix, distance_func d) override;

	void fromPointerReprToLinkageMatrix(vector<float> lambdas, vector<float> pies, vector< vector<float> > &linkageMatrix);
};

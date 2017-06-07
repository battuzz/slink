#include <vector>
#include <limits>
#include <iostream>
#include <cmath> 

#include "Utils.h"
#include "clusterize.h"

using namespace std;

class SLINK : public Clusterize {
public:
	void clusterize(const vector<vector<float>> &data, vector< vector<float>> &linkageMatrix, distance_func d) override;

	void fromPointerReprToLinkageMatrix(vector<float> lambdas, vector<float> pies, vector< vector<float> > &linkageMatrix);
};

//void clusterize(const vector<vector<float>> &data, vector< vector<float> > &linkageMatrix, distance_func);
//void fromPointerReprToLinkageMatrix(vector<float> lambdas, vector<float> pies, vector< vector<float> > &linkageMatrix);

#include <vector>
#include <limits>
#include <iostream>
#include <cmath> 
#include "Utils.h"

using namespace std;

void clusterize(vector< vector<float> > data, vector< vector<float> > &linkageMatrix, distance_func);
void fromPointerReprToLinkageMatrix(vector<float> lambdas, vector<float> pies, vector< vector<float> > &linkageMatrix);

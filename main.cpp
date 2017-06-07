#include <iostream>
#include <vector>

#include "Utils.h"
#include "SLINK.h"
#include "SingleLinkage.h"

using namespace std;

int main(int argc, char* argv[]) {
	vector< vector<float> > data;
	readCsv(data, argv[1], ',');

	vector< vector<float> > linkageMatrix; // 2n * 4 matrix
	int n = data.size();

	for (int i = 1; i <= 2*n; i++) {
		vector<float> v;
		linkageMatrix.push_back(v);
	}

	clusterize(data, linkageMatrix, manhattanDistance);
}

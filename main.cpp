#include <iostream>
#include "Utils.h"
#include "SLINK.h"

using namespace std;

int main(int argc, char* argv[]) {
	vector< vector<float> > data;

	read_csv(data, "test.csv");

	vector< vector<float> > linkageMatrix; // 2n * 4 matrix
	int n = data.size();

	for (int i = 1; i <= 2*n; i++) {
		vector<float> v;
		linkageMatrix.push_back(v);
	}

	clusterize(data, linkageMatrix, manhattanDistance);
}
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

	// for (int i = 1; i <= 2*n; i++) {
	// 	vector<float> v;
	// 	linkageMatrix.push_back(v);
	// }

	SingleLinkage slink;
	slink.clusterize(data, linkageMatrix, manhattanDistance);
	for (int i = 0; i < linkageMatrix.size(); i++) {
		for (int j = 0; j < linkageMatrix[i].size(); j++)
			cout << linkageMatrix[i][j] << " ";
		cout << endl;
	}
}

#include <iostream>
#include <vector>

#include "Utils.h"
#include "SLINK.h"
#include "SingleLinkage.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc < 3) {
		cout << "Usage: " << argv[0] << " input_data output_data" << endl;
		exit(0);
	}
	vector< vector<float> > data;
	readCsv(data, argv[1], ',');

	vector< vector<float> > linkageMatrix; // 2n * 4 matrix
	int n = data.size();

	SLINK slink;
	slink.clusterize(data, linkageMatrix, manhattanDistance);
	// for (int i = 0; i < linkageMatrix.size(); i++) {
	// 	for (int j = 0; j < linkageMatrix[i].size(); j++)
	// 		cout << linkageMatrix[i][j] << " ";
	// 	cout << endl;
	// }

	toCsv(linkageMatrix, argv[2]);
}

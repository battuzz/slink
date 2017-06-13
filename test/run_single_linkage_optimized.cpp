#include <iostream>
#include <vector>

#include "Utils.h"
#include "SingleLinkageOptimized.h"

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

	SingleLinkageOptimized slink;
	slink.clusterize(data, linkageMatrix, manhattanDistance);

	toCsv(linkageMatrix, argv[2]);
}

#include <iostream>
#include <vector>

#include "Utils.h"
#include "SLINK.h"
#include "SingleLinkage.h"

using namespace std;

float getAmenability(vector< vector<float> > &data, distance_func d, vector< vector<float> > &linkageMatrix);
float getStarDistance(vector< vector<float> > &linkageMatrix, int min_index, int max_index);


int main(int argc, char* argv[]) {
	vector< vector<float> > data;
	readCsv(data, argv[1], ',');

	vector< vector<float> > linkageMatrix; // 2n * 4 matrix
	int n = data.size();

	SLINK slink;
	slink.clusterize(data, linkageMatrix, manhattanDistance);

	float amenability = getAmenability(data, manhattanDistance, linkageMatrix);

	printf("Amenability: %f\n", amenability);

	toCsv(linkageMatrix, argv[2]);
}


float getAmenability(vector< vector<float> > &data, distance_func d, vector< vector<float> > &linkageMatrix) {
	float numerator = 0;
	float denumerator = 0;
	int n = linkageMatrix.size() + 1;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			float distance = d(data[i], data[j]);
			float star_distance = getStarDistance(linkageMatrix, i, j);

			numerator += distance - star_distance;
			denumerator += distance;
		}
	}

	return numerator / denumerator;
}

float getStarDistance(vector< vector<float> > &linkageMatrix, int min_index, int max_index) {
	int n = linkageMatrix.size() + 1;
	bool found = false;
	float result = 0;

	for (int i = 0; i < n - 1 && !found; i++) {
		vector<float> line = linkageMatrix[i];

		int min_index_line = min(line[0], line[1]);
		int max_index_line = max(line[0], line[1]);
		int new_index = n + i + 1;

		if (min_index == min_index_line && max_index == max_index_line) {
			found = true;
			result = line[2];
		}

		if (min_index == min_index_line) {
			min_index = min(new_index, max_index);
			max_index = max(new_index, max_index);	
		}

		else if (max_index == max_index_line) {
			min_index = min(new_index, min_index);
			max_index = max(new_index, min_index);	
		}
	}

	return result;
}
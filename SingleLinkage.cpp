#include "SingleLinkage.h"

void SingleLinkage::clusterize(const vector<vector<float>> &data, vector<vector<float>> &linkageMatrix, distance_func dist) {
	vector<vector<float>> D(data.size());		// Dissimilarity matrix
	vector<bool> visited(data.size());			// Store whether a point is already been used or not
	
	vector<int> unionFind(2 * data.size());
	makeSet(unionFind, 2 * data.size());


	computeDissimilarityMatrix(D, data, dist);

	for (int it = 0; it < data.size() - 1; it++) {
		// For each point
		int mini = 0;
		int minj = 0;
		float mindist = numeric_limits<float>::infinity();

		for (int i = 0; i < data.size(); i++) {
			if (!visited[i]) {
				for (int j = i+1; j < data.size(); j++)
				// Find the minimum
				if (!visited[j]) {
					if (D[i][j] < mindist) {
						mini = i;
						minj = j;
						mindist = D[i][j];
					}
				}
			}
		}

		int joined = min(mini, minj);
		int joiner = max(mini, minj);

		linkageMatrix.push_back(vector<float> {(float)find(unionFind, mini), (float)find(unionFind,minj), D[mini][minj], 1});

		join(unionFind, joined, data.size() + it);
		join(unionFind, joiner, data.size() + it);

		visited[joined] = true;
		// Update the row
		for (int j = joiner + 1; j < data.size(); j++)
			D[joiner][j] = min(D[joiner][j], D[joined][j]);

		// Update the column
		for (int i = 0; i < joiner; i++)
			if (i < joined)
				D[i][joiner] = min(D[i][joiner], D[i][joined]);
			else
				D[i][joiner] = min(D[i][joiner], D[joined][i]);

		
	}
}

void SingleLinkage::computeDissimilarityMatrix(vector<vector<float>> &D, const vector<vector<float>> &data, distance_func dist) {
	D.clear();
	D.resize(data.size());
	for (int i = 0; i < data.size(); i++) {
		D[i].resize(data.size());
		for (int j = i+1; j < data.size(); j++) {
			D[i][j] = dist(data[i], data[j]);
		}
	}
}
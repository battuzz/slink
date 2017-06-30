#include "SingleLinkage.h"

void SingleLinkage::clusterize(const vector<vector<float>> &data, vector<vector<float>> &linkageMatrix, distance_func dist) {
	clock_t start = clock();

	vector<vector<float>> D(data.size());		// Dissimilarity matrix
	vector<bool> visited(data.size());			// Store whether a point is already been used or not

	vector<int> unionFind(2 * data.size());
	makeSet(unionFind, 2 * data.size());

	/* C will count the number of points in each sub-cluster to compute linkage matrix */
	vector<int> C(2*data.size());
	for (int i = 0; i < data.size(); i++)
		C[i] = 1;


	computeDissimilarityMatrix(D, data, dist);

	clock_t end  = clock() ;
	float time1 = (float) (end - start) / CLOCKS_PER_SEC;
	printf("naive,%f,dissimilarity_matrix_build_time,%d,%d\n", time1, data.size(), data[0].size());

	start = clock();

	for (int it = 0; it < data.size() - 1; it++) {
		// For each point
		int mini = 0;
		int minj = 0;
		float mindist = numeric_limits<float>::infinity();

		// Search for the pair of points with min distance to join
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

		// Update the count in the new cluster as the sum of the two joined clusters
		C[data.size() + it] = C[find(unionFind, joined)] + C[find(unionFind, joiner)];

		// Add new row to linkage matrix
		linkageMatrix.push_back(vector<float> {(float)find(unionFind, mini), (float)find(unionFind,minj), D[mini][minj], (float)C[data.size() + it]});

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

	end  = clock() ;
	float time2 = (float) (end - start) / CLOCKS_PER_SEC;
	printf("naive,%f,linkage_matrix_build_time,%d,%d\n", time2, data.size(), data[0].size());
	printf("naive,%f,total_time,%d,%d\n", time1 + time2, data.size(), data[0].size());
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

#include "SingleLinkageOptimized.h"

void computeDissimilarityVector(vector<float> &D, const vector<vector<float>> &data, distance_func dist);

void SingleLinkageOptimized::clusterize(const vector<vector<float>> &data, vector<vector<float>> &linkageMatrix, distance_func dist) {
	clock_t start = clock();

	int N = (int)data.size();
	vector<float> D;					// Dissimilarity matrix

	vector<int> unionFind;
	makeSet(unionFind, 2 * N);


	vector<int> C(2 * N);
	for (int i = 0; i < N; i++)
		C[i] = 1;

	computeDissimilarityVector(D, data, dist);

	clock_t end  = clock() ;
	float time1 = (float) (end - start) / CLOCKS_PER_SEC;
	printf("naive_optimized,%f,dissimilarity_matrix_build_time,%d,%d\n", time1, data.size(), data[0].size());

	start = clock();

	RMQ rmq(N*N, D);

	for (int it = 0; it < N - 1; it++) {
		// For each point
		int joiner = 0;
		int joined = 0;
		int index;

		float mindist = rmq.getMin(index);


		joined = index % N;
		joiner = index / N;

		int pi_joined = find(unionFind, joined);
		int pi_joiner = find(unionFind, joiner);

		C[N + it] = C[pi_joined] + C[pi_joiner];

		linkageMatrix.emplace_back(vector<float> {(float)pi_joined, (float)pi_joiner, rmq.get(joiner*N + joined), (float)C[N + it]});

		join(unionFind, joined, N + it);
		join(unionFind, joiner, N + it);

		// Update the row
		for (int j = 0; j < joiner; j++) {
			if (joined > j) {
				//D[joiner*N + j] = min(D[joiner*N + j], D[joined*N + j]);
				rmq.update(joiner*N + j, min(rmq.get(joiner*N + j), rmq.get(joined*N + j)));
			}
			else if (joined < j) {
				// D[joiner*N + j] = min(D[joiner*N + j], D[j*N + joined]);
				rmq.update(joiner*N + j, min(rmq.get(joiner*N + j), rmq.get(j*N + joined)));
			}
		}

		// Update the column
		for (int i = joiner+1; i < N; i++) {
			// D[i*N + joiner] = min(D[i*N + joiner], D[i*N + joined]);
			rmq.update(i*N + joiner, min(rmq.get(i*N + joiner), rmq.get(i*N + joined)));
		}


		// Erase joined column and row by setting them to infinity
		for (int j = 0; j < joined; j++) {
			rmq.update(joined*N + j, numeric_limits<float>::max());
		}
		for (int j = joined + 1; j < N; j++) {
			rmq.update(j*N + joined, numeric_limits<float>::max());
		}
	}

	end  = clock() ;
	float time2 = (float) (end - start) / CLOCKS_PER_SEC;
	printf("naive_optimized,%f,linkage_matrix_build_time,%d,%d\n", time2, data.size(), data[0].size());
	printf("naive_optimized,%f,total_time,%d,%d\n", time1 + time2, data.size(), data[0].size());
}


/*
	This is like computeDissimilarityMatrix but here the matrix is linearized in one vector
	to simplify the range minimum query
*/
void computeDissimilarityVector(vector<float> &D, const vector<vector<float>> &data, distance_func dist) {
	int N = (int) data.size();
	D.clear();
	D.resize(N*N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			D[i*N + j] = numeric_limits<float>::max();
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			D[i*N + j] = dist(data[i], data[j]);
		}
	}
}

void SingleLinkageOptimized::computeDissimilarityMatrix(vector<vector<float>> &D, const vector<vector<float>> &data, distance_func dist) {
	int N = (int) data.size();
	D.clear();
	D.resize(N);
	for (int i = 1; i < N; i++) {
		D[i].resize(i);
		for (int j = 0; j < i; j++) {
			D[i][j] = dist(data[i], data[j]);
		}
	}
}

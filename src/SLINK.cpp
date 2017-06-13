#include "SLINK.h"

using namespace std;

void SLINK::clusterize(const vector<vector<float>> &data, vector<vector<float>> &linkageMatrix, distance_func d) {
	clock_t start = clock();

	int n = data.size();

	vector<float> lambdas(n);
	vector<float> pies(n);
	vector<float> mus(n);

	pies[0] = 0;
	lambdas[0] = numeric_limits<float>::infinity();
	for (int i = 1; i < n; i++) {
		// 1
		pies[i] = i;
		lambdas[i] = numeric_limits<float>::infinity();

		// 2
		for (int j = 0; j < i; j++) {
			mus[j] = d(data[j], data[i]);
		}

		// 3
		for (int j = 0; j < i; j++) {
			if (lambdas[j] >= mus[j]) {
				mus[pies[j]] = min(mus[pies[j]], lambdas[j]);
				lambdas[j] = mus[j];
				pies[j] = i;
			}
			else {
				mus[pies[j]] = min(mus[pies[j]], mus[j]);
			}
		}

		// 4
		for (int j = 0; j < i; j++) {
			if (lambdas[j] >= lambdas[pies[j]]) {
				pies[j] = i;
			}
		}
	}

	clock_t end  = clock() ;
	float time1 = (float) (end - start) / CLOCKS_PER_SEC;
	printf("slink,%f,pointer_representation_build_time,%d,%d\n", time1, n, data[0].size());

	start = clock();

	fromPointerReprToLinkageMatrix(lambdas, pies, linkageMatrix);

	end  = clock() ;
	float time2 = (float) (end - start) / CLOCKS_PER_SEC;
	printf("slink,%f,linkage_matrix_build_time,%d,%d\n", time2, n, data[0].size());
	printf("slink,%f,total_time,%d,%d\n", time1 + time2, n, data[0].size());
}

void SLINK::fromPointerReprToLinkageMatrix(vector<float> lambdas, vector<float> pies, vector< vector<float> > &linkageMatrix) {
	int n = lambdas.size();

	vector<int> unionFind;
	makeSet(unionFind, n*2);

	vector<index_value> ivVector;
	for (int i = 0; i < n; i++) {
		index_value iv = {
			i,
			lambdas[i]
		};
		ivVector.push_back(iv);
	}

	sort(ivVector.begin(), ivVector.end(), [](const index_value &a, const index_value &b) -> bool { 
	    return a.value < b.value; 
	});

	for (int i = 0; i < n - 1; i++) {
		int index = ivVector[i].index;
		float lambda = lambdas[index];
		int pie = pies[index];

		int reprIndex = find(unionFind, index);
		int dimReprIndex = 1;
		if (reprIndex >= n) {
			dimReprIndex = linkageMatrix[reprIndex - n][3];
		} 
		int reprPie = find(unionFind, pie);
		int dimReprPie = 1;
		if (reprPie >= n) {
			dimReprPie = linkageMatrix[reprPie - n][3];
		} 

		linkageMatrix.push_back(vector<float> {(float)reprIndex, (float)reprPie, lambda, (float)(dimReprIndex + dimReprPie)});

		join(unionFind, index, n + i);
		join(unionFind, pie, n + i);
	}
}

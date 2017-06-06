#include "SLINK.h"

using namespace std;

void clusterize(vector< vector<float> > data, vector< vector<float> > &linkageMatrix, distance_func d) {
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

	fromPointerReprToLinkageMatrix(lambdas, pies, linkageMatrix);	
}

void fromPointerReprToLinkageMatrix(vector<float> lambdas, vector<float> pies, vector< vector<float> > &linkageMatrix) {

}

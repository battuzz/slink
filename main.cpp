#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "SLINK.h"
#include "SingleLinkage.h"
#include "Utils.h"

using namespace std;

int main(int argc, char * argv[]) {
	//read_csv(string(argv[1]));
	vector <vector<float> > V;
	readCsv(V, argv[1], ';');

	for (auto v : V) {
		for (auto u : v)
			cout << u << " ";
		cout << endl;
	}
}



#include "Utils.h"

void readCsv(vector< vector<float> > &result, string filename) {
	readCsv(result, filename, ',');
}

// Reads the csv in filename and stores the values in result matrix
void readCsv(vector< vector<float> > &result, string filename, char sep) {
	ifstream file ( filename ); 
	string value;
	string s;

	result.clear();

	while ( file.good() ) {
		vector<float> linevalue(10);
		getline ( file, value, '\n' ); 

		stringstream line(value);

		while (getline(line, s, sep))
			if (isFloat(s))
				linevalue.push_back(toFloat(s));

		result.push_back(linevalue);
	}
}


bool isFloat( string myString ) {
    std::istringstream iss(myString);
    float f;
    iss >> f;
    return !iss.fail(); 
}

float toFloat( string myString ) {
    std::istringstream iss(myString);
    float f;
    iss >> f;
    return f;
}


void makeSet(vector<int> &set) {
	for (int i = 0; i < set.size(); i++)
		set[i] = i;
}

int find(vector<int> &set, int a) {
	if (set[a] == a)
		return a;
	set[a] = find(set, a);
	return set[a];
}

void join(vector<int> &set, int a, int b) {
	int parentA = find(set, a);
	int parentB = find(set, b);
	// Make sure that the biggest number is the representative
	if (parentB > parentA)
		set[parentA] = parentB;
	else
		set[parentB] = parentA;
}
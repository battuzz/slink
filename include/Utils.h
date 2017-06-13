#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath> 
#include <iostream>

using namespace std;

#ifndef UTILS
#define UTILS

void readCsv(vector< vector<float> > &result, string filename);
void readCsv(vector< vector<float> > &result, string filename, char sep);
bool isFloat( string myString );
float toFloat( string myString );

typedef float (*distance_func)(vector<float>, vector<float>);
float manhattanDistance(vector<float>, vector<float>);

void makeSet(vector<int> &set, int size);
int find(vector<int> &set, int a);
void join(vector<int> &set, int a, int b);

void toCsv(vector< vector<float> > &linkageMatrix, string filename);

class RMQ {
private:
	int n;
	vector<float> t;
	vector<int> idx;
	void build();

public:
	RMQ(int size, const vector<float> &initialValues);	// Initialize RMQ data structure

	void update(int p, float value);		// Update value in index p with new value
	float getMin(int &index);				// Get minimum value
	float query(int l, int r, int &index);	// Get minimum value in range
	float get(int p);						// Get value at given index
};

#endif
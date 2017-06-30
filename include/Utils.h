/*
	Utility class
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iostream>

using namespace std;

#ifndef UTILS
#define UTILS

/* Read the csv input file in result */
void readCsv(vector< vector<float> > &result, string filename);

/* Read the csv input file in result and specify csv separator */
void readCsv(vector< vector<float> > &result, string filename, char sep);

bool isFloat( string myString );
float toFloat( string myString );

/* Definition of a distance function to compute the dissimilarity between two points */
typedef float (*distance_func)(vector<float>, vector<float>);

/* Definition of the manhattan distance dissimilarity function */
float manhattanDistance(vector<float>, vector<float>);

/* Disjoint-set (union-find) data structure definition */
void makeSet(vector<int> &set, int size);
int find(vector<int> &set, int a);
void join(vector<int> &set, int a, int b);

/* Write linkage matrix in a csv output */
void toCsv(vector< vector<float> > &linkageMatrix, string filename);


/*
	Segment tree definition for Range Minimum Query
*/
class RMQ {
private:
	int n;			// Number of elements
	vector<float> t;	// a vector of size 2*n that will hold the values
	vector<int> idx;	// a vector of size 2*n that will hold the index values
	void build();

public:
	RMQ(int size, const vector<float> &initialValues);	// Initialize RMQ data structure

	void update(int p, float value);		// Update value in index p with new value
	float getMin(int &index);				// Get minimum value of the whole array
	float query(int l, int r, int &index);	// Get minimum value in range [l,r)
	float get(int p);						// Get value at given index
};

#endif

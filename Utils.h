#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath> 

using namespace std;

void readCsv(vector< vector<float> > &result, string filename);
void readCsv(vector< vector<float> > &result, string filename, char sep);
bool isFloat( string myString );
float toFloat( string myString );

typedef float (*distance_func)(vector<float>, vector<float>);
float manhattanDistance(vector<float>, vector<float>);

void makeSet(vector<int> &set, int size);
int find(vector<int> &set, int a);
void join(vector<int> &set, int a, int b);
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void readCsv(vector< vector<float> > &result, string filename);
void readCsv(vector< vector<float> > &result, string filename, char sep);
bool isFloat( string myString );
float toFloat( string myString );

void makeSet(vector<int> &set);
int find(vector<int> &set, int a);
void join(vector<int> &set, int a, int b);
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void read_csv(vector< vector<float> > &result, string filename);
void read_csv(vector< vector<float> > &result, string filename, char sep);
bool isFloat( string myString );
float toFloat( string myString );
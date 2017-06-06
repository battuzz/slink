#include "Utils.h"

void read_csv(vector< vector<float> > &result, string filename) {
	read_csv(result, filename, ',');
}

// Reads the csv in filename and stores the values in result matrix
void read_csv(vector< vector<float> > &result, string filename, char sep) {
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
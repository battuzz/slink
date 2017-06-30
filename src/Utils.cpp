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
		vector<float> linevalue(0);
		getline ( file, value, '\n' );

		if (value.size() > 0) {

			stringstream line(value);

			while (getline(line, s, sep)){
				if (isFloat(s)) {
					linevalue.push_back(toFloat(s));
				}
			}


			result.push_back(linevalue);
		}
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

float manhattanDistance(vector<float> v1, vector<float> v2) {
	float result = 0;
	for (int i = 0; i < v1.size(); i++) {
		result += abs(v1[i] - v2[i]);
	}
	return result;
}

void makeSet(vector<int> &set, int size) {
	set.resize(size);
	for (int i = 0; i < size; i++)
		set[i] = i;
}

int find(vector<int> &set, int a) {
	if (set[a] == a)
		return a;
	set[a] = find(set, set[a]);
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

void toCsv(vector< vector<float> > &linkageMatrix, string filename) {
	// Create file
	ofstream myfile;
	myfile.open (filename);

	// Write column names
	myfile << "Repr_1,";
	myfile << "Repr_2,";
	myfile << "Lambda,";
	myfile << "Size" << endl;

	// Write data
	for (auto row : linkageMatrix) {
		myfile << row[0] << ",";
		myfile << row[1] << ",";
		myfile << row[2] << ",";
		myfile << row[3] << endl;
	}

	myfile.close();
}

RMQ::RMQ(int size, const vector<float> &initialValues) {
	n = size;
	t.resize(2 * n);
	idx.resize(2 * n);

	for (int i = 0; i < n; i++) {
		t[n + i] = initialValues[i];
		idx[n + i] = i;
	}
	this->build();
}

/*
	Build the segment tree parent nodes to be the minimum of both children.
*/
void RMQ::build() {
	for (int i = n - 1; i > 0; --i) {
		if (t[i<<1] < t[i<<1|1]) { // The left child is minimum
			t[i] = t[i<<1];
			idx[i] = idx[i<<1];
		}
		else {			// The right child is minimum
			t[i] = t[i<<1|1];
			idx[i] = idx[i<<1|1];
		}
	//t[i] = min(t[i<<1], t[i<<1|1]);
	}
}

void RMQ::update(int p, float value) {  // set value at position p
	p += n;
	t[p] = value;

	for (; p > 1; p >>= 1) {
		if (t[p] < t[p^1]) {
			t[p>>1] = t[p];
			idx[p>>1] = idx[p];
		}
		else {
			t[p>>1] = t[p^1];
			idx[p>>1] = idx[p^1];
		}
		// t[p>>1] = min(t[p], t[p^1]);
	}
}
float RMQ::getMin(int &index) {
	index = idx[1];
	return t[1];
}

float RMQ::query(int l, int r, int &index) {  // sum on interval [l, r)
	float res = 0;

	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) {
			if (t[l] < res) {
				index = idx[l];
				res = t[l];
			}
			l++;
			// res = min( res, t[l++] );
		}
		if (r&1) {
			r--;
			if (t[r] < res) {
				res = t[r];
				index = idx[r];
			}
			// res = min( res, t[--r] );
		}
	}
	return res;
}

float RMQ::get(int p) {
	return t[n + p];
}

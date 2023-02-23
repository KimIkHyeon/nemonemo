//nemonemo header

#ifndef NEMO_H
#define NEMO_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

static string filepath("test.txt");
static string inputfile("input.txt");

class Nemologic {
private:
	int size;
	vector< vector<char> > matrix;
	vector< vector<int> > vertical;
	vector< vector<int> > horizon;

public:
	Nemologic();
	~Nemologic();
	void printMatrix();
	void writeAspect();
	void readAspect();
	inline int matSize() { return size; };
};

vector<int> putNum(string);

#endif

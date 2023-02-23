//nemonemo header

#ifndef NEMO_H
#define NEMO_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

static string filepath("test.txt");

class Nemologic {
private:
	int size;
	vector< vector<char> > matrix;
public:
	Nemologic();
	~Nemologic();
	void printMatrix();
};

/*
class Nemologic{
private:
    int size;

public:
    Nemologic();
};*/

#endif

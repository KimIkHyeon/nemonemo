//nemonemo header

#ifndef NEMO_H
#define NEMO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define SP 10000
#define NO 10001
#define OK 10002
#define DONT 10003

using namespace std;

const string writefilepath("test.txt");
const string readfilepath("input.txt");

class Nemologic{
private:
    int size;
	vector< vector<int> > map;
	int solveNum;

public:
    Nemologic();
	void printMap();
	void checkFullMap();
	void inputVH(string, int, bool);
	void solveStart();


private:
	vector< vector<int> > initMap();
	void printFullMap();
	void inputNum();
	void solveLogic();
	void solveV(vector< vector<int> >&, vector< vector<int> >&, vector< vector<int> >&);
	void solveH(vector< vector<int> >&, vector< vector<int> >&, vector< vector<int> >&);
	vector<int> putLine(vector<int>, vector<int>&);
};

void printOX(int);


#endif

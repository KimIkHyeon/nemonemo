#include "nemo.hpp"

using namespace std;

//get size and do init map
Nemologic::Nemologic()
{
	int t;
	cout << "Enter the size : ";
	cin >> t;

	Nemologic::size = t;
	Nemologic::solveNum = 0;

	Nemologic::map = Nemologic::initMap();

	Nemologic::inputNum();
}

void Nemologic::inputNum()
{
	string line;
	int vh = 0;
	ifstream rfile(readfilepath.data());
	if (!rfile.is_open()) {
		cout << "Can't open read file" << endl;
		return;
	}

	while(getline(rfile, line)) {
		vh++;
		if (vh < Nemologic::size+1) {
			Nemologic::inputVH(line, vh+Nemologic::size, 1);
		}
		else if (vh < Nemologic::size*2+1) {
			Nemologic::inputVH(line, vh, 0);
		}

	}

	rfile.close();
}

void Nemologic::inputVH(string line, int t, bool cvh)
{
	int tn;
	int num = 0;
	vector<int> v;

	for (int i = 0; i < line.size(); i++) {
		if (line[i] == ' ') {
			v.push_back(num);
			num = 0;
			continue;
		}
		int x = (int)line[i] - '0';
		num *= 10;
		num += x;
	}

	v.push_back(num);
	tn = Nemologic::size - v.size() + 1;
	for (int i = 0; i < v.size(); i++) {
		if(cvh == 0) Nemologic::map[t][tn] = v[i];
		else Nemologic::map[tn][t] = v[i];
		tn++;
	}
}

vector< vector<int> > Nemologic::initMap()
{
	vector< vector<int> > tm(Nemologic::size*2+2, vector<int>(Nemologic::size*2+2, NO));
	
	for (int i = Nemologic::size+1; i <= Nemologic::size*2; i++) {
		for (int j = Nemologic::size+1; j <= Nemologic::size*2; j++) {
			tm[i][j] = SP;
		}
	}
	
	return tm;
}


//print all map(Even the useless parts) for frequent check
void Nemologic::printFullMap()
{
	ofstream wfile(writefilepath.data());
	if(!wfile.is_open()) {
		cout << "Can't open write file" << endl;
		return;
	}

	wfile << endl << endl << endl;
	
	for (int i = 0; i < Nemologic::size*2+2; i++) {
		for (int j = 0; j < Nemologic::size*2+2; j++) {
			switch (Nemologic::map[i][j])
			{
				case NO:
					wfile << "X" << " ";
					break;
				case OK:
					wfile << "O" << " ";
					break;
				case SP:
					wfile << "H" << " ";
					break;
				default:
					wfile << Nemologic::map[i][j] << " ";
					break;
			}
		}
		wfile << endl;
	}

	wfile << endl << endl << endl;

	wfile.close();
}

void Nemologic::checkFullMap()
{
	Nemologic::printFullMap();
}

void Nemologic::printMap()
{
	int s = Nemologic::size;
	
	ofstream wfile(writefilepath.data());
	if(!wfile.is_open()) {
		cout << "Can't open write file" << endl;
		return;
	}
	
	wfile << endl << endl << endl;
	
	for (int i = s+1; i < s*2+1; i++) {
		for (int j = s+1; j < s*2+1; j++) {
			switch(Nemologic::map[i][j])
			{
				case NO:
					wfile << "X" << " ";
					break;
				case OK:
					wfile << "O" << " ";
					break;
				case SP:
					wfile << "H" << " ";
					break;
				default:
					wfile << Nemologic::map[i][j] << " ";
					break;
			}
		}
		wfile << endl;
	}

	wfile << endl << endl << endl;


	wfile.close();
}

vector<int> Nemologic::putLine(vector<int> tline, vector<int>& num)
{
	vector<int> rtn;


	return rtn;
}

void Nemologic::solveV(vector< vector<int> >& tmap, vector< vector<int> >& vv, vector< vector<int> >& hh)
{
	vector<int> tline(Nemologic::size+2, NO);
	vector<int> result;

	for (int i = 0; i < Nemologic::size; i++) {
		for(int j = 0; j < Nemologic::size; j++) {
			tline[j+1] = tmap[j][i];
			result = putLine(tline, vv[j]);
		}
		
		for(int j = 0; j < Nemologic::size; j++) {
			//tmap[j][i] = result[j];
			tmap[j][i] = NO;
		}
	}
}

void Nemologic::solveH(vector< vector<int> >& tmap, vector< vector<int> >& vv, vector< vector<int> >& hh)
{
	vector<int> tline(Nemologic::size+2, NO);
	vector<int> result;

	for (int i = 0; i < Nemologic::size; i++) {
		for(int j = 0; j < Nemologic::size; j++) {
			tline[j+1] = tmap[i][j];
			result = putLine(tline, vv[j]);
		}
		
		for(int j = 0; j < Nemologic::size; j++) {
			//tmap[i][j] = result[j];
			tmap[i][j] = NO;
		}
	}
}


void Nemologic::solveLogic()
{
	vector< vector<int> > tmap(Nemologic::size, vector<int>(Nemologic::size, SP));
	vector< vector<int> > vv;
	vector< vector<int> > hh;
	

	for (int i = Nemologic::size+1; i < Nemologic::size*2+1; i++) {
		int tmp = Nemologic::size;
		vector<int> vtemp;
		vector<int> htemp;
		
		while (Nemologic::map[tmp][i] != NO) {
			vtemp.push_back(Nemologic::map[tmp][i]);
			tmp--;
		}

		tmp = Nemologic::size;
		while (Nemologic::map[i][tmp] != NO) {
			htemp.push_back(Nemologic::map[i][tmp]);
			tmp--;
		}

		vv.push_back(vtemp);
		hh.push_back(htemp);

		
	}
	
	Nemologic::solveV(tmap, vv, hh);
/*
	while (Nemologic::solveNum < Nemologic::size) {

	}
	*/

	for (int i = 0; i < Nemologic::size; i++) {
				for (int j = 0; j < Nemologic::size; j++) {
					printOX(tmap[i][j]);
				}
				cout << endl;
			}

}

void Nemologic::solveStart()
{
	Nemologic::solveLogic();
}

void printOX(int t)
{
	switch(t)
	{
		case NO:
			cout << "X" << " ";
			break;
		case OK:
			cout << "O" << " ";
			break;
		case SP:
			cout << "H" << " ";
			break;
		default:
			cout << t << " ";
			break;
	}
}




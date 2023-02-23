#include "nemo.hpp"

using namespace std;

Nemologic::Nemologic()
{
	vector<char> temp;
	
	cout << "로직 사이를 입력하십시오(ex.5, 10, 20, 25) : ";
	cin >> Nemologic::size;
	
	for (int i = 0; i < Nemologic::size; i++){
		temp.push_back('H');
	}
	
	for (int i = 0; i < Nemologic::size; i++){
		matrix.push_back(temp);
	}
}

Nemologic::~Nemologic()
{
	
}

vector<int> putNum(string str)
{
	vector<int> v;
	int t = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			v.push_back(t);
			t = 0;
			continue;
		}
		int x = (int)str[i] - '0';
		t *= 10;
		t += x;
	}
	
	v.push_back(t);
	
	return v;
}

void Nemologic::readAspect()
{
	string line;
	int i = 0;
	bool vh = 0;
	
	ifstream rfile(inputfile.data());
	if(!rfile.is_open()) {
		cout << "Can't open read file" << endl;
		return;
	}

	while (getline(rfile, line)){
		
		if (vh == 0) Nemologic::vertical.push_back(putNum(line));
		else Nemologic::horizon.push_back((putNum(line)));

		i++;
		if (i == Nemologic::size) {
			i = 0;
			vh = 1;
		}
	}
	
	cout << "vertical"  << endl;
	

	for (int i = 0; i < Nemologic::vertical.size(); i++) {
		for (int j = 0; j < Nemologic::vertical[i].size(); j++) {
			cout << Nemologic::vertical[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "horizen" << endl;
	
	for (int i = 0; i < Nemologic::horizon.size(); i++) {
		for (int j = 0; j < Nemologic::horizon[i].size(); j++) {
			cout << Nemologic::horizon[i][j] << " ";
		}
		cout << endl;
	}
	
	rfile.close();
}


void Nemologic::writeAspect()
{
	
}

void Nemologic::printMatrix()
{
	ofstream wfile(filepath.data());
	if(!wfile.is_open()) {
		cout << "Can't open write file" << endl;
		return;
	}
	for (int i = 0; i < Nemologic::size; i++){
		for (int j = 0; j < Nemologic::size; j++) {
			wfile << matrix[i][j] << " ";
		}
		
		for (int t = 0; t < Nemologic::horizon[i].size(); t++){
			wfile << Nemologic::horizon[i][t] << " ";
		}
		wfile << endl;
	}
	
	//////////////////////think!! how to write vertical 
	
//	for (int i = 0; i < Nemologic::size; i++) {
//		for(int j = 0; j < Nemologic::size; j++){
//			if(Nemologic.)
//		}
//	}

	wfile.close();
}

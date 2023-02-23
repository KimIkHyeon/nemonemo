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

void Nemologic::printMatrix()
{
//	ofstream wfile("test.txt");
	ofstream wfile(filepath.data());
	if(!wfile.is_open()) return;
	for (int i = 0; i < Nemologic::size; i++){
		for (int j = 0; j < Nemologic::size; j++) {
			wfile << matrix[i][j] << " ";
		}
		wfile << endl;
	}
}

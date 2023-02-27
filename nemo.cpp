#include "nemo.hpp"

using namespace std;

//get size and do init map
Nemologic::Nemologic()
{
	int t;
	cout << "Enter the size : ";
	cin >> t;

	Nemologic::size = t;

	Nemologic::map = Nemologic::initMap();
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

	wfile << Nemologic::size << endl;
	
	for (int i = 0; i < Nemologic::size*2+2; i++) {
		for (int j = 0; j < Nemologic::size*2+2; j++) {
			switch (map[i][j])
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
					break;
			}
		}
		wfile << endl;
	}

	wfile.close();
}

void Nemologic::checkFullMap()
{
	Nemologic::printFullMap();
}

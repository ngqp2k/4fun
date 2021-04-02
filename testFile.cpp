#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main() {
	ifstream fi("score.dat");
	ofstream fo("score.dat", ios::app);

	fo << "\nuseNew#10";

	string st = "ngqp2k";
	while (!fi.eof()) {
		getline(fi, st);
		cout << st << "\n";
	}
	
	system("pause");
	fi.close();
	fo.close();
	return 0;
}
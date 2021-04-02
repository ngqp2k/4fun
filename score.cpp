#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std; 

int convertToInt(string s) {
	int res = 0;
	s += ' ';
	int i = 0;
	while (s[i] != ' ') {
		res = res * 10 + s[i] - '0';
		i++;
	}
	return res;
}

bool cmp(pair<string, int> p1, pair<string, int> p2) {
	return p1.second > p2.second;
}

void showScore() {
	ifstream fi("score.txt");
	// update score
	vector< pair<string, int> > a;

	string s;
	while (!fi.eof()) {
		fi >> s;
		string userName = s.substr(0, s.find('#'));
		int score = convertToInt(s.substr(s.find('#') + 1, s.length()));
		a.push_back(make_pair(userName, score));
	}

	sort(a.begin(), a.end(), cmp);
	//for (int i = 0; i < (int)a.size(); ++i)
		//cout << a[i].first << " " << a[i].second << "\n";

	fi.close();
}

int main() {
	showScore();
	system("pause");
	return 0;
}
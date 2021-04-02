#include "graphics.h"
#pragma comment(lib, "graphics.lib")
#include <ctime>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 8, M = 12;
const int X = 440, Y = 250, W = 50; // xBegin, yBegin, width
int u_old = 0,v_old = 0;
vector< vector<int> > f(N + 2, vector<int> (M + 2, 0));
vector< int > cnt(20, 0);

//draw
void squareDw(int x, int y){
	rectangle(x, y, x + W, y + W);
//	cout << x << " " << y << " " << x + width << " " << y + width << "\n";
}

void del_bdDw(int u, int v);

void bdDw(int u, int v){
	del_bdDw(u_old, v_old);
	u_old = u, v_old = v;
	if (f[u][v] == 0)
		return;
	int x = X + (v - 1) * (W + 10) + (W / 2);
	int y = Y + (u - 1) * (W + 10) + (W / 2);
	int k = W / 2 + 2;
	int len = W/4;
	setcolor(15);

	line(x + k, y - k, x + k - len, y - k);
	line(x + k, y - k, x + k, y - k + len);

	line(x + k, y + k, x + k, y + k - len);
	line(x + k, y + k, x + k - len, y + k);

	line(x - k, y + k, x - k, y + k - len);
	line(x - k, y + k, x - k + len, y + k);

	line(x - k, y - k, x - k, y - k + len);
	line(x - k, y - k, x - k + len, y - k);
}

void del_bdDw(int u, int v){
	if (f[u][v] == 0)
		return;
	int x = X + (v - 1) * (W + 10) + (W / 2);
	int y = Y + (u - 1) * (W + 10) + (W / 2);
	int k = W / 2 + 2;
	int len = W/4;
	setcolor(0);

	line(x + k, y - k, x + k - len, y - k);
	line(x + k, y - k, x + k, y - k + len);

	line(x + k, y + k, x + k, y + k - len);
	line(x + k, y + k, x + k - len, y + k);

	line(x - k, y + k, x - k, y + k - len);
	line(x - k, y + k, x - k + len, y + k);

	line(x - k, y - k, x - k, y - k + len);
	line(x - k, y - k, x - k + len, y - k);
}

void delDw(int u, int v){
	int x = X + (v - 1) * (W + 10) + (W / 2);
	int y = Y + (u - 1) * (W + 10) + (W / 2);
	setfillstyle(1,0);
	int k = W / 2 + 5;
	bar(x - k, y - k, x + k, y + k);
}

void dwBack() {
	setcolor(15);
	rectangle(10, 10, 100, 60);
	setfillstyle(1, BLUE);
	floodfill(55, 40, 15);

	setcolor(15);
	setbkcolor(BLUE);
	settextstyle(10, 0, 3);
	settextjustify(1, 1);
	outtextxy(55, 40, "Back");
	setbkcolor(0);
	setcolor(15);
}


//solve
void initF();

void layoutGame();

void useMouseGame();

void print(){
	for(int i = 0; i <= N + 1; ++i){
		for(int j = 0; j <= M + 1; ++j)
			cout << f[i][j] << "   ";
		cout << "\n";
	}
}

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

void layoutMenu();

void layoutHighScore();

void showScore();

bool check1(int x1, int y1, int x2, int y2){ // x1 = x2 OF y1 = y2
	cout << "Check 1: " << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
	if (x1 != x2 && y1 != y2)
		return false;
	// check col (y1 = y2)
	if (y1 == y2){
		if (x1 > x2)
			swap(x1, x2);
		for(int i = x1 + 1; i <= (x2 - 1); ++i) // 6 9 7 9, i = 7, 7 <= 6
			if (f[i][y1] != 0)
				return false;
	}
	
	//check row (x1 = x2);
	if(x1 == x2){
		if (y1 > y2)
			swap(y1, y2);
		for(int i = y1 + 1; i <= (y2 - 1); ++i) 
			if (f[x1][i] != 0)
			return false;
	}
	return true;
}
bool check2(int x1, int y1, int x2, int y2){
	if (y1 > y2){
		swap(y1, y2);
		swap(x1, x2);
	}

	// TH rieng
	if (x1 + 1 == x2 && y1 + 1 == y2)
		if (f[x1][y2] != 0 && f[x2][y1] != 0)
			return false;
		else;
	else
		if (x1 - 1 == x2 && y1 + 1 == y2)
			if (f[x2][y1] != 0 && f[x1][y2] != 0)
				return false;

	bool b1=true;
	if (x1 < x2)
		if (check1(x1, y1, x2 + 1, y1) && check1(x2, y1, x2, y2) ||
				check1(x1, y1, x1, y2 + 1) && check1(x1, y2, x2, y2))
		return true;

	if (x1 > x2)
		if (check1(x1, y1, x2 - 1, y1) && check1(x2, y1, x2, y2) ||
			  check1(x1, y1, x1, y2 + 1) && check1(x1, y2, x2, y2))
		return true;
  return false;
}
bool check3(int x1, int y1, int x2, int y2){
	if (y1 > y2){
		swap(y1, y2);
		swap(x1, x2);
	}
	// Tren
	for(int i=x1 - 1;i >= 0; i--){
		if(f[i][y1] != 0)
			break;
		if (check2(i, y1, x2, y2))
			return true;
	}
	// Phai
	for(int i = y1 + 1; i <= M + 1;++i){
		if (f[x1][i] != 0)
			break;
		if (check2(x1, i, x2, y2))
			return true;
	}
	// Duoi
	for(int i=x1 + 1;i<=N + 1;++i){
		if (f[i][y1] != 0)
			break;
		if (check2(i, y1, x2, y2)) // 6 5 6 8 -> check2(7 5 -> 6 8);
			return true;
	}
	// Trai
	for(int i=y1-1;i>=0;i--){
		if(f[x1][i] != 0)
			break;
		if (check2(x1, i, x2, y2))
			return true;
	}
	return false;
}

void checkPoint(int x1, int y1, int x2, int y2){
	if (x1 == x2 && y1 == y2)
		return;
	bool res = false;
	if (f[x1][y1] != f[x2][y2])
	{
		cout << "NO_T\n";
		del_bdDw(u_old, v_old);
		return;
	}
	if (check1(x1, y1, x2, y2))
		res = true;
	else if (check2(x1, y1, x2, y2))
			res = true;
	else if (check3(x1, y1, x2, y2))
			res = true;

	if (res){
		cout << "YES\n";
		// xoa x1, y1;
		delDw(x1, y1);
		// xoa x2, y2
		delDw(x2, y2);
		f[x1][y1] = 0;
		f[x2][y2] = 0;
	}
	else{
		cout << "NO\n";
		del_bdDw(u_old, v_old);

	}

}

void solveAl(){
	int x1, y1, x2, y2;
	print();
	while(1){
	  cout << "Enter: ";
	  cin >> x1 >> y1 >> x2 >> y2;
		checkPoint(x1,y1,x2,y2);
		print();
	}
}

int main(){
	int gd = DETECT, gm;
	//initgraph(&gd, &gm, "");
	initwindow(1600, 900);

	initF();
	print();
	layoutMenu();


//	getch();
	closegraph();
	return 0;
}

void initF(){
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			f[i][j] = rand() % 6 + 1;
}

void layoutGame(){
	cleardevice();
	dwBack();
	setbkcolor(0);
	setcolor(15);
	int x = X, y = Y;
	for(int i = 1; i <= N; ++i){
		for (int j = 1; j <= M; ++j) {
				squareDw(x, y);
				int color = f[i][j];
				setfillstyle(1, color);
				floodfill(x + (W / 2), y + (W / 2), 15);
				x += W + 10;
		}
		x = X;
		y += W + 10;
	}

	// use mouse
	vector<int> a;
	int u, v;
	while (1) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			int x, y;
			//updateLayout();
			getmouseclick(WM_LBUTTONDOWN, x, y);
			// x, y da co gia tri
			// xBegin = 200, yBegin = 150
			// x_tmp = 200, y_tmp = 150
			if (10 <= x && x <= 100 && 10 <= y && y <= 60) {
				layoutMenu();
			}
			int x_tmp = X, y_tmp = Y;
			int i = 1, j = 1;
			for (; i <= N; ++i) {
				;
				for (j = 1; j <= M; ++j) {
					if (x_tmp <= x && x <= x_tmp + W && y_tmp <= y && y <= y_tmp + W) {
						cout << i << " " << j << "\n";
						//	updateLayout2();
						goto tt;
					}
					x_tmp += W + 10;
				}
				x_tmp = X;
				y_tmp += W + 10;
			}
			del_bdDw(u_old, v_old);
			i = -1, j = -1;
		tt:
			if (i != -1 && j != -1) {
				bdDw(i, j); // ve border
				a.push_back(i);
				a.push_back(j);
				for (int ii = 0; ii<(int)a.size(); ++ii)
					cout << a[ii] << " ";
				if (a.size() == 4) {
					checkPoint(a[0], a[1], a[2], a[3]);
					print();
					a.clear();
				}
			}
			else {
				a.clear();
			}
		}
	}
}

void useMouseGame(){
	vector<int> a;
	int u, v;
	while(1){
		if (ismouseclick(WM_LBUTTONDOWN)){
			int x, y;
			//updateLayout();
			getmouseclick(WM_LBUTTONDOWN, x, y);
			// x, y da co gia tri
			// xBegin = 200, yBegin = 150
			// x_tmp = 200, y_tmp = 150
			int x_tmp = X, y_tmp = Y;
			int i=1,j=1;
			for(;i<=N;++i){
				;
				for(j=1;j<=M;++j){
					if (x_tmp <= x && x <= x_tmp + W && y_tmp <= y && y <= y_tmp + W){
						cout << i << " " << j << "\n";
					//	updateLayout2();
						goto tt;
					}
					x_tmp += W + 10;
				}
				x_tmp = X;
				y_tmp += W + 10;
			}
			del_bdDw(u_old, v_old);
			i = -1, j = -1;
tt:
			if (i != -1 && j != -1){
				bdDw(i, j); // ve border
				a.push_back(i);
				a.push_back(j);
				for(int ii=0;ii<(int)a.size();++ii)
					cout << a[ii] << " ";
				if (a.size() == 4){
					checkPoint(a[0], a[1], a[2], a[3]);
					print();
					a.clear();
				}
			}
			else{
				a.clear();
			}
		}
	}
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
		getline(fi, s);
		string userName = s.substr(0, s.find('#'));
		int score = convertToInt(s.substr(s.find('#') + 1, s.length()));
		a.push_back(make_pair(userName, score));
	}

	sort(a.begin(), a.end(), cmp);

	//show screen

	int x = 600, y = 300;
	settextjustify(0, 0);

	for (int i = 0; i < 5; ++i) {
		setcolor(WHITE);
		settextstyle(10, 0, 3);
		if (i == 0) {
			setcolor(YELLOW);
			settextstyle(10, 0, 4);
		}
		char *ch = &a[i].first[0];
		outtextxy(x, y, ch);
		x = 950;

		string st = to_string(a[i].second);
		char *ch2 = &st[0];
		outtextxy(x, y, ch2);

		x = 600;
		y += 50;
	}

	fi.close();
}

void layoutMenu() {
	cleardevice();
	setbkcolor(BLACK);
	setcolor(15);

	int xBegin = 600, yBegin = 250;
	int height = 100, width = 400;

	settextstyle(10, 0, 4);
	settextjustify(1, 1);
	setbkcolor(BLUE);

	// New game
	rectangle(xBegin, yBegin, xBegin + width, yBegin + height);
	setfillstyle(1, BLUE);
	floodfill(xBegin + width / 2, yBegin + height / 2, 15);
	outtextxy(xBegin + width / 2, yBegin + height / 2 + 10, "New game");


	// High Score
	yBegin += height + 30;
	rectangle(xBegin, yBegin, xBegin + width, yBegin + height);
	setfillstyle(1, BLUE);
	floodfill(xBegin + width / 2, yBegin + height / 2, 15);
	outtextxy(xBegin + width / 2, yBegin + height / 2 + 10, "High Score");

	// Quit
	yBegin += height + 30;
	rectangle(xBegin, yBegin, xBegin + width, yBegin + height);
	setfillstyle(1, BLUE);
	floodfill(xBegin + width / 2, yBegin + height / 2, 15);
	outtextxy(xBegin + width / 2, yBegin + height / 2 + 10, "Quit");

	setcolor(15);
	setbkcolor(0);

	// use mouse
	while (1) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			int x, y;
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if (xBegin <= x && x <= xBegin + width) {
				if (250 <= y && y <= 350) {
					//new game
					cout << "New game\n";
					layoutGame();
				}
				if (380 <= y && y <= 480) {
					// high score
					cout << "High score\n";
					layoutHighScore();
				}
				if (510 <= y && y <= 610) {
					exit(0);
				}
			}
		}
	}
}

void layoutHighScore() {
	setbkcolor(0);
	cleardevice();

	// back
	dwBack();

	// main
	setbkcolor(0);
	int x = getmaxx() / 2;
	int y = 150;
	setcolor(CYAN);
	settextstyle(10, 0, 6);
	settextjustify(1, 1);
	outtextxy(x, y, "HIGH SCORE");

	showScore();

	// use mouse
	while (1) {
		int x, y;
		if (ismouseclick(WM_LBUTTONDOWN)) {
			int x, y;
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if (10 <= x && x <= 100 && 10 <= y && y <= 60) {
				layoutMenu();
			}
		}
	}
}
#include"graphics.h"
#pragma comment(lib, "graphics.lib")

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
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

void layoutEnterUsename();

string useEnterName() {
	layoutEnterUsename();
	int x = getmaxx() / 2;
	int y = getmaxy() / 2;
	setcolor(15);
	string st;
	char *charr;
	while (1) {
		char c = getch();
		switch (c)
		{
		case 8: // backspace
			if (st.length() == 0) {
				break;
			}
			st.pop_back();
			charr = &st[0];
			cleardevice();
			layoutEnterUsename();

			settextjustify(0, 0);
			settextstyle(10, 0, 4);
			outtextxy(x - 60, y - 60, charr);
			break;

		case 13: // enter
						 // check name
			if (false) {
				settextstyle(8, 0, 3);
				settextjustify(1, 1);
				setcolor(LIGHTRED);
				outtextxy(x, y - 160, "Ten nguoi choi da ton tai");
				setcolor(WHITE);
			}
			// check length
			if (st.size() > 15) {
				settextstyle(8, 0, 3);
				settextjustify(1, 1);
				setcolor(LIGHTRED);
				outtextxy(x, y - 160, "So ky tu tu 1 ~ 15");
				setcolor(WHITE);
			}
			else
				return st;
			break;

		case 27: // escape
			return "Null";
			break;

		default:
			st.push_back(c);
			charr = &st[0];

			settextstyle(10, 0, 4);
			settextjustify(0, 0);
			outtextxy(x - 60, y - 60, charr);
			break;
		}
	}
}

void layoutMenu();

void layoutHighScore();

void showScore();


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
}

int main() {
	initwindow(1600, 900);

	layoutMenu();

	getch();
	closegraph();
	return 0;
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

	// use mouse
	while (1) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			int x, y;
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if (xBegin <= x && x <= xBegin + width) {
				if (250 <= y && y <= 350) {
					//new game
					cout << "New game\n";
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

void layoutEnterUsename() {
	// layout enter usename

	int x = getmaxx() / 2;
	int y = getmaxy() / 2;
	rectangle(x - 400, y - 150, x + 400, y);

	settextjustify(0, 0);
	settextstyle(10, 0, 4);
	setcolor(3);
	outtextxy(x - 370, y - 60, "Nhap ten: ");

	setcolor(15);

	//// layout play
	//rectangle(x - 100, y + 10, x + 100, y + 110);
	//setfillstyle(1, GREEN);
	//setbkcolor(GREEN);
	//floodfill(x - 100 + 10, y + 10 + 10, 15);
	//settextjustify(1, 1);
	//outtextxy(x, y + 70, "PLAY");
	//setbkcolor(0);

	//use mouse
}
#include "graphics.h"
#pragma comment(lib, "graphics.lib")
#include<iostream>
#include<string>

#define MAX_INPUT_LEN 80



using namespace std;

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

int main() {
	initwindow(1600, 900);

	layoutEnterUsename();
	//cout << useEnterName() << "\n";
	string newst = useEnterName();
	auto 

	getch();
	closegraph();
	return 0;
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
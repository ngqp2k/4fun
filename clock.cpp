//#include "graphics.h"
//#pragma comment(lib, "graphics.lib")
//
//using namespace std;
//
//void layoutClock() {
//	int cntSec = 20; // 180 giay
//	int x = getmaxx() / 2;
//	int y = 100;
//
//	setfillstyle(1, CYAN);
//	setcolor(15);
//	rectangle(x - 500 - 2, y - 2, x + 500, y + 20);
//	bar(x - 500, y, x + 500, y + 20);
//
//	int xx = x + 500;
//	setfillstyle(1, 0);
//	for (int i = 0; i <= cntSec; ++i) {
//		delay(1000);
//		bar(xx, y, xx - 50, y + 20);
//		xx -= 49;
//	}
//}
//
//int main() {
//	initwindow(1600, 900);
//
//	layoutClock();
//
//	getch();
//	closegraph();
//	return 0;
//}
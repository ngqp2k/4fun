#include "graphics.h"
#pragma comment(lib, "graphics.lib")

void menu_PlayGame()
{
	settextstyle(10, 0, 5); setcolor(14);
	outtextxy(58, 40, "PIKACHU CO DIEN");
	setcolor(13);
	for (int x = 50; x < 500; x++)
	{
		line(50, 100, x, 100);
		line(50, 500, x, 500);
		line(50, 101, x, 101);
		line(50, 501, x, 501);
		delay(0.5);
	}
	for (int y = 100; y < 500; y++)
	{
		line(50, 100, 50, y);
		line(500, 100, 500, y);
		line(51, 100, 51, y);
		line(501, 100, 501, y);
		delay(0.5);
	}
}
int main() {
	int gd = 0, gm;
	//initgraph(&gd, &gm, "");
	initwindow(600, 700);

	menu_PlayGame();

	getch();
	closegraph();
	return 0;
}
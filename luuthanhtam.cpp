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
	setbkcolor(15);
	settextstyle(10, 0, 5); setcolor(RED);
	outtextxy(510, 140, "SCORE");
	settextstyle(10, 0, 5); setcolor(RED);
	outtextxy(530, 300, "TIME");
}
void menu()
{
	settextstyle(0, 0, 0); setcolor(11);
	line(320, 0, 320, 200);
	line(320, 200, getmaxx(), 200);
	line(321, 1, 321, 201);
	line(321, 201, getmaxx(), 201);
	for (int i = 1; i < 5; i++)
	{
		setcolor(i);
		outtextxy(350, 5, "DE TAI: GAME PIKACHU CO DIEN");
		delay(100);
		i++;
	}
	setcolor(13);
	outtextxy(340, 30, "Thanh Vien:");
	setcolor(15);
	outtextxy(345, 60, "1. Thanh Tam");
	outtextxy(345, 90, "2. Quang Phu");
	outtextxy(345, 120, "3. Kieu Oanh");
	outtextxy(345, 150, "4. Do Huy");
	settextstyle(4, 0, 5); setcolor(14);
	outtextxy(10, 100, "PIKACHU");
	settextstyle(1, 0, 2);
	setcolor(15);
	outtextxy(255, 230, "NEW GAME");
	outtextxy(290, 260, "SCORE");
	outtextxy(305, 290, "HELP");
	outtextxy(290, 320, "ABOUT");
	outtextxy(310, 350, "EXIT");
}
void menu1(int &x, int &y)
{
	menu();
	if (ismouseclick(WM_MOUSEMOVE))
	{
		getmouseclick(WM_MOUSEMOVE, x, y); // lay toa do vi tri con tro	
		if ((y >= 230 && y <= 260) && (x >= 255 && x <= 450))
		{
			settextstyle(1, 0, 2);
			setcolor(14);
			outtextxy(255, 230, "NEW GAME");
			settextstyle(1, 0, 2);
			setcolor(15);
			outtextxy(290, 260, "SCORE");
			outtextxy(305, 290, "HELP");
			outtextxy(290, 320, "ABOUT");
			outtextxy(310, 350, "EXIT");
		}
		else if ((y >= 260 && y <= 290) && (x >= 255 && x <= 450))
		{
			restorecrtmode();
			settextstyle(1, 0, 2);
			setcolor(15);
			outtextxy(255, 230, "NEW GAME				");
			settextstyle(1, 0, 2);
			setcolor(14);
			outtextxy(290, 260, "SCORE		");
			settextstyle(1, 0, 2);
			setcolor(15);
			outtextxy(305, 290, "HELP			");
			outtextxy(290, 320, "ABOUT			");
			outtextxy(310, 350, "EXIT");
		}
		else if ((y >= 290 && y <= 320) && (x >= 255 && x <= 450))
		{
			settextstyle(1, 0, 2);
			setcolor(15);
			outtextxy(255, 230, "NEW GAME");
			outtextxy(290, 260, "SCORE");
			settextstyle(1, 0, 2);
			setcolor(14);
			outtextxy(305, 290, "HELP");
			settextstyle(1, 0, 2);
			setcolor(15);
			outtextxy(290, 320, "ABOUT");
			outtextxy(310, 350, "EXIT");
		}
		else if ((y >= 320 && y <= 350) && (x >= 255 && x <= 450))
		{
			settextstyle(1, 0, 2);
			setcolor(15);
			outtextxy(255, 230, "NEW GAME");
			outtextxy(290, 260, "SCORE");
			outtextxy(305, 290, "HELP");
			settextstyle(1, 0, 2);
			setcolor(14);
			outtextxy(290, 320, "ABOUT");
			settextstyle(1, 0, 2);
			setcolor(15);
			outtextxy(310, 350, "EXIT");
		}
		else if ((y >= 350 && y <= 380) && (x >= 255 && x <= 450))
		{
			settextstyle(1, 0, 2);
			setcolor(15);
			outtextxy(255, 230, "NEW GAME");
			outtextxy(290, 260, "SCORE");
			outtextxy(305, 290, "HELP");
			outtextxy(290, 320, "ABOUT");
			settextstyle(1, 0, 2);
			setcolor(14);
			outtextxy(310, 350, "EXIT");
		}
		else
		{
			settextstyle(1, 0, 2);
			setcolor(15);
			outtextxy(255, 230, "NEW GAME");
			outtextxy(290, 260, "SCORE");
			outtextxy(305, 290, "HELP");
			outtextxy(290, 320, "ABOUT");
			outtextxy(310, 350, "EXIT");
		}
	}
}

void clickmouse(int &thoat, int x, int y)
{
	if (ismouseclick(WM_LBUTTONDBLCLK) && (y > 230 && y < 380) && (x > 255 && x < 450))
	{
		int x1, y1;
		cleardevice();
		settextstyle(1, 0, 1); setcolor(12);
		getmouseclick((WM_LBUTTONDBLCLK), x1, y1); // lay toa do chuot click
		if ((y1 >= 230 && y1 <= 260) && (x1 >= 255 && x1 <= 450))
		{
			menu_PlayGame();
		}
		if ((y1 >= 260 && y1 <= 290) && (x1 >= 255 && x1 <= 450))
		{
			setcolor(15); outtext("Ban vua click");
			setcolor(12);
			outtext("SCORE");
		}
		if ((y1 >= 290 && y1 <= 320) && (x1 >= 255 && x1 <= 450))
		{
			setcolor(15); outtext("Ban vua click");
			setcolor(12);
			outtext("HELP");
		}
		if ((y1 >= 320 && y1 <= 350) && (x1 >= 255 && x1 <= 450))
		{
			setcolor(15); outtext("Ban vua click");
			setcolor(12);
			outtext("ABOUT");
		}
		if ((y1 >= 350 && y1 <= 380) && (x1 >= 255 && x1 <= 450))
		{
			thoat = 1;
		}
		if (thoat != 1)
		{
			int tamdung = 0;
			do {
				if (ismouseclick(WM_MOUSEMOVE))
				{
					getmouseclick(WM_MOUSEMOVE, x, y);
				}

				if ((y >= 450 && y <= 480) && (x >= 540 && x <= 570))
					setbkcolor(10);
				else
					setbkcolor(8);
				settextstyle(10, 0, 5);
				setcolor(12);
				outtextxy(540, 440, "EXIT");
				setbkcolor(0);
				if (ismouseclick(WM_LBUTTONDBLCLK))
				{
					getmouseclick(WM_LBUTTONDBLCLK, x, y);
					if ((y >= 450 && y <= 480) && (x >= 540 && x <= 570))
						tamdung = 1;
				}
			} while (tamdung == 0);
		}
		cleardevice();
		menu1(x, y);
	}
}
int main()
{
	int x, y, thoat;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\tc\\bgi");
	initwindow(700, 600);
	do
	{
		menu1(x, y);
		clickmouse(thoat, x, y);
		delay(10);
	} while (thoat != 1);

	closegraph();
	getch();
	return 0;
}
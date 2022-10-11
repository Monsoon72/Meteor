#include <stdio.h>
#include <easyx.h>
#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
#include <cstdlib>
#include <conio.h>
#pragma comment <lib,"winmm.lib">
#define Star_Num 500
#define Meteor_Num 130
using namespace std;
/*
@file Meteor
@author Yu Chang
@date 2022/07/05
*/


struct Star
{
	int x;
	int y;
	int r;
	int speed;
	COLORREF colour;
};
struct Meteor
{
	int x;
	int y;
	int speed;

};
struct Star star[Star_Num];
struct Meteor meteor[Meteor_Num];

IMAGE img[2];
IMAGE BK2;
void loadImg()
{
	//loadimage(img + 0, _T("A:/ C++/Project1/images/11.jpg.jpg"),50,50);
	//loadimage(img + 1, _T("A:/ C++/Project1/images/22.jpg.jpg"),50,50);
	loadimage(img + 0, _T("./images/11.jpg.jpg"), 50, 50);
	loadimage(img + 1, _T("./images/22.jpg.jpg"), 50, 50);
}

void initMeteor(int i)
{
	meteor[i].x = rand() % (2 * getwidth()) - 1200;
	meteor[i].y = rand() % 20 - 200;
	meteor[i].speed = rand() % 2 + 1;
}

void drawMeteor()
{
	for (size_t i = 0; i < Meteor_Num; i++)
	{
		putimage(meteor[i].x, meteor[i].y, img + (rand() % 2), SRCPAINT);
	}
}
void MoveMeteor()
{
	for (size_t i = 0; i < Meteor_Num; i++)
	{
		meteor[i].x += meteor[i].speed;
		meteor[i].y += meteor[i].speed;
		if (meteor[i].x >= getwidth() || meteor[i].y >= getheight())
		{
			initMeteor(i);
		}
	}
}

void star_init(int i)
{
	star[i].x = rand() % getwidth();
	star[i].y = rand() % getheight();
	star[i].r = rand() % 3 + 1;
	star[i].speed = (rand() % 2);
	star[i].colour = RGB(rand() % 256, rand() % 256, rand() % 256);
}

void draw()
{

	for (size_t i = 0; i < Star_Num; i++)
	{
		setfillcolor(star[i].colour);
		solidcircle(star[i].x, star[i].y, star[i].r);
		//putpixel(star[i].x, star[i].y, star[i].colour);
	}
}

void move()
{
	for (size_t i = 0; i < Star_Num; i++)
	{
		star[i].x += rand() % 3;
		if (star[i].x > getwidth())
		{
			star[i].x = 0;
		}
	}
}
void Confession()
{
	//mciSendString(_T("open ./images/COPYRIGHT.wav"), NULL, 0, NULL);
	//mciSendString(_T("play ./images/COPYRIGHT.wav"), NULL, 0, NULL);
	srand((unsigned)time(NULL));
	setbkmode(TRANSPARENT); //background color
	setbkmode(TRANSPARENT);
	while (!_kbhit()) // constantly change the color of the text and the emoji
	{
		cleardevice(); //without this function, the #heart will + 
		putimage(0, 0, &BK2);
		settextstyle(35, 0, _T(""));
		int Juzhong = (getwidth() - textwidth(_T("Letting go"))) / 2;
		outtextxy(Juzhong, 50, _T("雨季"));
		settextstyle(20, 0, _T(""));
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
		outtextxy(Juzhong - 450, 100, _T("这是一封离别信🍭"));
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
		outtextxy(Juzhong - 450, 140, _T("写下我该离开的原因 🚪"));
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
		outtextxy(Juzhong - 450, 180, _T("我在你生命中扮演的角色，太模糊了  :("));
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
		outtextxy(Juzhong - 450, 220, _T("窗外下雨了，这颗雨滴真美丽，跟往常的不太一样"));
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
		outtextxy(Juzhong - 450, 260, _T("雨...还在下，像在寻你，它敲着我的窗说找不到你"));
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
		outtextxy(Juzhong - 450, 300, _T("我想做诗，写雨，写夜里的相思，写梦中的你 💔"));
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
		outtextxy(Juzhong - 450, 340, _T("我像是无力的躺在干枯的河，在等待雨季来临"));
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
		outtextxy(Juzhong - 450, 380, _T("让我一直淋着雨，直到遇到那把我最爱的伞，和能配的上我的雨天"));
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
		outtextxy(Juzhong - 450, 420, _T("你说...雨肯定很伤心吧？所有人都在躲它 🌧"));
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
		outtextxy(Juzhong - 450, 460, _T("其实，雨真的不大，是风搞得紧张"));
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
		outtextxy(Juzhong - 450, 500, _T("下雨了，我说的不只是天气"));
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
		outtextxy(Juzhong - 450, 540, _T("好像所有的悲剧都发生在雨天，所以注定人们总会在阴雨天感到失落"));
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
		outtextxy(Juzhong - 450, 580, _T("雨后，总像有谁离去了"));
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
		outtextxy(Juzhong - 450, 620, _T("我无助　好想哭"));
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
		outtextxy(Juzhong - 450, 660, _T("大雨滂沱，思念无果"));
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
		outtextxy(Juzhong - 450, 700, _T("要在雨淋不到的环境，才能看到雨景"));
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
		outtextxy(Juzhong - 450, 740, _T("如果她总为别人撑伞，我何苦非为她等在雨中？"));
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
		outtextxy(Juzhong - 450, 780, _T("所有的这些记忆，如同雨中的泪水，都将随着时间消逝 🌧"));
		for (int i = 0; i < 20; i++)
		{
			setbkmode(TRANSPARENT);
			settextstyle(35, 0, _T(""));
			settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
			outtextxy(rand() % getwidth(), rand() % getheight(), _T("💔"));

		}
		for (int i = 0; i < 5; i++)
		{
			settextstyle(30, 0, _T(""));
			settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
			outtextxy(rand() % getwidth(), rand() % getheight(), _T("🌧️"));
		}
		Sleep(1000); //preventing the changing speed of the colors of the text too fast
	}
}
void play_sound()
{
	//PlaySound(_T("./images/music.wav"), NULL, SND_ASYNC);
}
int main()
{
	initgraph(1200, 800);
	IMAGE BK;
	loadimage(&BK, _T("./images/pic2.png"), getwidth(), getheight());
	loadimage(&BK2, _T("./images/pic3.jpg"), getwidth(), getheight());
	loadImg();
	play_sound();
	Confession();
	for (size_t i = 0; i < Meteor_Num; i++)
	{
		initMeteor(i);
	}
	for (size_t i = 0; i < Star_Num; i++)
	{
		star_init(i);
	}
	BeginBatchDraw();
	while (true)
	{
		cleardevice();
		putimage(0, 0, &BK);
		draw();
		move();
		drawMeteor();
		MoveMeteor();
		FlushBatchDraw();
	}
	EndBatchDraw();

}

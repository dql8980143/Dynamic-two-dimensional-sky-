#include <iostream>
#include <graphics.h>
#include <time.h>
#include <conio.h>

const int MAX=200;

struct Star
	{
		int X;
		int Y;
		int Step;//速度
		double Color;
	}star[MAX];

int main()
{
	initgraph(640,480);//初始化画布大小

	srand((unsigned int)time(NULL));//设置随机数种子

	//初始化200个星星的状态
	void InitStar(int i);
	int i;
	for(i=0;i<MAX;i++)
		InitStar(i);

	void MoveStar(int count);

	while(!_kbhit())
	{
		MoveStar(MAX);
		Sleep(20);
	}
}

void InitStar(int i)
{
	star[i].X=rand()%640;
	star[i].Y=rand()%480;
	star[i].Step=rand()%5+1;//1-5//设置星星的速度范围:1-5
	star[i].Color=star[i].Step*50;//设置星星的亮度50-250
}

void MoveStar(int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		putpixel(star[i].X,star[i].Y,RGB(0,0,0));//第二次调用MoveStar函数时，将上次调用时所画的星星轨迹覆盖
		star[i].X+=star[i].Step;
		if(star[i].X>640)
			InitStar(i);
		putpixel(star[i].X,star[i].Y,RGB(star[i].Color,star[i].Color,star[i].Color));
		
	}
}

	
#include <iostream>
#include <graphics.h>
#include <time.h>
#include <conio.h>

const int MAX=200;

struct Star
	{
		int X;
		int Y;
		int Step;//�ٶ�
		double Color;
	}star[MAX];

int main()
{
	initgraph(640,480);//��ʼ��������С

	srand((unsigned int)time(NULL));//�������������

	//��ʼ��200�����ǵ�״̬
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
	star[i].Step=rand()%5+1;//1-5//�������ǵ��ٶȷ�Χ:1-5
	star[i].Color=star[i].Step*50;//�������ǵ�����50-250
}

void MoveStar(int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		putpixel(star[i].X,star[i].Y,RGB(0,0,0));//�ڶ��ε���MoveStar����ʱ�����ϴε���ʱ���������ǹ켣����
		star[i].X+=star[i].Step;
		if(star[i].X>640)
			InitStar(i);
		putpixel(star[i].X,star[i].Y,RGB(star[i].Color,star[i].Color,star[i].Color));
		
	}
}

	
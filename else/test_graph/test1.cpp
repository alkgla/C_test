#include "conio.h"
#include <iostream>
#include <graphics.h>
#include <stdio.h>
using namespace std;
int main(){

	int gdriver,gmode;
	gdriver=DETECT;
	initgraph(&gdriver,&gmode,"c:");
	setbkcolor(BLUE);
	setcolor(WHITE);
//	circle(170,200,50);
//	circle(400,200,50);
//	int TriXy[]={200,200,300,300,150,260,200,200};
//	drawpoly(3,TriXy);
	setfillstyle(XHATCH_FILL,RED);
//	bar3d(100,100,200,200,50,5);
	pieslice(200, 200, 0, 20, 100);
	sector(400,400,0,30,100,50);
	getch();
	closegraph();
	return 0;

}

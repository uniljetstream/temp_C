﻿#define _CRT_SECURE_NO_WARNINGS

#include "line.h"
#include "point.h"
#include <stdio.h>

int main(void)
{
	Line a = { {1, 2}, {5, 6} };
	
	//선의 가운데 좌표
	Point b;
	b.x = (a.first.x + a.second.x) / 2;
	b.y = (a.first.y + a.second.y) / 2;
	printf("선의 가운데 좌표 : %d, %d", b.x, b.y);
	return 0;
}


//goto, volite 키워드 안함(뭐 안해도 될 듯 알고는 있자)
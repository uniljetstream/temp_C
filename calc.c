#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern int c;	//다른 c파일에 있는 전역변수를 참조할 때 쓴다.

void input_data(int* pa, int* pb)	//정의에서는 변수명 필수
{
	printf("정수 두 개를 입력하세요 : ");
	scanf("%d %d", pa, pb);

	printf("현재 c의 값은 : %d\n", c);
}

double average(int a, int b)
{
	return (a + b) / 2.0;
}


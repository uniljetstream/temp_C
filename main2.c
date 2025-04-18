#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 두 정수의 평균을 구하는 프로그램!!
void input_data(int *, int *);
double average(int, int);

//main2.c에서 전역변수 c를 만들었다.
int c = 100;
//stactic int c =100; //정적으로 선언하면 이 c 파일 혹은 중괄호 안에서만 사용 가능핟.

int main(void)
{
	int a, b;
	input_data(&a, &b);

	double avg = average(a, b);
	printf("%d와 %d의 평균 : %.1f", a, b, avg);

	return 0;
}
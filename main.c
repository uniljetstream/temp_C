#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "student.h"
//header의 경로는 절대 경로, 상대 경로 둘 다 가능.

//매크로
#define A 3	//int : 기본 정수 자료형
#define PI 3.141592	//double : 기본 실수 자료형
#define UNIT "cm^2"
#define SUCCESS_PRINT printf("면적 구하기 성공\n")

#define SUM(a, b) ((a)+(b))
#define	MUL(a, b) ((a)*(b))

#define NAME_CAT(x,y) (x##y)

#define VER 7 //현재 비주얼 스튜디오 버전
#define BIT16 //정수 표현 범위

//전처리기와 매크로에는 세미콜론이 없어야함.
int main(void)
{
#if VER >= 6	//컴파일전에 정해지는 조건부 컴파일 지시자
	printf("버전 %d 입니다.\n", VER);	//단 이거는 main()이 동작하고 나서 동작함.
#endif

	int max;

#ifdef BIT16	//BIT16이 정의 되어있으면 ifdef문 활성화 아니면 else 활성화
	max = 32767;
#else
	max = 2147243647
#endif 

	printf("정수형의 최대 범위 %d\n", max);

	//이미 만들어져있는 매크로
	printf("컴파일 날짜 : %s\n", __DATE__);
	printf("컴파일 시각 : %s\n", __TIME__);
	printf("파일명 : %s\n", __FILE__);
	printf("함수명 : %s\n", __FUNCTION__);
	printf("행번호 : %d\n", __LINE__);

#line 2025 "macro.c"	//파일명과 행번호 설정
	printf("파일명 : %s\n", __FILE__);
	printf("행번호 : %d\n", __LINE__);	//전처리문은 제외하고 센다.

	for (int i = 1;i <= 3;i++)
	{
		int	NAME_CAT(score, i);
		NAME_CAT(score, i) = i * 10;
		printf("%d\n", NAME_CAT(score, i));
	}

	int result = SUM(2, 5);
	printf("%d\n", result);

	int result2 = MUL(2, 5);
	printf("%d\n", result2);

	int r;

	printf("반지름을 입력하세요 : ");
	scanf("%d", &r);
	//원의넓이 : 원주율 x 반지름 x 반지름
	double area = PI * r * r;
	printf("원의 넓이 %.2lf %s\n", area, UNIT);
	SUCCESS_PRINT;

	Student s1;	//student.h 안에 있다.
	s1.num = 315;
	s1.grade = 3.7;

	return 0;
}
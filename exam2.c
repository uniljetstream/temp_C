#define _CRT_SECURE_NO_WARNINGS
/***********************************************************/
// [4-14] 비트연산
/***********************************************************/

#if 0 
#include <stdio.h>

int main(void)
{
	int a = 10, b = 12;
	printf("a & b = %d\n", a & b); //1010, 1100 => 1000
	// a | b
	// a : 00000000 00000000 00000000 00001010
	// b : 00000000 00000000 00000000 00001100
	printf("a | b = %d\n", a | b); //1110

	//a^b
	// a : 00000000 00000000 00000000 00001010
	// b : 00000000 00000000 00000000 00001100
	printf("a^b = %d\n", a ^ b);	//0110

	//~a : 부정 연산 1을 0을 1로
	// a : 00000000 00000000 00000000 00001010
	printf("~a : %d\n", ~a); //11110101  = -11(음의 보수 만들기);

	//a<<1 모든 비트의 위치를 한칸 왼쪽으로
	// a : 00000000 00000000 00000000 00001010 : 10
	// r : 00000000 00000000 00000000 00010100 : 20
	printf("a<<1 = %d\n", a << 1);	//비트를 n비트 왼쪽 쉬프트 시키면 2^n됨.

	//b>>1
	// b : 00000000 00000000 00000000 00001100 : 12
	// r : 00000000 00000000 00000000 00000110 : 6
	printf("b>>1 = %d\n", b >> 1);

	//~a >> 1 (-11 >> 1)
	// a : 00000000 00000000 00000000 00001010
	// ~a  : 11111111 11111111 11111111 11111010 ??
	printf("~a = %d\n", ~a >> 1); //-6
	return 0;
}
#endif

/***********************************************************/
// [4-14] 연산자 우선순위
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	printf("10/5*2=%d\n", 10 / 5 * 2); //4
	printf("10 > 5 && 10 != 5 : %d\n", 10 > 5 && 10 != 5); //1
	printf("10 %% 3 == %d\n", 10 % 3); //1
	return 0;
}
#endif

/***********************************************************/
// [5-1] 성인 판독기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int age;
	printf("나이를 입력해주세요 : ");
	scanf("%d", &age);
	if (age > 19) {
		printf("성인입니다.\n");
	}
	printf("프로그램이 종료되었습니다.");
	return 0;
}
#endif

/***********************************************************/
// [5-2] 공배수 출력하기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int num;
	printf("정수 입력 : ");
	scanf("%d", &num);
	if (num % 3 == 0 && num % 5 == 0) printf("3과 5의 배수입니다.");
	return 0;
}
#endif

/***********************************************************/
// [5-3] 성인 및 미성년자 여부 판단하기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int age;

	prinft("나이를 입력하세요");
	scanf("%d", &age);

	if (age >= 20)
	{
		printf("성인입니다.");
	}
	else
	{
		printf("미성년자입니다.");
	}
	return 0;
}
#endif

/***********************************************************/
// [5-4] 홀수 짝수 판별기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int num;
	printf("정수 입력 : ");
	scanf("%d", &num);
	if (num % 2 == 0) printf("짝수입니다.");
	else if (num % 2 != 0) printf("홀수입니다.");
	return 0;
}
#endif

/***********************************************************/
// [5-5] 마트 계산기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	double price = 10000;
	int count;

	printf("개수 입력 : ");
	scanf("%d", &count);

	if (count >= 11)
	{
		printf("%.0lf원 입니다.", price * count * 0.9);
		// 1 - 0.1
	}
	else printf("%d원입니다.", price * count);

	return 0;
}
#endif

/***********************************************************/
// [5-6] 학점 계산 프로젝트
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int score;
	char grade;
	printf("학점 입력 : ");
	scanf("%d", &score);

	if (score >= 90)
	{
		grade = 'A';
	}
	else if (score >= 80)
	{
		grade = 'B';
	}
	else if (score >= 70)
	{
		grade = 'C';
	}
	else
	{
		grade = 'F';
	}

	printf("%c학점", grade);

	return 0;
}
#endif

/***********************************************************/
// [5-07] 추석 선물 세트 확장
/***********************************************************/

#if 0 
#include <stdio.h>

int main(void)
{
	int count, member;
	double price = 10000;

	printf("개수 입력 : ");
	scanf("%d", &count);

	printf("회원 여부(회원 1 비회원 0) : ");
	scanf("%d", &member);

	if (count >= 11)
	{
		if (member == 1)
		{
			price = price * count * (1 - 0.1) * (1 - 0.1);
		}
		else price = price * count * (1 - 0.1);
	}
	else
	{
		if (member == 1)
		{
			price = price * count * (1 - 0.1);
		}
		else price = price * count * (1 - 0.1);
	}
	printf("%.0lf 원 입니다.", price);

	return 0;
}
#endif

/***********************************************************/
// [5-7.5] switch란
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int month = 4;
	switch (month)
	{
	case 4:
		printf("봄\n");
		break;
	case 6:
		printf("여름\n");
		break;
	default:
		break;
	}
	return 0;
}
#endif

/***********************************************************/
// [5-8] 상금 지급 프로그램
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int rank;

	printf("등수 입력 : ");
	scanf("%d", &rank);

	switch (rank)	//printf("%d\n", -100*rank+400) 이면 한 번에 가능. rank를 x좌표, 금액을 y좌표를 하면 나오는 1차함수 식.
	{
	case 1:
		printf("300만원");
		break;
	case 2:
		printf("200만원");
		break;
	case 3:
		printf("100만원");
		break;
	default:
		printf("상금 못 받지롱~");
		break;
	}
	return 0;
}
#endif

/***********************************************************/
// [5-확인] 자판기 프로그램
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int pay, menu, rest_1000 = 0, rest_500 = 0, rest_100 = 0;
	printf("금액을 입력하세요 : ");
	scanf("%d", &pay);

	printf("메뉴를 고르세요\n [1]아침햇살(700원) [2]솔의눈(1000원) [3]데자와(500원) :");
	scanf("%d", &menu);

	switch (menu)	//메뉴 가격 차감.
	{
	case 1:
		pay -= 700;
		break;
	case 2:
		pay -= 1000;
		break;
	case 3:
		pay -= 500;
		break;
	default:
		break;
	}

	if (pay < 0)
	{
		printf("돈이 부족해요 ㅠㅠ");
		return 0;
	}

	printf("%d\n", pay);
	if (pay % 1000 == 0) rest_1000 = pay / 1000;
	else if (pay % 1000 != 0)
	{
		rest_1000 = pay / 1000;
		if (pay % 1000 % 500 == 0) rest_500 = pay % 1000 / 500;
		else if (pay % 1000 % 500 != 0)
		{
			rest_500 = pay % 1000 / 500;
			rest_100 = pay % 1000 % 500 / 100;
		}
	}
	printf("천원 : %d, 오백원 : %d, 백원 : %d", rest_1000, rest_500, rest_100);
	return 0;
}
#endif

/***********************************************************/
// [5-도전실전예제] 계산기 프로그램
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int num1, num2;
	char oper;

	printf("사칙연산 입력(정수) : ");
	scanf("%d%c%d", &num1, &oper, &num2);

	if (oper == '+') printf("%d+%d=%d", num1, num2, num1 + num2);

	if (oper == '-') printf("%d-%d=%d", num1, num2, num1 - num2);

	if (oper == '*') printf("%d*%d=%d", num1, num2, num1 * num2);

	if (oper == '/') printf("%d/%d=%d", num1, num2, num1 / num2);

	return 0;
}
#endif

/***********************************************************/
// [6-1] 자릿수 계산 프로그램
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int num = 0, cnt = 0;

	printf("정수 입력 : ");
	scanf("%d", &num);

	//대게 반복 횟수가 정해져 있지 않을 때!! : while
	//반복회수가 정해져 있을 때!! : for
	while (num != 0)
	{
		num = num / 10;
		cnt++;
		//if (num == 0) break;
	}
	printf("%d 자리 정수입니다.", cnt);
	return 0;
}
#endif

/***********************************************************/
// [6-2] 10보다 작은 값 입력 프로그램
/***********************************************************/

#if 0 
#include <stdio.h>

int main(void)
{
	int num = 0;

	while (num < 10) {
		printf("정수입력 : ");
		scanf("%d", &num);
	}
	printf("종료되었습니다.");
	return 0;
}
#endif

/***********************************************************/
// [6-3] 누적합 출력 프로그램
/***********************************************************/

#if 0 
#include <stdio.h>

int main(void)
{
	int num, sum = 0;
	while (1) {
		printf("정수 입력 : ");
		scanf("%d", &num);
		if (num == -1) break;
		sum += num;
		printf("누적 결과 : %d\n", sum);
	}
	printf("종료되었습니다.");
	return 0;
}
#endif

/***********************************************************/
// [6-4] for 문 연습.
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	for (int i = 1;i < 11;i++)
	{	//지역변수 i의 성격
		printf("%d ", i);
	}
	printf("\n\n");
	for (int i = 21;i <= 57;i++)
	{
		printf("%d ", i);
	}
	printf("\n\n");
	for (int i = 96;i >= 53;i--)
	{
		printf("%d ", i);
	}
	printf("\n\n");
	//1에서 100까지 3의 배수만 출력
	for (int i = 1;i <= 100;i++)
	{
		if (i % 3 == 0)
		{
			printf("%d ", i);
		}
	}
	printf("\n\n");
	for (int i = 1;i <= 100;i++) 
	{	//3과 5의 배수만 출력
		if (i % 3 == 0 && i % 5 == 0)
		{
			//printf("%d ", i);
			continue;
		}
		printf("%d ", i);
	}
	printf("\n\n");
	for (int i = 1;i <= 100;i++)
	{	//3의 배수 제외 출력
		if (i % 3 == 0)
		{
			continue;	//더 이상 진행 시키지 않고 다음 증가식으로 이동.(break는 for문 자체를 중단시킴.)
		}
		printf("%d ", i);
	}
	printf("\n\n");
	return 0;
}
#endif

/***********************************************************/
// [6-5] 배수 출력하기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int num = 0;

	printf("자연수를 입력하세요 : ");
	scanf("%d", &num);	
	for (int i = 1;i < 11;i++) 
	{
		printf("%d ", num * i);
	}
	return 0;
}
#endif

/***********************************************************/
// [6-6] 구구단 출력하기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	for (int i = 1;i < 10;i++) {
		printf("2 x %d = %d\n", i, 2 * i);
	}
	return 0;
}
#endif

/***********************************************************/
// [6-7] 입력받은 정수의 약수를 구하기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int num;
	printf("정수를 입력하세요 : ");
	scanf("%d", &num);
	printf("%d의 약수 : ", num);
	for (int i = 1;i < num + 1;i++)
	{
		if (num % i == 0) {
			printf("%d ", i);
		}
	}
	/*
	약수의 성질 : 자기자신 끝까지 구할 필요 없이 절반까지만 구하고 자기자신만 추가해도 같은결과.
	*/
	return 0;
}
#endif

/***********************************************************/
// [6-권장] 권장규칙
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	//초기식, 조건식, 증감식은 반복회수를 알기 쉅게 작성한다.
	for (int i = 7;i <= 16;i++)
	{
		printf("%d ", i - 6);
	}
	//반복 횟수를 세는 변수를 반복문 안에서 바꾸지 않는 것이 좋다.
	return 0;
}
#endif

/***********************************************************/
// [6-유지보수] 누적합 do~while
/***********************************************************/

#if 0 
#include <stdio.h>

int main(void)
{
	int sum = 0;	//누적합을 저장하는 변수
	int num;
	do
	{
		printf("정수 입력 : ");
		scanf("%d", &num);
		sum += num;
		printf("누적 합계 : %d\n", sum);
	} while (num != -1);
	return 0;
}
#endif

/***********************************************************/
// [6-많이 써요] 무한 반복문.
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	//1을 무한히 출력
	int sum= 0, num = 0;
	while (1)
	{
		printf("정수 입력 : ");
		scanf("%d", &num);
		if (num == -1) break;
		sum += num;
		printf("누적 합계 : %d \n", sum);
	}
	return 0;
}
#endif

/***********************************************************/
// [6-8] 다이어트 관리 프로그램. 
/***********************************************************/

#if 0; 
#include <stdio.h>

int main(void)
{
	int crt_weight = 0, goal_weight = 0;
	printf("현재 몸무게를 입력하세요 : ");
	scanf("%d", &crt_weight);

	printf("목표 몸무게를 입력하세요 : ");
	scanf("%d", &goal_weight);
	
	int week = 1, weight=0;
	while (1)
	{
		printf("%d 주차 감량 몸무게 : ", week);
		scanf("%d", &weight);
		crt_weight -= weight;
		if (crt_weight <= goal_weight) {
			printf("%d kg 달성!! 축하합니다.\n", crt_weight);
			break;
		}
		week++;
	}
	return 0;
}
#endif

/***********************************************************/
// [6-9] 로그인 프로그램
/***********************************************************/
//250410, 0405i
#if 0
#include <stdio.h>
#include <string.h> //strcmp()

int main(void)
{
	//char fruit1[20] = "banana";
	//char fruit2[20] = "banana";
	//printf("%d", strcmp(fruit1, fruit2));	//strcmp() : 0이면 두 인수가 같다. 기본자료형이 아니면 c언어에서는 비교 불가능.

	char id[20] = "test";
	char pw[20] = "test027";

	char inputId[20], inputPw[20];
	
	while (1) 
	{
		printf("ID :");
		scanf("%s", inputId);
		printf("PW :");
		scanf("%s", inputPw);

		if (!(strcmp(id, inputId)) && !(strcmp(pw, inputPw)))
		{
			printf("로그인 성공\n");
			break;
		}
		else {
			printf("로그인 실패\n");
		}
	}
	return 0;
}
#endif

/***********************************************************/
// [6-11] 별 찍기 기초
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int i, j;
	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 5;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
#endif

/***********************************************************/
// [6-13] 별찍기 응용
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int i, j;
	for (i = 1;i <= 5;i++) 
	{
		for (j = 0;j < i;j++) 
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
#endif

/***********************************************************/
// [6-14] 별찍기 응용2
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int i, j, k;
	for (i = 0;i < 5;i++) 
	{
		for (j = 4; j > i;j--)
		{
			printf(" ");
		}
		for (k = 0;k < i+1;k++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
#endif

/***********************************************************/
// [6-15] 별찍기 응용3
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int i, j, k;
	for (i = 0;i < 5;i++)
	{
		for (j = 5;j > i;j--)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
#endif

/***********************************************************/
// [6-16] 별찍기 응용4
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int i, j, k;
	for (i = 1;i < 6;i++)
	{
		for (j = 0;j < i;j++) 
		{
			printf(" ");
		}
		for (k = 0;k < 6-i;k++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
#endif

/***********************************************************/
// [6-17] 별찍기 응용
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	for (int i = 1;i < 6;i++)
	{
		for (int k = 5;k > i;k--)
		{
			printf(" ");
		}
		for (int j = 0;j < i;j++)
		{
			printf("**");
		}
		printf("\n");
	}
	return 0;
}
#endif





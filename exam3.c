#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
/***********************************************************/
// [2-9] 2단부터 9단까지 구구단출력
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	for (int j = 2;j <= 9;j++)
	{
		for (int i = 1;i <= 9;i++)
		{
			printf("%d x %d = %d\n", j, i, i * j);
		}
		printf("\n");
	}
	return 0;
}
#endif

/***********************************************************/
// [7-1] 두 정수의 합을 반환하는 함수
/***********************************************************/

#if 0 
#include <stdio.h>

int sum(int num1, int num2);	//함수 선언. 미리 함수를 알려주어 메모리를 할당함. 즉 함수명은 생략을 하거나 다른 이름을 사용해도 가능하지만. 보통은 쓰지

int main(void)
{
	//함수를 정의 : 함수명, 매개변수, 반환형
	//함수를 호출 : 함수명(전달인자(argument)1, 전달인자2); 
	//함수를 선언 : 절차지향 프로그래밍에서 메모리 공간을 미리 할당
	//				정의 그대로 작성!! 단 몸통 없이.

	printf("%d\n", sum(3, 5));
	printf("%d\n", sum(10, 20));

	return 0;
}
//함수 정의 : 두 정수를 더해서 반환하는!!
//-함수명 :sum
//-매개변수 : num1, num2  
//-반환형 : int
//반환형 함수형(매개변수1...)
int sum(int num1, int num2)
{
	int result = num1 + num2;
	return result;
}
#endif

/***********************************************************/
// [7-확인] 실수 두 개의 평균을 반환하는 average 함수
/***********************************************************/

#if 0
#include <stdio.h>

double average(double num1,double num2);

int main(void)
{

	printf("%.2lf\n", average(1.5, 3.4));
	return 0;
}

double average(double num1, double num2) 
{
	return (num1 + num2) / 2;
}
#endif

/***********************************************************/
// [7-2] 매개변수가 없는 함수.
/***********************************************************/

#if 0
#include <stdio.h>

int get_num();

int main(void)
{
	int input1 = get_num();
	int input2 = get_num();

	printf("%d", input1 + input2);

	return 0;
}

//양수를 입력 받아 반환하는 함수.
int get_num()
{
	int result;

	printf("양수 입력 : ");
	scanf("%d", &result);

	return result;
}
#endif

/***********************************************************/
// [7-3] 반환값이 없는 함수.
/***********************************************************/

#if 0
#include <stdio.h>

void print_char(char ch, int count);

int main(void)
{
	print_char('*', 3);
	print_char('*', 4);
	for (int i = 0;i <= 5;i++)
	{
		print_char('@', i);
	}
	return 0;
}

//문자와 갯수를 전달하면 가로로 출력하는 함수!!
//예) *과 3 전달시 ** 출력
//void : 타입 없음을 표현
void print_char(char ch, int count)
{
	for (int i = 0;i < count;i++)
	{
		printf("%c", ch);
	}
	printf("\n");
	return;	//생략 가능
}
#endif

/***********************************************************/
// [7-4] 매개변수와 반환값이 모두 없는 함수
/***********************************************************/

#if 0 
#include <stdio.h>

void print_line(void);	//인수에 void를 쓰면 인수가 없다는 것을 명시적으로 선언.

int main(void)
{
	printf("이름 학번 전공 mbti\n");
	print_line();
	return 0;
}

//--------------------- 30개
void print_line(void)
{
	int i=0;
	while (i < 30)
	{
		printf("-");
		i++;
	}
}
#endif

/***********************************************************/
// [7-5] 재귀 함수
/***********************************************************/

#if 0
#include <stdio.h>

int fibonacci(int num);

int main(void)
{
	//재귀함수를 통해 피보나치 수열 20번째 항 구하기.
	//재귀함수는 함수 호출횟수가 커지면 커질수록
	//연산속도, 연산량이 기하 급수적으로 늘어난다.
	//f(3) = f(1) + f(2) //2번
	//f(4) = f(2) + f(3) //3번
	//f(5) = f(3) + f(4) //5번 ...
	printf("%d", fibonacci(20));
	return 0;
}
//피보나치 수열의 일반항 구하는 함수
int fibonacci(int num)
{
	if (num == 1 || num == 2) return 1;
	else if (num >= 3)
	{
		return fibonacci(num - 1) + fibonacci(num - 2);
	}
}
#endif

/***********************************************************/
// [7-6] 정수의 절댓값을 반환하는 abs함수
/***********************************************************/

#if 0
#include <stdio.h>

int abs(int num);
int main(void)
{
	printf("%d\n", abs(-20));
	return 0;
}

int abs(int num)
{
	if (num < 0) return num * -1;
	else return num;
	//return num<0 ? num*-1 : num;
}
#endif

/***********************************************************/
// [7-7, 8, 9, 10] 완전 수 구하기 
/***********************************************************/

#if 0
#include <stdio.h>

int is_divisor(int num1, int num2);
void print_divisors(int num);
int get_sum_of_divisors(int num);
int is_perfect_number(int num);
	
int main(void)
{
	printf("%d\n", is_divisor(10, 2));
	printf("%d\n", is_divisor(10, 3));
	printf("\n");

	print_divisors(10);
	print_divisors(12);
	printf("\n");

	printf("%d\n", get_sum_of_divisors(10));
	printf("%d\n", get_sum_of_divisors(28));
	printf("\n");

	printf("%d\n", is_perfect_number(10));
	printf("%d\n", is_perfect_number(28));
	printf("\n");

	//첫번째 완전수 6
	//두번째 완전수 28
	//세번째 완전수 ?? : 2~1000 사이에 있다.
	for (int i = 2;i < 1000;i++)
	{
		if (i != 6 && i != 28 && is_perfect_number(i) == 1) printf("%d\n", i);
	}
	printf("\n");
	//네번째 완전수 ?? : 1000~10000 사이에
	for (int i = 1000;i < 10001;i++)
	{
		if (is_perfect_number(i) == 1) printf("%d\n", i);
	}
	//다섯번째 완전수는 : 10000~10억 사이에(너무 커서 이 알고리즘으로 못찾아)


	return 0;
}

//step1. num2가 num1의 약수라면 1을 아니면 0을 반환.
int is_divisor(int num1, int num2)
{
	return num1 % num2 == 0 ? 1 : 0;	//num1%num2==0 이것도 됨. 아니면 return 1이 자동으로 되니깐.
}

//step2. print_divisors() : 약수를 출력하는 함수.
void print_divisors(int num)
{
	printf("%d의 약수 : ", num);
	for (int i = 1;i < num + 1;i++)
	{
		if (num % i == 0)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}

//step3. get_sum_of_divisors(int num) : num의 약수의 합을 반환하는 함수.
int get_sum_of_divisors(int num)
{
	int sum = 0;

	for (int i = 1;i < num + 1;i++)
	{
		if (num % i == 0)	//if (is_divisor(num, i))로 바꿀 수 있다.
		{
			sum += i;
		}
	}
	return sum;
}

//step4. is_perfect_number(int num) : 완전수면 1, 아니면 0 반환
int is_perfect_number(int num)
{
	return get_sum_of_divisors(num) - num == num ? 1 : 0;
	/*
	if (get_sum_of_divisors(num) == num*2)
	{
		return 1;
	} else return 0;
	*/
}


#endif

/***********************************************************/
// [6-9] up-down 프로그램
/***********************************************************/

#if 0
#include <stdio.h>
#include <stdlib.h>	//rand(), srand()
#include <time.h>	//time()

int main(void)
{
	srand(time(NULL));	//sead rander. 밀리초단위의 현재 시간을 시드로 줌.
	//1~100 사이의 랜던한 정수 추출
	int random_number = rand() % 100 + 1;
	//printf("%d\n", rand() % 100+1);	//0~99
	//printf("%d\n", rand() % 100 + 1);
	while (1)
	{
		int num;
		printf("정수 입력 : ");
		scanf("%d", &num);
		if (random_number > num)
		{
			printf("입력한 숫자보다 큽니다");
		}
		else if (random_number < num)
		{
			printf("입력한 숫자보다 작습니다.");
		}
		else
		{
			printf("정답!!");
			break;
		}
	}
	return 0;
}
#endif

/***********************************************************/
// [8-1] 배열의 선언과 사용
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int num;	//변수의 선언
	num = 10;	//변수의 할당(최초 할당 : 초기화)
	num = 20;	//변수의 재할당
	printf("%d\n", num);	//변수를 활용

	//배열요소가 초기화 되어 있지 않다면
	//배열이 초기화 되어 있지 않다면
	//사용 시 쓰레기 값 출력
	int array[5];	//배열의 선언
	array[0] = 10;	//배열 요소에 초기화
	array[1] = 20;
	array[2] = 50;
	array[3] = 70;
	array[4] = 100;
	for (int i = 0;i < 5;i++)
	{
		printf("array[%d] : %d\n", i, array[i]);
	}
	printf("%d %d\n", array[0], array[1]);
	//printf("%d %d\n", array[2], array[3], array[4]);
	//printf("%d\n", array[5]);
	return 0;
}
#endif

/***********************************************************/
// [8-2] 배열의 선언과 활용
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int arr[5] = { 8, 4, 99, 6, 7 };
	printf("array에 들어 있는 홀수는 ");
	//sizeof 연산자 활용
	//array[5] 몇 바이트 -> 20byte / 4 -> 5
	//sizeof(int) = 4, sizeof(double) = 8, sizeof(char) = 1

	for (int i = 0;i < sizeof(arr)/sizeof(int);i++)	//혹은 string.h의 strlen()
	{
		if (arr[i] % 2 != 0) printf("%d ", arr[i]);
	}

	return 0;
}
#endif

/***********************************************************/
// [8-3] sizeof 연산자를 사용한 배열
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int score[5];
	int sum = 0;
	for (int i = 0;i < 5;i++)
	{
		printf("%d과목 성적을 입력하세요 : ", i+1);
		scanf("%d", &score[i]);
	}
	for (int i = 0;i < 5;i++)
	{
		sum += score[i];
	}
	printf("총점: %d, 평균: %.lf\n", sum, (double)sum / 5);

	return 0;
}
#endif

/***********************************************************/
// [8-4] char형 배열의 선언과 초기화
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	char fruit[6] = {'a', 'p', 'p', 'l', 'e'};	//초기화 될때 문자열의 길이 + 1을 해야 컴파일러 끝에 널문자를 넣어줌(1 이상도 무관)
	char fruit2[6] = "apple";

	//for (int i = 0;i < 5;i++) 
	//{
	//	printf("%c", fruit[i]);
	//}
	//printf("\n");
	//for (int i = 0;i < 5;i++)
	//{
	//	printf("%c", fruit2[i]);
	//}
	//printf("\n");

	//return 0;
	printf("%s\n", fruit);
	printf("%s\n", fruit2);

	char my_name[10];
	my_name[0] = 'k';
	my_name[1] = 'h';
	my_name[2] = 'j';
	my_name[3] = '\0';

	printf("%s\n", my_name);

	return 0;
}
#endif

/***********************************************************/
// [8-5] 문자열을 대입하는 strcpy() 함수.
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h> //strcpy함수 사용을 위한 라이브러리

int main(void)
{
	char cat_name[100] = "이름을 지어주세요";
	char string[100];
	//char fruit[100] = "apple";
	//printf("현재 과일 : %s\n", fruit);
	////strcpy(이전 문자열, 새로운 문자열);
	//strcpy(fruit, "banana");
	//printf("새로운 과일 : %s\n", fruit);
	printf("%s : ", cat_name);
	scanf("%s", string);
	strcpy(cat_name, string);
	printf("%s", cat_name);
	return 0;
}
#endif

/***********************************************************/
// [8-6] 띄어쓰기까지 입력받자
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	char inputs[100];
	printf("내일의 점심 메뉴 입력 : ");
	gets(inputs);	//띄어쓰기 탭 무시.

	puts(inputs);	//gets에 대응 화면 출력.

	return 0;
}
#endif

/***********************************************************/
// [8-7] 대소문자 변환 프로그램
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>

int main(void)
{
	char string[100] = { '\0' };
	int num=0;

	printf("문자 입력 : ");
	gets(string);
	
	int i = 0;
	while (string[i]) {
		
		if (string[i] <= 'Z' && string[i] >= 'A') string[i] = string[i] + 32;
		i++;
	}

	printf("바뀐 문장 : ");
	puts(string);

	char temp[100] = "HELLO WORLD!!";
	strlwr(temp);	//소문자로 변환하는 함수. 사용하려면 #pragma 어쩌고 최상된에 선언함.
	printf(temp);

	return 0;

}
#endif

/***********************************************************/
// [8-정렬] 기본 졍렬
/***********************************************************/

#if 1
#include <stdio.h>

int main(void)
{
	int arr[6] = { 1, 13, 21, 7, 31, 28 };
	//정렬 : 탐색을 손쉽게 하기 위해
	//가장 큰 수는 ?
	//모든 값 탐색 : 시퀸셜 서치
	//오름차순
	//내림차순
	
	//1. 버블 정렬.
	//자리를 어떻게 바꿀 것인가? => 치환(swap)
	//int num1 = 10;
	//int num2 = 20;
	//num1에 20, num2에 10 저장.
	//int temp = num1;
	//num1 = num2;
	//num2 = temp;
	int temp;
	for (int j = 0;j < 5;j++) {
		for (int i = 0;i < j;i++)
		{
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}

	for (int i = 0;i < 5;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [0-0] 타이틀
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif


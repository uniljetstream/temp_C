﻿#define _CRT_SECURE_NO_WARNINGS
/***********************************************************/
// [9-1] 변수 메모리 주소 확인
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a; //4byte의 정수형 메모리
	double b;	//8byte의 실수형 메모리
	char c;		//1바이트 

	printf("a의 주소 %p \n", &a);
	printf("a의 주소 %p \n", &b);
	printf("a의 주소 %p \n", &c);

	return 0;
}
#endif


/***********************************************************/
// [9-2] 포인터 선언과 사용
/***********************************************************/

#if 0 
#include <stdio.h>

int main(void)
{
	int a; //변수의 선언
	int* pa; //포인터의 선언

	pa = &a; //a의 주솟값을 포인터 p에 담겠다.
	printf("pa에 들어있는 값 : %d\n", pa);
	
	a = 10;
	printf("a에 들어 있는 값 : %d\n", a);

	*pa = 20;	//간접 참조 연산자
	printf("pa에 들어 있는 값 : %d\n", a);
	return 0;
}
#endif

/***********************************************************/
// [9-3] 포인터를 사용한 두 정수의 합과 평균 계산 
/***********************************************************/

#if 0 
#include <stdio.h>

int main(void)
{
	int a = 10, b = 15, total;
	int* pa, * pb, * pt;
	double avg;
	double* pg;

	//1. pa, pb, pt, gg 를 초기화
	//2. 간접 참조 연산 *를 활용하여 total에 a+b를 대입
	//3. 간접 참조 연산자 *를 활용하여 avg에 a와 b의 평균을 대입
	pa = &a;
	pb = &b;
	pt = &total;
	pg = &avg;
	*pt = *pa + *pb;
	*pg = *pt / 2.0;
	printf("두 정수의 값 : %d %d\n", *pa, *pb);
	printf("두 정수의 총합 : %d\n", *pt);
	printf("두 정수의 평균 : %.1lf\n", *pg);
	return 0;
}
#endif
/***********************************************************/
// [9-4] 포인터에 const 사용 
/***********************************************************/

#if 0 
#include <stdio.h>

int main(void)
{
	//const 키워드를 사용한 변수는 선언과 동시에 초기화해야함.
	const int num = 10;
	int a = 10, b = 20;
	const int *pa= &a;
	printf("a의 값 : %d\n", *pa);

	pa = &b;	//pa가 b의 주소를 가르킨다.
	printf("b의 값 : %d \n", *pa);

	pa = &a;
	a = 7;
	printf("a의 값 : %d\n", *pa);

	*pa = 77; //이거는 불가능, const로 포인터 설정 간접 참조 불가.
	//변수 a를 수정하기 위해 *pa = 20 같은 것은 불가능.(pa가 가르키고 있는 변수 자체를 수정은 불가능)
	//*pa에 다른 변수의 주솟값을 담는 것은 가능. == pa가 담는 주솟값은 수정 가능하나, 그 주소값이 가르키는 변수 값 수정은 불가능.
	//하지만 주소값이 가르키는 변수로 변수의 값을 바꾸는 것은 가능
	//*pa = &b는 가능, *pa = 77은 불가, a =77은 가능
	printf("a의 값 : %d\n", *pa);
	return 0;
}
#endif

/***********************************************************/
// [9-5] 주소와 포인터의 크기 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	//sizeof 연산자 : sizeof(피연산자), 피연산의 데이터 크기 bythe로 반환
	int a;
	double b;
	char c;

	//포인터는 반드시 변수와 데이터 자료형이 일치해야한다.
	int* pa = &a;
	double* pb = &b;
	char* pc = &c;

	//주소의 크기
	printf("a주소 : %d, b주소 : %d, c주소 : %d\n", sizeof(&a), sizeof(&b), sizeof(&c));
	//포인터의 크기
	printf("a 포인터 : %d, b포인터 : %d, c포인터 : %d \n", sizeof(pa), sizeof(pb), sizeof(pc));
	//포인터가 가르키는 변수의 크기
	printf("a값 : %d, b값 : %d, c값 : %d\n", sizeof(*pa), sizeof(*pb), sizeof(*pc));
	
	return 0;
}
#endif

/***********************************************************/
// [9-6] 허용되지 않는 포인터의 대입 
/***********************************************************/

#if 0 
#include <stdio.h>

int main(void)
{
	int a = 10;
	int* pa = &a;
	double* pd;
	//pa는 a를 가르키는 int형 포인터
	//pd는 double형을 가리킬 수 있는 포인터!
	pd = pa;	//a의 주소를 가리킬 수 있게 pd에 대입.
	printf("%lf\n", *pd); //double은 int형 변수를 가르켜서는 안된다.
	//주의) 형 변환처럼 사용 시 주소 범위 확인필요
	//형변환을 가능하기는 하지만 잘 안씀.

	int* pb;
	pb = pa;
	printf("%d\n", *pa);
	printf("%d\n", *pb);	//같은 자료형 포인터 일때만 대입 가능
	
	return 0;
}
#endif

/***********************************************************/
// [9-7] 포인터를 사용한 두 변수의 값 교환 
/***********************************************************/

#if 0 
#include <stdio.h>

void swap(int* pa, int* pb);

int main(void)
{
	int a = 10, b = 20;
	//두 값을 swap 후 출력

	int temp;
	temp = a;
	a = b;
	b = temp;

	printf("%d %d\n", a, b); //20, 10

	a = 10, b = 20;
	swap(&a, &b);	//swap에서 바라 볼 수 있게 a와 b의 주소를 넘김.
	printf("%d %d\n", a, b);	//20, 10
	return 0;
}
void swap(int* pa, int* pb) { //메모리에 실제 주소값으로 변수를 바꿈
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}
#endif

/***********************************************************/
// [9-8, 9] 다른 함수의 변수 사용하기 
/***********************************************************/

#if 0 
#include <stdio.h>

void swap(int a, int b);

int main(void)
{
	int a = 10, b = 20;
	swap(a, b); //치환 안됨. 함수의 지역변수 a,b와는 다른 변수이다.
	printf("a : %d, b : %d\n", a, b);
	return 0;
}
void swap(int a, int b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
#endif

/***********************************************************/
// [9-도전] 미니 정렬 프로그램
/***********************************************************/

#if 0
#include <stdio.h>

void swap(int* pa, int* pb);
void descending(int* max, int* mid, int* min);
int main(void)
{
	int max, mid, min;
	scanf("%d %d %d", &max, &mid, &min);
	//값 3개 넘길 시 가장 큰 값을 max, 중간값을 mid, 가장 작은 값을 min으로 바꾸는 함수.
	descending(&max, &mid, &min);	//내림차순
	printf("%d %d %d\n", max, mid, min);
	return 0;
}
void swap(int* pa, int* pb) { //메모리에 실제 주소값으로 변수를 바꿈
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}
void descending(int* max, int* mid, int* min) {
	for (int i = 0;i < 3;i++) {
		if (*max < *mid) {
			swap(max, mid);	//이 함수의 매개변수는 이미 주솟값임. 따라서 &붙혀서 넘길 필요가 없음.
		}
		else if (*mid < *min) {
			swap(mid, min);
		}
		else if (*max < *min) {
			swap(max, min);
		}
	}
}
#endif

/***********************************************************/
// [10-1] 배열명에 정수 연산을 수행해 배열 요소 사용
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int ary[3];	//3칸짜리 int 형 배열 선언!(총 12byte)
	int i;
	printf("%d\n", ary);
	printf("%d\n", &ary[0]);	//배열의 0번 인덱스는 배열의 주소를 가르킴.
	printf("%d\n", ary+1);	//배열의 0번 인덱스는 배열의 주소를 가르킴.

	ary[0] = 10;
	*(ary + 1) = 20; //ary[1]에 넣음.
	//*(ary+3) = 10;	//범위에 벗어난 주소 사용 금지!!

	for (int i = 0;i < 3;i++) {
		printf("%d 번째 요소 : %d\n", i + 1, ary[i]);
	}
	return 0;
}
#endif

/***********************************************************/
// [10-2] 배열명처럼 사용되는 포인터
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int ary[3];
	int* pa = ary;	//ary자체가 첫번째 배열의 주소

	*pa = 10;
	//20을 배열 두번째 요소(인덱스1)에 할당
	//*(pa + 1) = 20;

	pa++;
	*pa = 20;
	
	for (int i = 0;i < 3;i++) {
		printf("%d번째 요소 : %d\n", (i + 1), ary[i]);
	}

	printf("배열 전체의 길이 : %d\n", (int)sizeof(ary));
	printf("포인터 하나의 길이 : %d\n", (int)sizeof(pa));
	return 0;
}
#endif

/***********************************************************/
// [10-3] 포인터를 이용한 배열의 값 출력
// /***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int ary[3] = { 10, 20, 30 };
	int* pa = ary;

	printf("배열의 값 : ");
	for (int i = 0;i < 3;i++) {
		printf("%d ", *(pa++));	//pa를 사용시킨후 증가 시킴., 전위 증감 연산자는 사용하지말자 오버플로우난다.
	}//++(*pa), (*pa)++는 안된다.

	//후위 증감 연산자 사용 시!!
	//주소 값을 확인하여 범위를 벗어난지 확인 필요
	pa = ary;	//for문에 인덱스를 넘어서기 때문에 재할당필요

	return 0;
}
#endif

/***********************************************************/
// [10-4] 포인터의 뺄셈과 관계 연산
/***********************************************************/

#if 0
#include <stdio.h>
//관계연산, 대소비교 가능!
int main(void)
{
	int ary[5] = { 10, 20, 30, 40, 50 };
	int* pa = ary;	//10
	int* pb = pa + 3;	//40
	//ary+1 도 가능 하지만 원본은 ary는 건들지 말고 포인터 변수를 하나 만들어서 처리하는 것이좋다.

	printf("pa : %u\n", pa);
	printf("pb : %u\n", pb);
	
	pa++;
	printf("pb-pa : %u\n", pb - pa);
	
	//두 포인터 중
	// 더 앞에 있는 (인덱스가 작은) 요소 출력!!
	if (pa < pb) {
		printf("%d", *pa);
	}
	else
	{
		printf("%d\n", *pb);
	}
	return 0;
}
#endif

/***********************************************************/
// [10-5] 배열을 처리하는 함수
/***********************************************************/

#if 0 
#include <stdio.h>

void print_ary(int* pa);

int main(void)
{
	int ary[5] = { 10, 20, 30, 40, 50 };
	print_ary(ary);


	return 0;
}

void print_ary(int* pa) {
	for (int i = 0;i < 5;i++) {
		printf("%d\t", pa[i]);
		//printf("%d\t", *(pa++));
}
#endif

/***********************************************************/
// [10-6] 크기가 다른 배열을 출력하는 함수 
/***********************************************************/

#if 0
#include <stdio.h>

void print_ary(int* pa, int size);

int main(void)
{
	int ary[7] = { 10, 20, 30, 40, 50, 60, 70 };
	print_ary(ary, 7);
	print_ary(ary, 5);
	return 0;
}
void print_ary(int* pa, int size)
{
	// 배열의 주소를 담고 있는 포인터 pa를 활용하여
	// 모든 배열의 요소를 
	// 예) 10 20 30 40 50로 출력!!
	for (int i = 0;i < size;i++) {
		printf("%d\t", pa[i]);
	}
	printf("\n");
}
#endif

/***********************************************************/
// [10-7] 배열에 값을 입력하는 함수
/***********************************************************/

#if 0
#include <stdio.h>

void input_ary(int* ary, int size);
int find_max(int* ary, int size);
void print_ary(int arr[], int size);

int main(void)
{
	//1. 배열에 값을 입력하는 input_ary()
	int ary[5];
	input_ary(ary, sizeof(ary)/sizeof(int));
	//총 다섯번의 입력
	//입력 받는 대로 배열에 들어감.
	
	//배열의 최댓값을 찾아 출력하는 함수
	//find_max(ary, 5);
	//배열의 최댓값 : 50
	printf("%d\n", find_max(ary, 5));
	print_ary(ary, 5);

	return 0;
}
void input_ary(int* ary, int size) {
	int* pr = ary;
	for (int i = 0;i < size;i++) {
		scanf("%d", pr++);	//&pa[i]
	}
}

int find_max(int* ary, int size) {
	int max = ary[0];    
	for (int i = 0;i < size;i++) {
		if (ary[i] > max) {
			max = ary[i];
		}
	}
	return max;
}

void print_ary(int arr[], int size) {
	for (int i = 0;i < size;i++) {
		printf("%d", arr[i]);
	}
	printf("\n");
}
#endif
/***********************************************************/
// [10-도전] 로또 번호 생성 프로그램
/***********************************************************/

#if 0
#include <stdio.h>
#include <stdlib.h>	//time()
#include <time.h>	//srand(), seed()

void inputNum(int *number, int size);
void printNum(int* pa, int size);

int main(void)
{
	//도전 문제 : 6개의 정수 입력(1~45)
	//해당 값이 이미 존재 -> 다시 입력
	int lotto[6];
	inputNum(&lotto, sizeof(lotto)/sizeof(int));
	printNum(&lotto, sizeof(lotto)/sizeof(int));
	//랜덤으로 6개 추출
	//구매

	return 0;
}
void inputNum(int *number, int size) {
	srand(time(NULL));	//현재 시각을 통해 시드랜덤
	for (int i = 0;i < 6;i++) {
		//pa[i] = 랜덤으로 1~45까지 추출
		number[i]=rand() % 45 + 1;
		//로또 번호 입력 로직 시작
		//printf("%d 번째 번호를 입력하세요 : ", i+1);
		//scanf("%d", &number[i]); 
		//로또 번호 입력  로직 끝
		for (int j = 0;j < i;j++) {
			if (number[i] == number[j]) {
				printf("중복입니다.\n");
				i--;	//이 한줄이 중복을 감지 할 수 있는 테크닉
				break;
			}
		}
	}
}
void printNum(int* pa, int size) {
	printf("당신이 선택한 번호 : ");
	for (int i = 0;i < size;i++) {
		printf("%d ", pa[i]);
	}
	printf("\n");
}

#endif

/***********************************************************/
// [10-1] 정렬 알고리즘
/***********************************************************/

#if 0 
#include <stdio.h>

void swap(int* pa, int* pb);
void bubbleSort(int* pa, int size);
void print_array(int* pa, int size);
void selection_sort(int* pa, int size);
void binary_search(int* pa, int size, int search);
int main(void)
{
	int arr[10] = { 1, 32, 19, 27, 23, 20, 15, 96, 25, 37 };
	int size = sizeof(arr) / sizeof(int);
	printf("배열 원본 : ");
	print_array(arr, size);
	// bubbleSort(arr, size);
	// print_array(arr, size);
	selection_sort(arr, size);
	print_array(arr, size);

	int search = 19;
	binary_search(arr, size, search);
	print_array(arr, size);
	return 0;
}

void print_array(int* pa, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", pa[i]);
	}
	printf("\n");
}
// 두 값을 치환하는 swap
void swap(int* pa, int* pb)
{
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}
void bubbleSort(int* pa, int size)
{
	int max = pa[0];
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (pa[i] < pa[j])
				swap(&pa[i], &pa[j]);
		}
	}
}
void selection_sort(int* pa, int size)
{
	// 선택정렬
	// 버블정렬의 단점을 보완
	// 사이클 당 최대 치환 1번
	int max;
	int max_index;
	for (int j = 0; j < size - 1; j++)
	{
		max = pa[0];
		max_index = 0;
		// cycle1
		for (int i = 0; i < size - j; i++)
		{
			if (pa[i] > max)
			{
				max = pa[i];
				max_index = i;
			}
		}
		swap(&pa[max_index], &pa[size - (j + 1)]);
	}
}
void binary_search(int* pa, int size, int search) // 왜 안됨???
{
	// 이진탐색
	int low_index = 0;                            // 0
	int high_index = size - 1;                    // 9
	int mid_index = (low_index + high_index) / 2; // 4
	
	//while문이 10000번 정도 반복된다. ->
	int count = 0;

	while (low_index <= high_index)	//1대신 넣음. low_index가 high_index보다 커지는 경우(search가 없는 경우) 방지. 
	{
		int mid_index = (low_index + high_index) / 2;
		// 23       >      19
		if (pa[mid_index] > search)
		{
			// low_index는 그대로
			high_index = mid_index - 1;
		}
		else if (pa[mid_index] < search)
		{
			// high_index는 그대로
			low_index = mid_index + 1;
		}
		else
		{
			printf("찾고자 하는 %d은 index %d에 있습니다", search, mid_index);
			return;
		}
	}
}
#endif
/***********************************************************/
// [11-1] 대문자를 소문자로 변경 
/***********************************************************/

#if 0
#include <stdio.h>

char lowercase(char alphabet);

int main(void)
{
	printf("%c\n", lowercase('H'));
	return 0;
}

char lowercase(char alphabet) {

	if (alphabet <= 'Z' && alphabet >= 'A') return alphabet - 'A' + 'a';
	else return alphabet;
}
#endif

/***********************************************************/
// [11-2] 공백이나 제어문자의 입력 
/***********************************************************/

#if 0 
#include <stdio.h>

int main(void)
{
	char ch, ch2;
	//scanf("%c", &ch);
	//printf("[%c]\n", ch);	//엔터 등도 문자로 취급
	//printf("[%d]\n", ch);

	scanf("%c%c", &ch, &ch2);
	printf("[%d] [%d]\n", ch, ch2);
	return 0;
}
#endif

/***********************************************************/
// [11-3] Hello world 출력 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	while (1) {
		char ch;
		//scanf -> 문자입력, 문자열, 정수, 실수
		//문자 : 1byte, 정수/실수 => 4, 8byte
		//버퍼를 사용하기 때문에 상대적으로 무거움.
		scanf("%c", &ch);
		if (ch == 10) break; //엔터 입력 전까지 입력받기, 아스키 코드 10 == enter
		printf("%c", ch);
	}
	return 0;
}
#endif

/***********************************************************/
// [11-3] getchar, putchar 
/***********************************************************/
//문자 한정으로 scanf보다 가볍게 사용할 수 있다.
#if 0
#include <stdio.h>

int main(void)
{
	int ch;	
	while (1) {
		ch = getchar();
		if (ch == 10) break;
		printf("입력한 문자 : ");
		putchar(ch);
	}
		return 0;
}
#endif

/***********************************************************/
// [11-3] scanf에 공백
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	for (int i = 0;i < 5;i++) {
		char ch;
		//scanf("%c", &ch);
		scanf(" %c", &ch);	//화이트 스페이스를 제외하고 입력받음. ex. h e l l o로 입력받아도 hello로 출력됨.
		//%앞에 공백 삽입 시 -> 화잍트 스페이스 무시!!
		// 입력 값 : H e l l o
		// 입력 값 : H엔터e엔터l엔터l엔터o엔터
		// 입력 값 : H탭e탭l탭l탭o탭
		//3개 모두 출력은 Hello
		printf("%c", ch);
	}

	return 0;
}
#endif

/***********************************************************/
// [11-4] 버퍼를 사용하는 문자 입력 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	// 3개의 문자를 입력받는
	//for (int i = 0;i < 3;i++) {
	//	char ch;
	//	scanf("%c", &ch);
	//	printf("%c", ch);
	//}
	
	while(1) {
		char ch;
		//엔터가 들어오기 전까지 입력!!
		//엔터 들어올 시 break;
		scanf("%c", &ch);	
		if (ch == '\n') break;
		printf("%c", ch);
	}

	return 0;
}
#endif

/***********************************************************/
// [11-5] 입력 문자의 아스키 코드 값을 출력하는 프로그램.
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{	
	int result;
	char ch;

	while (1)
	{
		result = scanf("%c", &ch);
		//if (result == -1) break;	//crtl + z가 -1의 값을 가짐
		if (result == EOF) break;
		printf("%d ", ch);
	}
	return 0;
}
#endif

/***********************************************************/
// [11-6] getchar 함수를 사용한 문자열 입력
/***********************************************************/

#if 0
#include <stdio.h>

//apple -> 문자열을 입력받는 함수!!
void my_getchar(char* str, int size);

int main(void)
{
	char str[7];
	my_getchar(str, 7);
	printf("입력한 문자열 : %s \n", str);
	
	return 0;
}

void my_getchar(char* str, int size)
{
	//int i = 0;	//이 코드는 사용자가 6글자보다 적게 입력해도 6글자를 모두 입력받아야하는 문제 존재
	//int ch;
	//while (i < size-1) {
	//	//scanf("%c", &str[i]);
	//	str[i] = getchar();
	//	i++;
	//}
	//str[i] = '\0';
	
	int i;
	for (i = 0;i < size - 1;i++) {
		str[i] = getchar();
		if (str[i] == '\n') {
			break;
			i++;
		}
	}
	str[i] = '\0';	//끝에 널문자 삽입.
}
#endif

/***********************************************************/
// [11-7] 버퍼 초기화
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int num;
	int grade;
	//scanf()과 getchar()는 buffer를 공유한다.
	printf("학번 입력 : ");
	scanf("%d", &num);

	//getchar();	//버퍼 초기화

	printf("학점 입력 : ");
	grade = getchar();	//학점 입력이 안됨. 앞에 학번에서 입력하고 남아있는 \n을 버퍼에서 가져와서 끝남.

	printf("학번 : %d, 학점 : %c\n", num, grade);	//학점을 %d로 하면 엔터에 해당하는 \n가 출력되는 것을 볼 수 있다.
	
	//입력 버퍼 사용시 주의사항
	//잘 모르겠으면 버퍼를 초기화 하자.
	//getchar()를 한번 호출하면 초기화된다.

	return 0;
}
#endif

/***********************************************************/
// [11-도전] 길이가 가장 긴 단어 찾기
/***********************************************************/

#if 0
#include <stdio.h>
//scanf의 %s의 사용 금지. string.h 쓰지 않기
int main(void)
{
	int cnt = 0;
	int ch;
	int result = 0;
	while (1) {
		ch = getchar();
		if (ch == EOF) break;
		else if (ch != '\n') {
			cnt ++;
		}
		else if (ch == '\n') {
			//getchar(); 줄바꿈문자가 버퍼에 있다고 생각해서 추가한 건데, 이미 위에서 줄바꿈문자를 읽은 상태이므로 필요없음.
			if (result < cnt) {
				result = cnt;
			}
			cnt = 0;
		}
			
	}

	printf("가장 긴 단어의 길이 : %d", result);
	return 0;
	/*교수님 코드
	   int ch, max, len;
		max = -1;
		while (1)
		{
		ch = getchar();
		if (ch == EOF) break;

      // 하나의 문자열을 입력!!
      len = 0;
      while (1)
      {
         if (ch == '\n') break;
         ch = getchar();
         len++;
      }
      // printf("해당 문자열의 길이 : %d\n", len);
      if (len > max) max = len;
   }
   printf("가장 긴 단어의 길이 : %d\n", max);
	*/
}
#endif

/***********************************************************/
// [12-1] 문자열은 문자열 배열 ??
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int array[5] = { 10, 20, 30, 40, 50 };
	int* pa = array;
	printf("%p\n", array);	//배열명은 주솟값이다.
	printf("%p\n", pa);

	char fruit[6] = { 'a', 'p', 'p', 'l', 'e' };	//문자열 가장 뒤에 널문자를 컴파일러가 삽입함.
	char fruit2[6] = "apple";	//문자열도 포인터이다.

	printf("%s\n", fruit);
	printf("%s\n", fruit2);

	char* pf = fruit;
	char* pf2 = fruit2;

	printf("%p\n", pf);		//다른 주소를 가지고 있다. = 다른 메모리 위치를 가진다.
	printf("%p\n", pf2);

	return 0;
}
#endif

/***********************************************************/
// [12-2] 포인터로 문자열을 사용하는 방법
/***********************************************************/
// 사용하는 이유 : 배열을 함수에서 접근하는 유일한 방법이 포인터인데 문자열은 배열임.
#if 0
#include <stdio.h>

int main(void)
{
	char drink[80] = "tejava";
	char* pd = drink;

	//포인터를 통해 문자열 접근 가능
	//printf("%c\n", pd[0]);
	
	//while (1) {
	//	if (*pd == '\0') break;
	//	printf("%c", *pd);
	//	pd++;
	//}

	while (*pd != '\0') {	//*pd 만 있어도 가능.(널이면 0이므로)
		printf("%c", *(pd++));
		//pd++
	}

	//while (*pd) printf("%c", *(pd++));

	return 0;
}
#endif

/***********************************************************/
// [12-잠깐] 같은 문자열 상수
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	char fruit[6] = { 'a', 'p', 'p', 'l', 'e', '\0' };
	char fruit2[6] = "apple";
	char fruit3[6] = "apple";

	printf("apple의 주소 : %p\n", "apple");	//이거 두개는 같다. 두 개의 문자열을 사용했지만 컴파일러가 최적화를 위해 하나의 메모리를 사용
	printf("apple의 주소 : %p\n", "apple");

	printf("%p\n", fruit);
	printf("%p\n", fruit2);
	printf("%p\n", fruit3);
	printf("\n");

	char* pf = fruit;
	char* pf2 = fruit2;
	char* pf3 = fruit3;

	printf("%p\n", pf);
	printf("%p\n", pf2);
	printf("%p\n", pf3);

	return 0;
}
#endif

/***********************************************************/
// [12-3] scanf 함수를 사용한 문자열 입력
/***********************************************************/

#if 0 
#include <stdio.h>

int main(void)
{
	char str[80];
	
	printf("문자열 입력 : ");
	scanf("%s", str);	//공백없는 문자열만 입력받음.
	printf("%s\n", str);

	return 0;
}
#endif

/***********************************************************/
// [12-4] gets 함수로 한 줄의 문자열 입력 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	char str[80];
	printf("문자열 입력 : ");
	gets(str);	//엔터를 제외한 탭, 공백 입력 가능
	//문자열의 갯수를 넘어서 입력받을 위험성이 있다.
	printf("%s\n", str);

	return 0;
}
#endif

/***********************************************************/
// [12-5] fgets함수의 문자열 입력 방법
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>	//strlen()

int main(void)
{
	char str[10];
	printf("문자열 입력 : ");
	fgets(str, sizeof(str), stdin);	//키보드로 입력하겠다라는 뜻, 널문자를 제외한 10 -1만큼 입력됨.
	printf("문자열 길이 : %d\n", strlen(str)-1);	//엔터 제외
	printf("문자열 길이2 : %d\n", sizeof(str));	//문자열 선언 당시 선언된 크기(실제 길이와는 무관)
	printf("입력한 문자열 : %s\n", str);
	//문자열을 제외한 자료구조 배열에서는
	//배열의 요소 갯수를 sizeof(배열명) / sizeof(자료형)
	//문자열은 널문자를 제외해야 한다.
	return 0;
}
#endif

/***********************************************************/
// [12-6] 개행 문자로 인해 get함수가 입력안되는 경우
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int age;
	char name[20];
	printf("나이 입력 : ");
	scanf("%d", &age);

	printf("이름 입력 : ");
	//get함수 사용 전 버퍼 초기화 필요
	//초기화 방법에는 3가지가 있다. 교재 358p
	//scanf("%*c");
	//getchar();
	fgetc(stdin);
	gets(name);

	printf("나이 : %d, 이름 : %s", age, name);

	return 0;
}
#endif

/***********************************************************/
// [12-7] 문자열을 출력하는 puts와 fputs 함수
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	char str[80] = "apple juice";	//배열에 문자열 초기화
	char *ps = "banana";	//*ps : 배열이라는 뜻.

	puts(str);	//자동 줄바꿈.
	puts(ps);

	fputs(str, stdout);	//stdout : 모니터를 통해 표준 출력
	fputs(ps, stdout);	//fgets는 줄 바꿈이 안됨.

	return 0;
}
#endif

/***********************************************************/
// [12-직접] gets함수 구현해보기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	char str[20];	//"apple" 값을 입력!!
	//getchar() 함수를 활용해 gets() 구현
	//getchar() -> 문자를 하나하나 입력!

	//gets() 시작
	//int i = 0;
	//while (i<20) {
	//	str[i] = getchar();
	//	if (str[i++] == '\n') break;
	//}
	//str[i] = '\0';
	////gets() 끝

	//printf("%s", str); //apple 출력

	//return 0;

	//포인터로 gets 구현
	char* ps = str;
	while (1) {
		*ps = getchar();
		if (*ps++ == '\n') break;
	}
	*ps = '\0';
	printf("%s", str);
	return 0;
}
#endif

/***********************************************************/
// [12-8] 문자열을 대입하는 strcpy함수
/***********************************************************/
//문자열은 기본 자료형이 아니기 때문에 함수 사용해서 비교 연산 진행
#if 0
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[80] = "strawberry";
	//str을 "banana"로 바꾸시오
	// str = "strawberry"; //금지
	strcpy(str, "banana");
	printf("%s\n", str);

	char* ps = str;
	ps = "straberry";
	printf("%s\n", ps);	//가르키는 메모리가 바뀐 것이므로 str의 변화와는 관계없음.
	printf("%s", str);
	

	return 0;
}
#endif

/***********************************************************/
// [11-9] n개의 문자열을 복사하는 strncpy 
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[80] = "strawberry";
	strncpy(str, "mango", 5);

	printf("%s\n", str);

	char* ps = "choch";
	strncpy(str, ps, 5);

	printf("%s\n", str);
	
	char str2[80] = "melon_top_100";
	strncpy(str, str2, 5);

	printf("%s\n", str);

	return 0;
}
#endif

/***********************************************************/
// [12-8-직접구현] strcpy
/***********************************************************/

#if 0
#include <stdio.h>

char* my_strcpy(char* pd, char* ps);	//strcpy함수를 따라가기 위해 char* 타입으로, void 타입도 무관.
int main(void)
{
	char str[80] = "strawberry";
	printf("바꾸기 전 까지 문자열 : %s\n", str);	//strawberry
	
	//my_strcpy(복사할곳, 복사할 내용);
	//배열을 다룰 때 크기를 넣는 이유
	// -> 다른 함수에서 원래 배열의 크기를 못보기 때문
	//문자열 배열 -> 다른 함수에서 문자열 크기 볼수 있을까요? 볼 수 있습니다.
	// 널 문자까지 개수를 세면 가능.
	my_strcpy(str, "mango");

	printf("바꾼 후 문자열 : %s\n", str); //magoberry
	return 0;
}

char* my_strcpy(char* pd, char* ps)
{
	char* po = pd;
	
	while (*ps) {
		*po = *ps;
		po++;
		ps++;
		//*po++ = *ps++;
	} 
	*po = '\0';
	return po;
}
#endif

/***********************************************************/
// [12-10] 문자열을 연결하는 strcat() 
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h> //strcat()

int main(void)
{
	char str[80] = "straw";
	//strcat(연결할 장소, 연결 내용); 	
	strcat(str, "berry");
	printf("%s\n", str);

	char* pi = " ice-cream";
	strcat(str, pi);
	printf("%s\n", str);

	char str2[80] = "cake dessert yogurt";
	strncat(str, str2, 4);
	printf("%s\n", str);

	return 0;
}
#endif

/***********************************************************/
// [12-10-직접구현]	나만의 my_strcat() 만들기
/***********************************************************/

#if 0
#include <stdio.h>

char* my_strcat(char* pd, char* ps);
int main(void)
{
	char str[80] = "straw";
	my_strcat(str, "berry");

	printf("%s\n", str);	//strawberry
	return 0;
}

char* my_strcat(char* pd, char* ps)
{
	char* po = pd;
	while (1)
	{
		if (*po != '\0') po++;
		else
		{
			while (1)
			{
				*po = *ps;
				po++;
				ps++;
				if (*ps == '\0') {
					*po = *ps;
					break;
				}
			}
			return po;
		}
	}
}
/*
char *po = pd;
while (*po) po++;
while (*ps) *po++ = *po++;
*po = '\0';	//안 넣어도 동작하는 이유 : 초기화된 문자열은 크기만큼 \0로 가득 차 있다.	
return po;
/*
char* my_strcat(char* pd, char* ps)
{
   // pd -> straw
   // ps -> berry
   char* po = pd;
   // po, ps를 가지고 진행
   // "straw" "berry"
   // 1. po를 가장 오른쪽 위치로 이동!!
   while (1)
   {
	  po++;
	  if (*po == '\0') break;
   }
   // 2. 해당 값들을 ps에 있는 값들로 채우자!!
   // po -> w다음을 가리키고 있는 상태 index 5를 가리키고 있다
   // ps -> berry에서 b를 가리키고 있는 상태
   while (1)
   {
	  *po = *ps; // b -> w다음에 대입!!
	  po++;
	  ps++;
	  if (*ps == '\0') break;
   }
   // 3. 끝나면 \0 넣자!!
   *po = '\0';
   return po;
}
*/

#endif

/***********************************************************/
// [12-11] 문자열 길이 strlen()
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	char str1[80], str2[80];
	printf("두 과일 입력(과일1 과일2) : ");
	scanf("%s %s", str1, str2);

	if (strlen(str1) > strlen(str2))
	{
		printf("첫 번째 과일이 더 깁니다.\n");
	}
	else
	{
		printf("두 번째 과일이 더 깁니다.\n");
	}

	printf("첫 번째 과일 : %s\n", str1);
	printf("두 번재 과일 : %s\n", str2);

	return 0;
}
#endif

/***********************************************************/
// [12-11-직접] 나만의 my_strlen() 만들기
/***********************************************************/

#if 0
#include <stdio.h>

int my_strlen(char* str);

int main(void)
{
	char str1[80], str2[80];
	printf("두 과일 입력(과일1 과일2) : ");
	scanf("%s %s", str1, str2);

	if (my_strlen(str1) > my_strlen(str2))
	{
		printf("첫 번째 과일이 더 깁니다.\n");
	}
	else
	{
		printf("두 번째 과일이 더 깁니다.\n");
	}

	printf("첫 번째 과일 : %s\n", str1);
	printf("두 번재 과일 : %s\n", str2);

	return 0;
}
int my_strlen(char* str)
{
	int count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return count;
}
#endif

/***********************************************************/
// [12-12] strcmp 함수를 사용한 문자열 비교
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>	//strcmp(), strncmp()

int main(void)
{
	//strcmp(문자열1, 문자열2)
	//각 문자열 앞에서부터 아스키 코드 값 비교
	//모두 같으면 0 반환, 두 번째 문자열 아스키 코드 값이 크면 -  1, 첫번째 문자열 아스키 코드값이 크면 1
	char str1[80] = "pear";
	char str2[80] = "peach";
	int result = strcmp(str1, str2);
	int result2 = strncmp(str1, str2, 3);

	switch (result2) 
	{
	case 1: printf("%s이 사전에 나중에 나옵니다.", str1); 
		break;
	case -1 :  printf("%s이 사전에 나중에 나옵니다.", str2); 
		break;
	case 0 :  printf("문자열이 동일합니다.");
		break;
	default: printf("잘못 입력하셨습니다.\n");
		break;
	}

	return 0;
}
#endif

/***********************************************************/
// [12-12] 나만의 my_strcmp()
/***********************************************************/

#if 0
#include <stdio.h>

int my_strcmp(char* str1, char* str2);

int main(void)
{
	//strcmp(문자열1, 문자열2)
	//각 문자열 앞에서부터 아스키 코드 값 비교
	//모두 같으면 0 반환, 두 번째 문자열 아스키 코드 값이 크면 -  1, 첫번째 문자열 아스키 코드값이 크면 1
	char str1[80] = "paaaa";
	char str2[80] = "pzzz";
	int result = my_strcmp(str1, str2);

	switch (result)
	{
	case 1: printf("%s이 사전에 나중에 나옵니다.", str1);
		break;
	case -1:  printf("%s이 사전에 나중에 나옵니다.", str2);
		break;
	case 0:  printf("문자열이 동일합니다.");
		break;
	default: printf("잘못 입력하셨습니다.\n");
		break;
	}

	return 0;

	return 0;
}

int my_strcmp(char* str1, char* str2) 
{
	while (1)	
	{
		//안됨. str1, str를 둘을 가르키는 포인터를 만들어서 비교하는 것이 안전하다.
		if (*str1 > *str2) return 1;
		else if (*str1 < *str2) return -1;
		else if (*str1 == *str2 && *str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	/*
	int my_strcmp(char* str1, char* str2)
{
   char *p1 = str1;
   char *p2 = str2;

   while ((*p1 == *p2) && ((*p1 != '\0')))
   {
      p1++;
      p2++;
   }
   if (*p1 > *p2) return 1;
   else if (*p1 < *p2) return -1;
   else return 0;
}
	*/
}
#endif

/***********************************************************/
// [12-추가] 문자 갯수 찾아보기
/***********************************************************/

#if 0
#include <stdio.h>

int find_char(char* string, char ch);
int main(void)
{
	printf("%d\n", find_char("Hello", 'H'));
	return 0;
}
int find_char(char* string, char ch)
{
	char* ps = string;
	int count = 0;
	while (1)
	{
		if (*ps == '\0') return count;
		if (*ps == ch) {
			count++;
		}
		ps++;
	}
}
#endif
/***********************************************************/
// [12-도전] 단어 정렬 프로그램
/***********************************************************/
//해야함.
#if 0
#include <stdio.h>

int main(void)
{
	char* word1 = { '\0' }, word2 = { '\0' }, word3 = { '\0' };
	scanf("%s %s %s", word1, word2, word3);

	return 0;
}
#endif

/***********************************************************/
// [13-1] 두 함수에서 같은 이름의 지역변수를 사용하는 경우 
/***********************************************************/

#if 0 
#include <stdio.h>

void assign(void);

int main(void)
{
	auto int a = 10;	//지역 변수 선언과 초기화, auto 초기화 생력가능, 생략 시 컴파일러가 자동으로 추가
	printf("%d", a);
	
	assign();
	printf("a의 값 : %d\n", a);
	
	return 0;
}
void assign(void)
{
	auto int a = 20;
	printf("assing 함수 내 a의 값 : %d\n", a);
}
#endif

/***********************************************************/
// [13-2] 블록 안에서 사용하는 지역변수
/***********************************************************/

#if 0 
#include <stdio.h>

int main(void)
{
	int a = 10;
	printf("here1 : %d\n", a);
	{
		int a = 20;
		printf("here1 : %d\n", a);
		{
			int a = 30;
			printf("here1 : %d\n", a);
		}
	}
	printf("here4 : %d\n", a);

	return 0;
}
#endif

/***********************************************************/
// [13-3] 전역변수의 사용 
/***********************************************************/

#if 0 
#include <stdio.h>

void assign10(void);
void assign20(void);

int a;
int main(void)
{
	//지역 변수는 초기화되지 않으면 사용 불가능.
	//int b;
	//printf("%d\n", b);
	
	//전역 변수는 컴파일러가 자동으로 초기화!!
	//int ->0, double -> 0.0, char ->0
	printf("함수 호출 전 전역변수 a의 값 : %d\n", a);
	assign10();
	assign20();

	printf("함수 호출 전 전역변수 b의 값 : %d\n", a);
	return 0;
}

void assign10(void)
{
	a = 10;
}

void assign20(void)
{
	auto int a;
	a = 20;
}
#endif

/***********************************************************/
// [13-4] 정적 지역변수 
/***********************************************************/

#if 0
#include <stdio.h>

void print_star(void);

int main(void)
{
	for (int i = 0;i < 5;i++) {
		print_star();
	}

	return 0;
}

void print_star(void)
{
	static int a = 1; //static으로 선언하면 함수 호출 후 종료되더라도 static 변수는 소멸되지 않음.
	//선언된 함수에서 정적지역변수를 계속 사용할 수 있다. ==> 함수를 반복 호출하더라도 static 키워드 변수는 유지됨.
	for (int i = 0;i < a;i++)
	{
		printf("*");
	}
	printf("\n");
	a++;
}
#endif

/***********************************************************/
// [13-5] 레지스터 변수 
/***********************************************************/

#if 0 
#include <stdio.h>
#include <time.h>

int main(void)
{
	// 약수의 합
	// 100 -> 100의 약수의 합 sum에 저장
	register int num = 2000000000;	//원래는 register를 선언하면 빨라지지만 요즈음 컴파일러는 알아서 최적화 후 레지스터 배치함.
	register long long sum = 0;	//그래서 register키워드에 따라 성능 차이가 크지 않지만 임베디드 파트에서는 유용.
	long start = clock();
	for (int i = 1; i <= num; i++)
	{
		if (num % i == 0)
		{
			sum += i;
		}
	}
	printf("%d의 약수의 합 : %lld\n", num, sum);
	long end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC; 
	printf("소요 시간 : %lfs\n", time);
	return 0;
}
#endif

/***********************************************************/
// [13-6] 값을 복사해서 전달
/***********************************************************/

#if	0
#include <stdio.h>

int add_ten(int a);

int main(void)
{
	int a = 10;
	printf("함수 호출 전 a : %d\n", a);
	a=add_ten(a);
	printf("함수 호출 후 a : %d\n", a);

	return 0;
}

int add_ten(int a)
{
	a = a + 10;
	return a;
}
#endif

/***********************************************************/
// [13-7] 주소를 전달
/***********************************************************/

#if 0 
#include <stdio.h>

void add_ten(int* pa);
int main(void)
{
	int a = 10;
	//함수 -> 정의 -> 원형(선언) -> 호출
	printf("함수 호출 전 : %d\n", a);
	add_ten(&a);
	printf("함수 호출 후 : %d\n", a);

	return 0;
}
void add_ten(int* pa)
{
	*pa = *pa + 10;
}
#endif

/***********************************************************/
// [13-8] 주소를 반환하는 함수 
/***********************************************************/

#if 0
#include <stdio.h>

int* sum(int a, int b);
int main(void)
{
	int a = 10, b = 20;
	//두 정수의 합을 구하는 sum(a, b)
	int* resp = sum(a, b);
	printf("두 정수의 합 : %d\n", *resp);
	return 0;
}
int* sum(int a, int b)
{
	//주솟값을 반환 시
	//static 키워드를 사용하자
	static int result;
	result = a + b;
	return &result;
}
#endif

/***********************************************************/
// [13-도전] 전역변수 교환 프로그램
/***********************************************************/

#if 0
#include <stdio.h>

void swap(void);

int a, b;//전역변수 a,b 선언
int main(void)
{
	//전역변수 초기화
	a = 10;
	b = 20;

	printf("교환 전 a : %d, b: %d\n", a, b);
	swap();	//전역변수 a, b 치환
	printf("교환 전 a : %d, b: %d\n", a, b);
	return 0;
}
void swap(void) {
	int temp = a;
	a = b;
	b = temp;
}
#endif

/***********************************************************/
// [14-0] 2차원 배열 사용 이유
/***********************************************************/

#if 0 
#include <stdio.h>

int main(void)
{
	int score1[4] = { 10, 20, 30, 40 };
	int score2[4] = { 20, 30, 40, 50 };
	int score3[4] = { 30, 40, 50, 60 };

	return 0;
}
#endif

/***********************************************************/
// [14-1] 네 과목의 총점과 평균
/***********************************************************/

#if 0 
#include <stdio.h>

int main(void)
{
	//국영수과
	int scores[3][4] = {
		{72, 80, 95, 60},	//사람1
		{68, 98, 83, 90},	//사람2
		{75, 72, 84, 90}	//사람3
	};

	//사람2의 3번째 과목 scores[1][2];
	// 각 사람의 총점 구하기
	for (int i = 0;i < 3;i++)
	{
		int sum = 0;
		for (int j = 0;j < 4;j++)
		{
			sum += scores[i][j];
		}
		printf("사람 %d의 점수 총합 : %d\n", i+1, sum);
		printf("사람 %d의 점수 평균 : %.1lf\n", i + 1, (double)sum / 4);
	}
	return 0;
	// 총 12개의 데이터
	// [3][4] : 3행 4열
	// 7번째 데이터의 행, 열의 index는 어떻게 되는가?
	// scores[1][2]
	// 1 ~ 4 -> 열 인덱스 0
	// 5 ~ 8 -> 열 인덱스 1
	// 9 ~ 12 -> 열 인덱스 2
	// 0 ~ 3 -> 1자리
	// 4 ~ 7 -> 2자리
	// like 4진수
	// 7 - 1 / 4
	// 1번째 데이터 열 index -> 0
	// 2번째 데이터 열 index -> 1
	// 3번째 데이터 열 index -> 2
	// 4번째 데이터 열 index -> 3
	// 5번째 데이터 열 index -> 0
	// (7 - 1) % 4
	// n번째 데이터의 행 index -> (n - 1) / 열의 개수
	// n번째 데이터의 열 index -> (n - 1) % 열의 개수
}
#endif

/***********************************************************/
// [14-2] scanf를 통한 2차원 배열 초기화 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int scores[3][4];
	
	//입력부
	for (int j = 0;j < 3;j++)
	{
		for (int i = 0;i < 4;i++)
		{
			scanf("%d", &scores[j][i]);
		}
	}
	
	//출력부
	for (int j = 0;j < 3;j++)
	{
		for (int i = 0;i < 4;i++)
		{
			printf("%4d", scores[j][i]);
		}
		printf("\n");
	}

	return 0;
}
#endif


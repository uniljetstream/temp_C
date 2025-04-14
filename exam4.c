#define _CRT_SECURE_NO_WARNINGS
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

#if 1 
#include <stdio.h>

void swap(int* pa, int* pb);
void bubbleSort(int* pa, int size);
void print_array(int* pa, int size);
void selection_sort(int* pa, int size);
void binary_search(int *pa, int size, int search);
int main(void)
{
	int arr[10] = { 1, 32, 19, 27, 23, 20, 15, 96, 25, 37 };
	int size = sizeof(arr) / sizeof(int);
	printf("배열 원본 : ");
	print_array(arr, size);	
	//bubbleSort(arr, size);
	//print_array(arr, size);
	//selection_sort(arr, size);
	//print_array(arr, size);

	int search = 19;
	binary_search(arr, size, search);	
	print_array(arr, size);
	return 0;
}

void print_array(int* pa, int size) {
	for (int i = 0;i < size;i++) {
		printf("%d ", pa[i]);
	}
	printf("\n");
}
//두 값을 치환하는 swap
void swap(int* pa, int* pb) {
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}
void bubbleSort(int* pa, int size) {
	int max = pa[0];
	for (int i = 1;i < size;i++) {
		for (int j = 0;j < i;j++) {
			if (pa[i] < pa[j]) swap(&pa[i], &pa[j]);
		}
	}
}
void selection_sort(int* pa, int size) {
	//선택정렬
	//버블정렬의 단점을 보완
	//사이클 당 최대 치환 1번
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
void binary_search(int* pa, int size, int search)	//왜 안됨???
{
	// 이진탐색
	int low_index = 0; // 0
	int high_index = size - 1; // 9
	int mid_index = (low_index + high_index) / 2; // 4

	while (1)
	{
		// 23       >      19
		if (pa[mid_index] > search)
		{
			// low_index는 그대로
			high_index = mid_index - 1;
			mid_index = (low_index + high_index) / 2;
		}
		else if (pa[mid_index] < search)
		{
			// high_index는 그대로
			low_index = mid_index + 1;
			mid_index = (low_index + high_index) / 2;
		}
		else
		{
			printf("찾고자 하는 %d은 index %d에 있습니다", search, mid_index);
			break;
		}
	}
}
#endif
/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	r/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

eturn 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif
/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	r/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

eturn 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif

/***********************************************************/
// [0-0] 템플릿
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{


	return 0;
}
#endif


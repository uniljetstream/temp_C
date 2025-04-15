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


#define _CRT_SECURE_NO_WARNINGS

/***********************************************************/
// [14-연습] 2차원 배열 부수기
/***********************************************************/

#if 0
#include <stdio.h>

void print_2d_array(int array[5][5]);
void input_2d_array(int array[5][5]);
void input_2d_array2(int array[5][5]);
void print_2d_array2(int array[5][5]);
void print_2d_array3(int array[5][5]);
void print_2d_array4(int array[5][5]);
void print_2d_array5(int array[5][5]);

int main(void)
{
	//입력부1
	int array[5][5];
	input_2d_array(array);
	//입력부 2
	//for (int i = 0;i < 5;i++)
	//{
	//	for (int j = 0;j < 5;j++)
	//	{
	//		array[i][j] = (5*i)+j+1;
	//	}
	//}

	//출력부
	//이곳에서 사용하는 모든 2차원 배열은 5x5
	//들어온 5x5 배열을 출력
	print_2d_array(array);

	printf("\n");

	input_2d_array2(array);
	print_2d_array(array);

	printf("\n");

	print_2d_array2(array);

	printf("\n");

	print_2d_array3(array);
	printf("\n");

	print_2d_array4(array);
	printf("\n");

	print_2d_array5(array);
	
	//행과 열의 수를 사이즈로부터 구하기
	int array2[10][3];
	// 행의 개수 : 10
	// 열의 개수 : 3
	// array2를 통해서 -> 10
	// array2 : 120byte
	// array2[0] : 12byte

	sizeof(array2); // 120byte
	sizeof(array2[0]); // 12byte
	sizeof(int); // 4byte

	int row = sizeof(array2) / sizeof(array2[0]);
	int column = sizeof(array2[0]) / sizeof(int);

	return 0;
}
void print_2d_array(int array[5][5])
{
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			printf("%3d", array[i][j]);
		}
		printf("\n");
	}
}
void input_2d_array(int array[5][5])
{
	int count = 1;
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			array[i][j] = count++;
		}
	}
}

void input_2d_array2(int array[5][5])
{
	int count = 21;
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			array[i][j] = count++;
		}
	}
}

void print_2d_array2(int array[5][5])
{
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			printf("%3d", array[j][i]);
		}
		printf("\n");
	}
}
void print_2d_array3(int array[5][5])
{
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			printf("%3d", array[i][4-j]);
		}
		printf("\n");
	}
}
void print_2d_array4(int array[5][5])
{
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			printf("%3d", array[4-j][4-i]);
		}
		printf("\n");
	}
}
void print_2d_array5(int array[5][5])
{
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			if (i % 2 == 0) printf("%3d", array[i][j]);
			else printf("%3d", array[i][4 - j]);
			//printf("%3d", pa[i][(1 - i % 2) * j + (i % 2) * (4 - j)]);
		}
		printf("\n");
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
// [14-3] 여러 마리의 동물을 입출력
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	char animal[5][20];
	int row = sizeof(animal) / sizeof(animal[0]);	//5

	for (int i = 0;i < row;i++)
	{
		scanf("%s", animal[i]);

	}
	for (int i = 0;i < row;i++)
	{
		printf("%s ", animal[i]);

	}
	return 0;
}
#endif

/***********************************************************/
// [14-4] 포인터 배열로 여러개의 문자열 출력
/***********************************************************/

#if 0 
#include <stdio.h>

int main(void)
{
	char* pary[5] = { "dog" ,"cat","rabbit","elephant", "hippo" };	//사실상 2차원 배열

	for (int i = 0;i < 5;i++)
	{
		printf("%s\n", pary[i]);
	}
	
	return 0;
}
#endif

/***********************************************************/
// [14-5] 포인터 배열을 통해 int 2차원도 1차원처럼 써보자 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int ary1[4] = { 10, 20, 30, 40 };
	int ary2[4] = { 11, 21, 32, 41 };
	int ary3[4] = { 12, 22, 32, 42 };
	
	int* pary[3] = { ary1, ary2, ary3 };	//2차원 배열을 포인터로 쓰면 1차원 배열처럼 다룰 수 있다. -> 문자열에 쓴다.
	
	//4를 sizeof 값으로 얻을 수 없다.
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 4;j++) {
			printf("%3d", pary[i][j]);
		}
		printf("\n");
	}

	return 0;
}
#endif

/***********************************************************/
// [14-도전] 가로세로의 합의 구하기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int arr[5][6] = { 0 }, count = 1, sum_row = 0, col_sum = 0, sum = 0;

	for (int i = 0;i < 4;i++)	//입력
	{
		for (int j = 0;j < 5;j++)
		{
			arr[i][j] = count++;
		}
	}

	for (int i = 0;i < 4;i++) //row sum
	{
		sum_row = 0;
		for (int j = 0;j < 6;j++)
		{
			if (arr[i][j] != 0) sum_row += arr[i][j];
			else if (arr[i][j] == 0) arr[i][j] = sum_row;
		}
	}
	
	for (int i = 0;i < 5;i++) //col sum
	{
		col_sum = 0;
		for (int j = 0;j < 5;j++)
		{
			if (arr[j][i] != 0) col_sum += arr[j][i];
			else if (arr[j][i] == 0) arr[j][i] = col_sum;
		}
	}

	for (int i = 0;i < 6;i++) {	//1~20 sum
			if (arr[4][i] != 0) sum += arr[4][i];
			else if (arr[4][i] == 0) arr[4][i] = sum;

	}

	for (int i = 0;i < 5;i++)	//출력
	{
		for (int j = 0;j < 6;j++)
		{
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}

	

	return 0;
}
#endif

/***********************************************************/
// [15-1] 이중 포인터
/***********************************************************/

#if 0 
#include <stdio.h>

int main(void)
{
	int a = 10;
	int* pi = &a;
	int** ppi = &pi;
	int*** pppi = &ppi;
	// pppi -> ppi의 주소 300번지
	// *pppi -> 200번지
	// **pppi -> 100번지
	// ***pppi -> 10
	printf("%d\n", a); // 10
	printf("%d\n", pi); // a의 주소!! -> 100번지
	printf("%d\n", *pi); // 10 : 100번지를 찾아가서 값을 참조!!
	printf("%d\n", ppi); // pi의 주소!! -> 200번지
	printf("%d\n", *ppi); // a의 주소!! -> 100번지
	printf("%d\n", **ppi);
	// 10 : (200번지를 찾아가서 값을 참조)번지를 찾아가서 값을 참조!!
	return 0;
}
#endif

/***********************************************************/
// [15-2] 이중 포인터를 활용한 문자열 교환
/***********************************************************/

#if 0
#include <stdio.h>


void swap_pointer(char** ppa, char** ppb);

int main(void)
{
	char* pa = "success";
	char* pb = "failure";

	printf("pa -> %s, pb -> %s\n", pa, pb);
	swap_pointer(&pa, &pb);	//문자열, 2차원배열을 주솟값을 매개변수로 넘길 때 이중포인터에 넣어줘야함.
	printf("pa -> %s, pb -> %s\n", pa, pb);
	

	return 0;
}
void swap_pointer(char** ppa, char** ppb)
{
	int* temp;	//이중포인터를 인자르 받았다. -> 이중포인터를 담는 temp는 *temp여야함(메인문의 pa를 넘겨받은 것이기때문)
	temp = *ppa;
	*ppa = *ppb;
	*ppb = temp;
}
#endif

/***********************************************************/
// [15-3] 배열 포인터 
/***********************************************************/

#if 0
#include <stdio.h>

void print_str(char** ppa, int size);

int main(void)
{
	char* animal = { "dog" };
	printf("%s\n", animal);
	
	char* animals[4] = { "dog", "cat", "rabbit", "hippo" };
	//animals : 문자열(배열) 배열
	print_str(&animal, 4);

	return 0;
}
void print_str(char** ppa, int size)
{
	printf("%c\n", *(*ppa+0)); //d
	printf("%c\n", *(*ppa+1));	//o

	printf("%c\n", **(ppa + 1)); // c
	printf("%c\n", *(*(ppa + 1) + 1)); // a

	for (int i = 0; i < size; i++)
	{
		printf("%s\n", ppa[i]);
	}
}
#endif

/***********************************************************/
// [15-4] 배열의 주소?
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int array[5];
	printf("%u\n", array);	//array의 주소(0번 인덱스 주소)
	printf("%u\n", &array);	//array의 주소값
	printf("%u\n", array + 1);	//1번 인덱스의 주소
	//printf("%u\n", array +1);	//실행하면 안됨. (array의 주소)의 다음 주소
	return 0;
}
#endif

/***********************************************************/
// [15-5] 배열 포인터로 5x5 출력
/***********************************************************/

#if 0
#include <stdio.h>


void print_array(int** ppa);
int main(void)
{
	int array[5][5];
	int count = 1;
	//입력부
	for (int i = 0;i < 5;i++)
		for(int j= 0;j<5;j++)
			array[i][j] = count++;

	print_array(array);

	return 0;
}

//???이해가 안됨.
void print_array(int** ppa)	//인자를 int (*pa)[5] 해도 됨.
{
	int (*pa)[5] = ppa;	//열 갯수대로 분할, pa의 각 원소는 ppa의 0번, 5번, 10번.. 시작 주소를 가지게됨.(5개씩)


	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 5;j++) {
			printf("%3d", pa[i][j]);
		}
		printf("\n");
	}
}
#endif

/***********************************************************/
// [15-6] 함수 포인터를 사용한 함수 호출 
/***********************************************************/

#if 0
#include <stdio.h>

int sum(int, int);	//변수명 생략가능.(메모리만 할당하면 되기 때문)
int main(void)
{
	int result;
	result = sum(10, 20);
	printf("%d\n", result);	//30

	int (*fp)(int, int);	//함수 포인터 선언, 매개변수의 자료형 명시 필수, 변수명은 생략가능, 연산자 우선순위때문에(*fp)괄호 필수
	fp = sum;
	int result2 = fp(20, 30);
	printf("%d\n", result2);

	int result3 = (*sum)(30, 40);	//함수 포인터 선언. 잘안씀.
	printf("%d\n", result3);

	return 0;
}
int sum(int a, int b)
{
	return a + b;
}
#endif

/***********************************************************/
// [15-8] 깔끔한 계산 프로그램 만들기
/***********************************************************/

#if 0
#include <stdio.h>

int sum(int a, int b);
int mul(int a, int b);
int max(int a, int b);
int sub(int a, int b);
void func(int (*fp)(int a, int b));	//함수를 가르키는 함수 -> 함수의 주소를 인수를 취함.

int main(void)
{
	printf("1 두 정수의 합\n");
	printf("2 두 정수의 곱\n");
	printf("3 두 정수 중에서 큰 값 계산\n");
	printf("4 두 정수의 차의 절댓값 \n");
	printf("원하는 연산을 선택하세요 :");

	int menu;
	scanf("%d", &menu);

	switch (menu)
	{
	case 1: func(sum); break;
	case 2: func(mul); break;
	case 3: func(max); break;
	case 4: func(sub); break;
	default: return 1;
	}

	return 0;
}
int sum(int a, int b)
{
	return a + b;
}
int mul(int a, int b)
{
	return a * b;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
int sub(int a, int b)
{
	return a > b ? a - b : b - a;
}
void func(int (*fp)(int a, int b))	//함수를 가르키는 함수 -> 함수의 주소를 인수를 취함.
{
	//sum을 넘기면 fp를 sum처럼 쓸 수 있다.
	printf("두 정수의 값을 입력하세요:");
	int a, b;
	int result; //결과
	scanf("%d %d", &a, &b);
	result = fp(a, b);
	printf("결과값은 : %d\n", result);
}

#endif

/***********************************************************/
// [15-9] void 포인터
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 10;
	double b = 3.14;

	void* vp;
	vp = &a;	//void 포인터는 사용 시 강제 형변환 시켜야 한다.
	printf("%d\n",*((int *)vp));	//정수형 포인터를 가르키는 void 포인터

	vp = &b;
	printf("%.2lf\n", *((double*) vp));

	return 0;
}
#endif

/***********************************************************/
// [16-1] 동작할당을 활용한 배열 생성 
/***********************************************************/

#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	printf("배열의 크기를 입력하세요 : ");
	scanf("%d", &n);
	//void* vp = malloc(n * sizeof(int));	//malloc은 void 포인트여서 void포인터에 담는 것 가능
	//int* array = (int*)vp;	//형변환 이후 array에 담기 가능.

	//int* array = (int*)malloc(n * sizeof(int));	//한 번에 담기도 가능.
	// 5칸짜리 int형 배열 -> 20byte
	// int array[5]; // 20byte를 할당!!
	// malloc : 동적 할당
	// N * sizeof(int) // N개 x 4byte만큼 할당!!
	// (int *) -> void pointer를 casting해서 사용하자!!
	int* array = (int*)malloc(n * sizeof(int));

	//만약, 할당할 여유 공간(메모리)가 없다면
	if (array == NULL) {
		printf("메모리가 부족합니다.\n");
		exit(1);	//stdlib.h에 있는 프로그램 종료 함수.
	}
	//n: 5
	int count = 1;
	for (int i = 0;i < n;i++) array[i] = count++;
	for (int i = 0;i < n;i++) printf("%3d", array[i]);

	//동적할당해제!! 필수
	free(array);
	//단 해제한 이후 더 이상 array를 출력할 수 없다.


	return 0;
}
#endif

/***********************************************************/
// [16-2] 연속할당과 재할당
/***********************************************************/

#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int count = 1;

	printf("배열의 크기를 입력하세요 : ");
	scanf("%d", &n);
	int *array = (int *)calloc(n, sizeof(int));		
	if (array == NULL) {
		printf("메모리가 부족합니다.\n");
		exit(1);	//stdlib.h에 있는 프로그램 종료 함수.
	}

	for (int i = 0;i < n;i++)	//입력, 출력 로직이 분리가 가능한 로직이라 이렇게 하지만. 분리하는 것이 권장.
	{
		array[i] = count++;
		printf("%3d", array[i]);
	}

	int m;
	printf("재조정할 배열의 크기 입력 : ");
	scanf("%d", &m);
	array = (int *)realloc(array, m*sizeof(int));	//재할당. void를 int*를 바꿀 때 명시적 형변환 필요, 그 역은 아님.
	
	for (int i = n;i < m;i++) array[i] = count++;
	for (int i = 0;i < m;i++) printf("%3d", array[i]);
	
	free(array);
	return 0;
}
#endif

/***********************************************************/
// [16-4] 3개의 문자열을 저장하기 위한 동적할당 
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	//문자열의 길이를 모를때 문자열 동적할당(문자열의 갯수는 3개)
	char* str[3];
	char* temp[46] = { '\0' };

	for (int i = 0;i < 3;i++)
	{
		gets(temp);	//temp : rabbit
		str[i] = (char *)malloc(strlen(temp) + 1);
		if (str[i] == NULL) {
			printf("메모리가 부족합니다.\n");
			exit(1);	//stdlib.h에 있는 프로그램 종료 함수.
		}//널문자포함.	//malloc의 메모리 할당 후 할당한 메모리주소 대입.
		//자료형 기본형이 아니다.
		//대입 안됨
		strcpy(str[i], temp);
	}
	for (int i = 0;i < 3;i++) printf("%s ", str[i]);
	for (int i = 0;i, 3;i++) free(str[i]);
	
	return 0;
}
#endif

/***********************************************************/
// [16-5] 몇 개??를 받아 문자열 출력
/***********************************************************/

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(char** ppa); //문자열이라 사이즈 안줘도 된다.

int main(void)
{
	//사용자가 문자열을 입력
	//몇 개 입력할 지 모름
	//최대 20개까지만 입력받도록 설계
	char* str[21];
	char temp[46];
	
	for (int i = 0;i < 20;i++)
	{
		printf("문자열을 입력하세요 : ");
		gets(temp);
		if (strcmp(temp, "end") == 0) break;
		str[i] = (char*)malloc(strlen(temp) + 1);	//널문자 포함
		strcpy(str[i], temp);
		if (str[i] == NULL) exit(1);
	}

	print_array(str);

	for (int i = 0;str[i] != NULL;i++)
	{
		free(str[i]);
	}
	return 0;
}


void print_array(char** ppa)
{
	for (int i = 0;*ppa != NULL;i++)
	{
		printf("%s\n", *ppa);
		ppa++;
	}
}
#endif

/***********************************************************/
// [16-6] 명령 프롬프트 인자를 출력하는 프로그램
/***********************************************************/

#if 0
#include <stdio.h>
#include <stdlib.h> // atoi()

int main(int argc, char** argv)	//main 문의 매개변수는 명령프롬프트에서 실행파일명.exe 인자명1 인자명2..로 받을 수 있다.
{
	// 수정 후 Ctrl + Shift + B 빌드!!
	printf("Hello World!!\n");
	int size = atoi(argv[1]);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	/*for (int i = 0; i < argc; i++)
	{
	   printf("%s\n", argv[i]);
	}*/

	return 0;
}
#endif

/***********************************************************/
// [17-1] 구조체 선언 및 사용
/***********************************************************/

#if 0
#include <stdio.h>

struct contact
{	//구조체 선언!!(반드시 main 앞에)

	//멤버
	//자료형 멤버명;
	char* name;
	int age;
	char* mbti;
};

struct student
{
	char ch1;
	short num;
	char ch2;
	int score;
	char ch3;	//여기 있으면 패딩바이트 때문에 구조체 크기가 줄어듬
	double grade;
	//char ch3;
};

struct exam
{
	char c1;
	int num;
};
//구조체는 8바이트 단위로 크기가 정해진다.
int main(void)
{
	struct contact p1;
	struct contact p2;
	struct student s1;
	struct exam e1;

	printf("e1의 크기 %d\n", sizeof(e1)); //8바이트트
	printf("s1의 크기 : %d\n", sizeof(s1));

	// . : 안에, ~의
	p1.name = "홍길동";
	p1.age = 20;
	p1.mbti = "mbti";

	p2.name = "아이유";
	p2.age = 33;
	p2.mbti = "INFP";

	printf("이름 : %s, 나이 : %d세, mbti : %s\n", p1.name, p1.age, p1.mbti);
	printf("이름 : %s, 나이 : %d세, mbti : %s\n", p2.name, p2.age, p2.mbti);

	return 0;
}
#endif

/***********************************************************/
// [17-2] 멤버의 자료형
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
	//학번과 학점 정보 추가
	int id;
	double grade;
};

struct profile
{
	char name[20]; //이름
	int age;	//나이
	double height;	//키
	char* info;	//자기소개

	struct student st;	//앞에 있는 구조체만 사용 가능.
};


int main(void)
{
	struct profile p1;
	strcpy(p1.name, "홍길동");
	p1.age = 20;
	p1.height = 200.0;
	
	//자기소개 문구를 입력받아 info에 대입	
	printf("자기소개 입력 : ");
	char temp[80];
	gets(temp);
	p1.info = (char*)malloc(strlen(temp) + 1);
	strcpy(p1.info, temp);

	p1.st.id = 2025;
	p1.st.grade = 4.5;

	printf("이름 : %s, 나이 : %d세, 키 : %.1lfcm\n", p1.name, p1.age, p1.height);
	printf("자기소개 : %s\n", p1.info);
	printf("학번 : %d, 학점 : %.1f\n", p1.st.id, p1.st.grade);

	return 0;
}
#endif

/***********************************************************/
// [17-3] 최고 학점의 학생
/***********************************************************/

#if 0
#include <stdio.h>

struct student
{
	int id;
	char name[20];
	double grade;
};

int main(void)
{
	//구조체 선언과 동시에 초기화
	struct student s1 = { 315, "홍길동", 2.4 }, s2 = { 316, "임꺽정", 3.7 }, s3 = { 317, "심청이", 4.5 };

	//s1, s2, s3의 학점을 탐색하면서
	//가장 높은 학점을 가지고 있는 사람의
	//다음과 같이 학번, 이름, 학점을 출력
	//학번 : , 이름 : , 학점 :

	struct student max;

	max = s1;
	if (max.grade < s2.grade) max = s2;
	if (max.grade < s3.grade) max = s3;

	printf("학점 : %d, 이름 : %s, 학점 : %.1lf", max.id, max.name, max.grade);

	return 0;
	
	//구조체는 결국 자료형(사용자 정의된)
	//대입 연산 가능.
}
#endif

/***********************************************************/
// [17-6] 구조체 포인터와 간접 멤버 접근 연산자  
/***********************************************************/

#if 0 
#include <stdio.h>

struct score
{
	int kor;
	int eng;
	int math;
};

int main(void)
{
	struct score s1 = { 70, 80, 90 };
	struct score* ps = &s1; //s1를 가르킴.

	printf("국어: %d\n", s1.kor);
	printf("영어: %d\n", (*ps).eng);	//연산자 우선순위 때문에 괄호 필요
	printf("수학: %d\n", ps -> math);	//-> 간접 멤버 접근 연산자

	return 0;
}
#endif

/***********************************************************/
// [17-7] 구조체 배열 
/***********************************************************/

#if 0
#include <stdio.h>


void print_list(struct student* lp, int size);

struct student
{
	int id;
	char name[20];
	double grade;
};

int main(void)
{

	struct student s[3] = { {315, "홍길동", 2.4}, {316, "임꺽정", 3.7}, {317, "심청이", 4.5} };

	print_list(s, 3);
	//3명의 정보를 다음과 같이 3행으로 출력
	//학번 : , 이름 : , 학점 :


	return 0;
}

void print_list(struct student *lp, int size)
{
	for (int i = 0;i < size;i++)
	{
		printf("학번 : %d, 이름 : %s, 학점 : %.1lf\n", lp[i].id, (*(lp+i)).name, (lp+i)->grade);
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



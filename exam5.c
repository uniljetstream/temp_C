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
// [17-8] 구조체 선언 
/***********************************************************/

#if 0
#include <stdio.h>

struct student
{
	int num;
	double grade;
} s1;	//구조체 변수를 이렇게도 선언 가능.

struct student s1;	//이렇게도 가능.

int main(void)
{
	
	struct student //구조체를 한번만 쓸거면 main문 안에도 선언 가능
	{
		int num;
		double grade;
	};

	return 0;
}
#endif

/***********************************************************/
// [17-9] 자기 참조 구조체
/***********************************************************/

#if 0 
#include <stdio.h>

struct list
{
	int num;
	struct list* next;	//struct list*형의 변수
};

int main(void)
{
	//linked list
	struct list a = { 10, }, b = { 20, }, c = { 30, };
	//처음 값인 a를 가르키기 위한 주소
	//head의 값은 절대 변경하지 않는다.
	const struct list* head = &a;

	a.next = &b;
	b.next = &c;

	//printf("a: %d, a.next의 주소 : %u\n", a.num, a.next);
	//printf("b: %d, b.next의 주소 : %u\n", b.num, b.next);
	//printf("c: %d, c.next의 주소 : %u\n", c.num, c.next);

	printf("a : %d, a가 가리키는 주소 : %d\n", a.num, a.next);
	printf("b : %d, b가 가리키는 주소 : %d\n", a.next->num, a.next->next);
	printf("c : %d, c가 가리키는 주소 : %d\n", a.next->next->num, a.next->next->next);

	//linked list 탐색
	printf("list all : ");
	struct list* current = head;
	while(current != NULL)
	{
		printf("%d ", current->num);
		current = current->next;
	}

	return 0;
}
#endif

/***********************************************************/
// [17-10] 공용체 union 
/***********************************************************/

#if 0 
#include <stdio.h>
union data
{
	int i;
	double d;
} weather_data;

int main(void)
{
	//패킷을 통해 타 디바이스에서 데이터를 전공하고자한다.
	//2개 data가 오는데
	//1. 정수형 습도
	//2. 실수형 기온
	//예시 데이터 : 84,17.1,85,17.2,86,17.3
	char* str = "84";
	char* str = "84";
	int count = 1;
	if (count % 2 == 1)	//이럴 때 쓴다.
	{
		weather_data.i = 84;
		count++;
	}
	else
	{
		weather_data.d = 17.1;
		count++;
	}

	return 0;
}
#endif

/***********************************************************/
// [17-11] 열거형
/***********************************************************/

#if 0
#include <stdio.h>

enum discout {NORMAL, EALRY = 4000, TELECOME = 2000};	//초깃값 설정하면 그 다음 변수에 별도로 초깃값을 설정하지 않으면 그이전값 +1
//기본적으로 0, 1, 2, 3...

int main(void)
{
	// 영화 예매 프로그램
	int menu;
	printf("[1]없음 [2]조조 [3]통신사 할인\n");
	printf("할인 권종을 선택하세요 : ");
	scanf("%d", &menu);

	int ticket_price = 14000;
	switch (menu)
	{
	case 1: ticket_price -= NORMAL; break;
	case 2: ticket_price -= EALRY; break;
	case 3: ticket_price -= TELECOME; break;
	default:
		break;
	}
	
	return 0;
}
#endif

/***********************************************************/
// [17-12] typedef을 사용한 사용자 자료형 재정의
/***********************************************************/

#if 0
#include <stdio.h>
#include <time.h>

typedef signed int 정수;

struct student
{
	int num;
	double grade;
};

typedef struct student Student;	

typedef struct
{
	char name[20];
	int age;
}; Profile; //구조체이름을 정하지 않고 typedef로 별칭을 바로 정함.

int main(void)
{
	clock_t t = clock();	//typedef된 time.h의 예시

	//구조체를 재정의하면
	//대문자로 시작하자
	//재정의하다러라도 struct student는 뜰 수 있다.
	Student s1 = { 315, 3.7 };

	int a = 10;
	정수 b = 20;
	printf("%d, %d\n", a, b);



	return 0;
}
#endif

/***********************************************************/
// [18-1,2] 파일 열고 닫기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	FILE* fp;	//파일 구조체 포인터
	const char* path = "C:\\Users\\INTEL07\\Desktop\\workspace_c\\a.txt";
	//상대 경로로 경로 정할 때
	//우리가 지금 바라 봤을 때 -> ctrl + f5
	//컴파일 후 배포 할 때는 exe 기준.
	const char* path2 = "..\\a.txt";

	fp = fopen(path, "r");
	if (fp == NULL)
	{
		printf("파일이 열리지 않았습니다.");
		return 1;	//0은 main은 정상적 동작을 말함. 1은 비정상적 동작.
	}
	printf("파일이 열렸습니다.\n");

	int ch;
	while (1)
	{
		ch = fgetc(fp);
		if (ch == EOF)
		{
			break;
		}
		putchar(ch);
	}

	fclose(fp);	//열었으면 닫자!! 열었으면 닫자!

	return 0;
}
#endif

/***********************************************************/
// [18-3] 파일에 문자열 쓰기 
/***********************************************************/
#if 0
#include <stdio.h>

int main(void)
{
	FILE* fp;
	// 끝에 a.txt -> b.txt로 바꿔주세요!!
	const char* path = "C:\\Users\\INTEL07\\Desktop\\workspace_c\\b.txt";
	fp = fopen(path, "w");
	if (fp == NULL) return 1;

	char* words = "C CLEAR!!";
	while (*words != NULL) fputc(*words++, fp);
	fputc('\n', fp);

	fclose(fp); // 열었으면 닫자, 열었으면 닫자
	return 0;
}
#endif

/***********************************************************/
// [18-3-연습] 파일 입출력 연습
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>

int main(void)
{
	// 현재, a.txt -> Hello World!!
	// b.txt -> C CLEAR!!
	// 두 파일을 읽어서
	// 문자열에 string.h -> strcpy, strcat 활용해서
	// 새로운 문자열 Hello World!! C CLEAR!! 를 만들어서
	// 내용을 저장하는 c.txt를 만들자
	FILE* fpa, *fpb, *fpc;	//파일 구조체 포인터
	char* origin_path = "C:\\Users\\INTEL07\\Desktop\\workspace_c\\";
	char path_a[256] = { 0, };
	char path_b[256] = { 0, };
	char path_c[256] = { 0, };
	strcpy(path_a, origin_path);
	strcpy(path_b, origin_path);
	strcpy(path_c, origin_path);
	strcat(path_a, "a.txt");
	strcat(path_b, "b.txt");
	strcat(path_c, "c.txt");

	fpa = fopen(path_a, "r");
	if (fpa == NULL) return 1;

	fpb = fopen(path_b, "r");
	if (fpb == NULL) return 2;

	fpc = fopen(path_c, "w");
	if (fpc == NULL) return 3;

	char temp[256] = { 0, };
	// 1. a.txt 읽어서 temp에 담기!! // Hello World!!
	int ch;
	char* pt = temp;
	while (1)
	{
		ch = fgetc(fpa);
		*pt++ = ch;
		if (ch == EOF)
		{
			break;
		}
	}
	pt--;
	*pt = '\0';

	// 2. b.txt 읽어서 temp에 추가!! // Hello World!! C CLEAR!!
	while (1)
	{
		ch = fgetc(fpb);
		*pt++ = ch;
		if (ch == EOF)
		{
			break;
		}

	}
	pt--;
	*pt = '\0';

	// 3. temp를 c.txt에 그대로 쓰기
	pt = temp;
	while (1)
	{
		fputc(*pt++, fpc);
		if (*pt == NULL)
		{
			break;
		}
	}
	fputc('\n', fpc);

	fclose(fpa);
	fclose(fpb);
	fclose(fpc);

	return 0;
}
#endif
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
   FILE *fpa, *fpb, *fpc;
   const char *origin_path = "C:\\Users\\Intel Master\\Desktop\\workspace_c\\";
   char path_a[256] = { 0, };
   char path_b[256] = { 0, };
   char path_c[256] = { 0, };
   strcpy(path_a, origin_path);
   strcpy(path_b, origin_path);
   strcpy(path_c, origin_path);
   strcat(path_a, "a.txt");
   strcat(path_b, "b.txt");
   strcat(path_c, "c.txt");

   fpa = fopen(path_a, "r");
   if (fpa == NULL) return 1;

   fpb = fopen(path_b, "r");
   if (fpb == NULL) return 2;

   fpc = fopen(path_c, "w");
   if (fpc == NULL) return 3;

   char temp[256] = { 0, };
   // 1. a.txt 읽어서 temp에 담기!! // Hello World!!
   // 2. b.txt 읽어서 temp에 추가!! // Hello World!! C CLEAR!!
   // 3. temp를 c.txt에 그대로 쓰기
   char* pt = temp;
   int ch;
   while (1)
   {
	  ch = fgetc(fpa);
	  *pt++ = ch;
	  if (ch == EOF) break;
   }
   pt--;

   while (1)
   {
	  ch = fgetc(fpb);
	  *pt++ = ch;
	  if (ch == EOF) break;
   }
   pt--;
   *pt = '\0';

   pt = temp; // 쓰기 위해 포인터 맨 왼쪽으로 이동!!
   while (1)
   {
	  fputc(*pt, fpc);
	  pt++;
	  if (*pt == NULL) break;
   }
   fputc('\n', fpc);

   printf("%s\n", temp);

   fclose(fpa);
   fclose(fpb);
   fclose(fpc);

   return 0;
}
*/

/***********************************************************/
// [18-4] 표준 입출력 스트림을 사용한 문자열 입력, stdin, stdout
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int ch;
	while (1)
	{
		ch = getchar();
		if (ch == EOF) break;
		putchar(ch);
	}

	while (1)
	{
		ch = fgetc(stdin);	//현재 os와 연결된 키보드라는 뜻
		if (ch == EOF) break;
		fputc(ch, stdout);
	}
	return 0;
}
#endif

/***********************************************************/
// [18-6] 파일 형태와 개방 모드가 다른 경우
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	FILE* fp;
	char* path = "C:\\Users\\INTEL07\\Desktop\\workspace_c\\d.txt";

	fp = fopen(path, "wb");
	if (fp == NULL) return 1;

	int array[10] = { 13, 10, 13, 13, 10, 26, 13, 10, 13, 10 };
	for (int i = 0;i < 10;i++)
	{
		fputc(array[i], fp);
	}

	fclose(fp);

	//txt 형식으로 읽어보자
	fp = fopen(path, "rt");
	int ch;
	while (1)
	{
		ch = fgetc(fp);
		if (ch == EOF) break;
		printf("%3d", ch);
	}
	fclose(fp);
	return 0;
}
#endif

/***********************************************************/
// [18-7] a+모드로 파일의 내용을 확인하며 출력
/***********************************************************/

#if 0 
#include <stdio.h>
#include <string.h>

int main(void)
{
	//FILE* fp;
	////경로 끝에 music.txt
	//char* path = "C:\\Users\\INTEL07\\Desktop\\workspace_c\\music.txt";

	////추가될 데이터(문자열) 임시 저장되는 공간
	//char str[20];
	//
	//fp = fopen(path, "a+");
	//if (fp == NULL) return 1;

	////logic
	//while (1)
	//{
	//	printf("노래 제목 : ");
	//	scanf("%s", str);
	//	//end : 프로그램 종료
	//	//list : 현재까지 저장된 모드 노래 출력
	//	if (strcmp(str, "end") == 0) break;
	//	else if (strcmp(str, "list") == 0)
	//	{
	//		//모든 정보 출력
	//		//fp를 맨 첫줄
	//		//맨 앞으로 이동시키자
	//		fseek(fp, 0, SEEK_SET);

	//		while (1)
	//		{
	//			fgets(str, strlen(str+1), fp);
	//			//행 끝에 도달하면
	//			//feof() ->
	//			if (feof(fp) != 0) break;
	//			printf("%s", str);
	//		}
	//	}
	//	else
	//	{
	//		//while(1) fputc(), 문장 전체를 입력하는 fprint 두가지 다 가능.
	//		fprintf(fp, "%s\n", str);
	//	}
	//	//str에 들어 있는 노래 정보를 
	//	//d.txt에 쓰자
	//	//맨 끝에 쓰자

	//	//while (1)
	//	//{
	//	//	//만약에 아무 내용도 없다면 ㄱㅊ
	//	//	// 내용이 있다면 -> fp를 가장 마지막 행으로 이동!!

	//	//	//fseek(파일 포인터, 이동위치(양수 우, 음수 좌), 기준)
	//	//	//fseek(fp,0 , SEEK_END);
	//	//	//한 문장 씩 가져온다 <- 엔터 치는 곳까지
	//	//	fgets(str, strlen(str), fp);

	//	//	//fprintf -> 한 줄 씩 출력

	//	//}
	//}

	//fclose(fp);
	//return 0;
	FILE* fp;
	// 경로 끝에 music.txt
	char* path = "C:\\Users\\INTEL07\\Desktop\\workspace_c\\music.txt";
	// 추가될 데이터(문자열) 임시 저장되는 공간
	char str[20];

	fp = fopen(path, "a+");
	if (fp == NULL) return 1;

	// logic

	while (1) {
		printf("노래 제목 : "); // 아몬드 초콜릿
		scanf("%s", str);
		if (strcmp(str, "end") == 0) break; // end <- 프로그램 종료
		else if (strcmp(str, "list") == 0) // list <- 현재까지 저장된 모든 노래 출력!!
		{
			// 모든 정보 출력하기 전
			// fp를 맨 첫 줄 
			// 맨 앞으로 이동시키자
			fseek(fp, 0, SEEK_SET);
			while (1)
			{
				// 개행(\n)가져오기 위해 +1
				fgets(str, strlen(str) + 1, fp);
				// 행 끝에 도달하면
				// feof() -> 
				if (feof(fp) != 0) break;
				printf("%s", str);
			}
		}
		// while(1) fputc(), -> 문장 전체를 입력, fputs() fprintf
		else fprintf(fp, "%s\n", str);
		// str에 들어 있는 노래 정보를
		// 맨 끝에 d.txt에 쓰자!! 
	}

	fclose(fp); // 열었으면 닫자, 열었으면 닫자!!
	return 0;

}
#endif

/***********************************************************/
// [18-8] 여러 줄의 문장을 입력해 한 줄로 내보내기
/***********************************************************/

#if 0 
#include <stdio.h>
#include <string.h> // strlen
int main(void)
{
	// a : Hello World!!
	// b : C CLEAR!!
	// 2개를 e에 내보내기
	char* path_a = "C:\\Users\\Intel Master\\Desktop\\workspace_c\\a.txt";
	char* path_b = "C:\\Users\\Intel Master\\Desktop\\workspace_c\\b.txt";
	char* path_e = "C:\\Users\\Intel Master\\Desktop\\workspace_c\\e.txt";

	FILE* fpa, * fpb, * fpe;
	fpa = fopen(path_a, "r");
	if (fpa == NULL) return 1;

	fpb = fopen(path_b, "r");
	if (fpb == NULL) return 2;

	fpe = fopen(path_e, "w");
	if (fpe == NULL) return 3;

	char str[80];
	char* result;

	while (1)
	{
		result = fgets(str, strlen(str) + 1, fpa);
		if (result == NULL)
		{

			/*while (1)
			{
			   result = fgets(str, strlen(str) + 1, fpb);
			   if (result == NULL) break;
			}*/
			break;
		}
		fputs(result, fpe);
	}
	fclose(fpa);
	fclose(fpb);
	fclose(fpe);

	return 0;
}
#endif

/***********************************************************/
// [18-9] 다양한 형식으로 내보내기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	FILE* fp;
	char* path = "C:\\Users\\INTEL07\\Desktop\\workspace_c\\girlfriend.txt";
	fp = fopen(path, "r");
	if (fp == NULL) return 1;

	FILE* fs;
	char *path_score = "C:\\Users\\INTEL07\\Desktop\\workspace_c\\score.txt";
	fs = fopen(path_score, "w");
	if (fs == NULL) return 2;
	
	//이름 국영수
	char name[20];
	int kor, eng, math;
	int total, result;
	double avg;

	while (1)
	{
		result = fscanf(fp, "%s %d %d %d", name, &kor, &eng, &math);	//fp의 한줄 씩 읽는다.
		if (result == EOF) break;
		total = kor + eng + math;
		avg = total / 3.0;

		fprintf(fs, "%3s %4d %.lf\n", name, total, avg);	//fs에 한 줄 쓴다.
	}
	fclose(fp);
	fclose(fs);

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



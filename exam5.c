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



#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdarg.h"
#include "time.h"

#define debug_info(fmt,...) printf("%s [%d] -<%s>:\n"fmt,__FILE__,__LINE__,__FUNCTION__,##__VA_ARGS__);


//大小端判断 
void is_little_big(void)
{
	unsigned int num = 0xaabbccdd;
	unsigned char * buff = (unsigned char *)&num;

	if(buff[0] == 0xaa)
	{
		printf("big\r\n");
	}
	else if(buff[0] == 0xdd)
	{
		printf("little\r\n");
	}

	for(int i=0; i<4; i++)
	{
		printf("buff[%d] = %2x\r\n", i, buff[i]);
	}
}

int src[2][4] = {{0, 1, 2, 3},{4, 5, 6, 7},};
int dest[4][2] = {0};


//矩阵转换 
void convert(int (*src)[2][4], int (*dest)[4][2], int line, int row)
{

	for(int i=0; i<line; i++)
	{
		for(int j=0; j<row; j++)
		{
			(*dest)[j][i] = (*src)[i][j];
		}
	}

	for(int i=0; i<row; i++)
	{
		for(int j=0; j<line; j++)
		{
			printf("%d ", (*dest)[i][j]);
		}
		printf("\r\n");
	}

}

//打印菱形 
int printf_lx(unsigned int line)
{
	if(line%2 == 0)
	{
		return -1;
	}

	int x1, x2;

	int pos = line/2;
	int i, j;

	for(i=0; i<pos; i++)
	{
		x1 = pos-i;
		x2 = pos+i;

		for(int j=0; j<line; j++)
		{
			if((j==x1) || (j==x2))
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	for(int i=pos; i>=0; i--)
	{
		x1 = pos-i;
		x2 = pos+i;

		for(int j=0; j<line; j++)
		{
			if((j==x1) || (j==x2))
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}

}


void creat_rand_buff(int * buff, int len)
{
	clock_t num = clock();
	srand(num);
	for(int i=0; i<len; i++)
	{
		buff[i] = rand()%10000;
		srand(buff[i]);
	}
}


void print_buff(int * buff, int len)
{
	for(int i=0; i<len; i++)
	{
		printf("%d ", buff[i]);
	}
	printf("\n\n");
}


#define BUFF_NUM	50000
int wait_sort1[BUFF_NUM] = {0};
int wait_sort2[BUFF_NUM] = {0};
int wait_sort3[BUFF_NUM] = {0};
//冒泡排序 
void sort_up(int * buff, int len)
{
	int i=0;
	int j=0;

	for(i=0; i<len; i++)
	{
		for(j=i; j<len; j++)
		{
			if(buff[i]>buff[j])
			{
				int temp = buff[i];
				buff[i] = buff[j];
				buff[j] = temp;
			}
		}
	}
}
//选择排序 
void sort_select(int * buff, int len)
{
	int i=0;
	int j=0;
	int min = 0;
	int min_index = 0;

	for(i=0; i<len; i++)
	{
		min = buff[i];
		for(j=i; j<len; j++)
		{
			if(min>buff[j])
			{
				min = buff[j];
				min_index = j;
			}
		}
		int temp = buff[i];
		buff[i] = min;
		buff[min_index] = temp;
	}

}


int getIndex(int* arr, int low, int high)
{
	// 基准数据
	int tmp = arr[low];
	while (low < high)
	{
		// 当队尾的元素大于等于基准数据时,向前挪动high指针
		while (low < high && arr[high] >= tmp)
		{
			high--;
		}
		// 如果队尾元素小于tmp了,需要将其赋值给low
		arr[low] = arr[high];
		// 当队首元素小于等于tmp时,向前挪动low指针
		while (low < high && arr[low] <= tmp)
		{
			low++;
		}
		// 当队首元素大于tmp时,需要将其赋值给high
		arr[high] = arr[low];

	}
	// 跳出循环时low和high相等,此时的low或high就是tmp的正确索引位置
	// 由原理部分可以很清楚的知道low位置的值并不是tmp,所以需要将tmp赋值给arr[low]
	arr[low] = tmp;
	return low; // 返回tmp的正确位置
}

//快速排序 
void quickSort(int* arr, int low, int high)
{
	if (low < high)
	{
		// 找寻基准数据的正确索引
		int index = getIndex(arr, low, high);

		// 进行迭代对index之前和之后的数组进行相同的操作使整个数组变成有序
		//quickSort(arr, 0, index - 1); 之前的版本，这种姿势有很大的性能问题，谢谢大家的建议
		quickSort(arr, low, index - 1);
		quickSort(arr, index + 1, high);
	}

}

#if	(BUFF_NUM >= 50) 
#define PRINT_NUM	50
#else
#define PRINT_NUM	(BUFF_NUM/2)
#endif
int main(void)
{
	int len = sizeof(wait_sort1)/sizeof(wait_sort1[0]);
	clock_t num = 0;
	is_little_big();
	printf_lx(5);
	
	creat_rand_buff(wait_sort1, BUFF_NUM);
	memcpy(wait_sort2, wait_sort1, BUFF_NUM*4);
	memcpy(wait_sort3, wait_sort1, BUFF_NUM*4);
	
	print_buff(wait_sort1, PRINT_NUM);
	print_buff(wait_sort2, PRINT_NUM);
	print_buff(wait_sort3, PRINT_NUM);

	num = clock();
	printf("start:%d\n", num);
	sort_up(wait_sort1, len);
	num = clock();
	printf("end:%d\n", num);

	num = clock();
	printf("start:%d\n", num);
	sort_select(wait_sort2, len);
	num = clock();
	printf("end:%d\n", num);

	
	num = clock();
	printf("start:%d\n", num);
	quickSort(wait_sort3, 0, len-1);
	num = clock();
	printf("end:%d\n", num);


	print_buff(wait_sort1, PRINT_NUM);
	print_buff(wait_sort2, PRINT_NUM);
	print_buff(wait_sort3, PRINT_NUM);
}




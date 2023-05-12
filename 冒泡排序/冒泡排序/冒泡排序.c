#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	printf("请输入10个数值进行从小到大排序：");
	int arr[10];
	int i = 0,j=0;
	int zh = 0;
	for (i = 0; i < 10; i++)
	scanf("%d", &arr[i]);
	for (j = 1; j < 10; j++)
	{
		for (i = 0; i < 10 - j; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				zh = arr[i]; arr[i] = arr[i + 1]; arr[i + 1] = zh;
			}
		}
	}
	for (i = 0; i <10; i++)
		printf("%d ",arr[i] );
	return 0;
}

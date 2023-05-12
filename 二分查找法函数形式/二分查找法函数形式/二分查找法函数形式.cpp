// 二分查找法函数形式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <stdio.h>

int binary_search(int arr[], int k, int sz)
{int left = 0;
int right = sz - 1;

while (left <= right)
{
	int mid = left + (right - left) / 2;
	if (arr[mid] < k)
	{
		left = mid + 1;
	}
	else if (arr[mid] > k)
	{
		right = mid - 1;
	}
	else
	{
		return mid;//找到了返回下标
	}
}
return -1;//找不到返回-1，不能返回0因为找到了返回的下标可能是0
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 7;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = binary_search(arr, k, sz);
	if (ret == -1)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了，下标是：%d\n", ret);
	}

	return 0;
}
//结果为：找到了，下标是：6
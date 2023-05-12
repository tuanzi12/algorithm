// 二分查找法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<stdio.h>

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 7;
	int sz = sizeof(arr) / sizeof(arr[0]);//计算数组元素个数
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		//int mid = (left + right) / 2;当数值太大可能出现溢出问题
		int mid = left + (right - left) / 2;//不会出现溢出问题

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
			printf("找到了，下标是:%d\n", mid);
			break;
		}
	}
	if (left > right)
		printf("找不到\n");
	return 0;
}
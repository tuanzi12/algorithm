#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	float j, y;
	printf("请输入距离：");
	scanf("%f", &j);
	if (j < 3)
		y = 8;
	else if (j >= 3 && j < 8)
		y = 8 + (j - 3) * 2;
	else if (j >= 8)
		y = 18 + (j - 8) * 2.3;
	printf("您的车费为：%f\n", y); return 0;
}
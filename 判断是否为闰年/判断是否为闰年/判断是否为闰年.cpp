// 判断是否为闰年.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
int is_leap_year(int i)
{
    return  ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0));
}
int main()
{
    int y = 0;
    for (y = 1000; y <= 2000; y++)
    {
        if (is_leap_year(y) == 1)
        {
            printf("%d ", y);
        }
    }
    return 0;

}

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define OVERFLOW -2
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define STACK_INIT_SIZE 100                               //顺序栈存储空间的初始分配量
#define STACKINCREMENT 10
typedef int SElemType;
typedef int Status;


//顺序栈的存储结构
typedef struct {
	SElemType* base;                                      //栈底指针
	SElemType* top;                                       //栈顶指针
	int stacksize;                                        //栈可用的最大容量
}SqStack;


//顺序栈的初始化
Status InitStack(SqStack& S)                                           //构建一个空栈S
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));    //为顺序栈动态分配一个容量为STACK_INIT_SIZE的数组空间 
	if (!S.base)
		exit(OVERFLOW);                                               //存储分配失败
	S.top = S.base;                                                    //top初始为base，空栈
	S.stacksize = STACK_INIT_SIZE;                                     //stacksize置为栈的最大容量STACK_INIT_SIZE
	return OK;
}


//顺序栈的入栈
Status Push(SqStack& S, SElemType e)
{
	if (S.top - S.base == S.stacksize) {
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));     //栈满，追加存储空间
		if (!S.base)
			return OVERFLOW;                                               //存储分配失败
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;                                                      //元素e压入栈顶，栈顶指针加一
	return OK;
}


//顺序栈的出栈
Status Pop(SqStack& S, SElemType& e)                            //         
{
	if (S.top == S.base)
		return ERROR;                                          //栈空，返回ERROR
	e = *--S.top;                                              //栈顶指针减一，将栈顶元素赋给e
	return e;
}


//主函数
int main()
{
	int choice=1;
	char c;
	int n, m;
	SElemType e;
	SqStack S;
	InitStack(S);
	printf("**********进制转换**********\n");
	printf("1.请输入一个十进制数n\n");
	printf("2.请输入转换的进制m\n");
	printf("3.进制转换\n");
	printf("4.继续或退出(y/n)\n");
	while (choice)                                          //保证操作的选择循环进行
	{
		printf("请选择操作1--4:\n");
		scanf("%d", &choice);
		if (choice > 4 || choice <= 0)                          //如果输入的操作数不符合条件，则退出程序
		{
			printf("您输入的数据有误!\n");
			return 0;                                      //返回0，结束循环，退出程序
		}
		while (choice <= 4)                                 //进行操作1--4的选择
		{
			if (choice == 1)
			{
				printf("请输入一个十进制数:\n");
				scanf("%d", &n);
				break;
			}
			if (choice == 2)
			{
				printf("请输入转换的进制:\n");
				scanf("%d", &m);
				break;
			}
			if (choice == 3)
			{
				printf("进制转换:\n");
				while (n != 0)
				{
					Push(S, n % m);
					n = n / m;
				}
				while (S.top != S.base)
				{
					e = Pop(S, e);
					if (e < 10)
						printf("%d", e);
					else if (e >= 10)
					{
						if (e == 10)
							printf("A");
						if (e == 12)
							printf("B");
						if (e == 13)
							printf("C");
						if (e == 14)
							printf("D");
						if (e == 15)
							printf("E");
					}
				}
				printf("\n");
				break;
			}
			if (choice == 4)
			{
				printf("请输入y/n选择继续或退出\n");
				getchar();
				scanf("%c", &c);
				if (c == 'y')
				{
					printf("请输入操作1--4继续运行程序:\n");
					scanf("%d", &choice);
				}
				if (c == 'n')
					return 0;                                     //返回0，结束循环，退出程序
			}
		}
	}
}
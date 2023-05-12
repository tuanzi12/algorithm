#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define OVERFLOW -2
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define STACK_INIT_SIZE 100                               //˳��ջ�洢�ռ�ĳ�ʼ������
#define STACKINCREMENT 10
typedef int SElemType;
typedef int Status;


//˳��ջ�Ĵ洢�ṹ
typedef struct {
	SElemType* base;                                      //ջ��ָ��
	SElemType* top;                                       //ջ��ָ��
	int stacksize;                                        //ջ���õ��������
}SqStack;


//˳��ջ�ĳ�ʼ��
Status InitStack(SqStack& S)                                           //����һ����ջS
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));    //Ϊ˳��ջ��̬����һ������ΪSTACK_INIT_SIZE������ռ� 
	if (!S.base)
		exit(OVERFLOW);                                               //�洢����ʧ��
	S.top = S.base;                                                    //top��ʼΪbase����ջ
	S.stacksize = STACK_INIT_SIZE;                                     //stacksize��Ϊջ���������STACK_INIT_SIZE
	return OK;
}


//˳��ջ����ջ
Status Push(SqStack& S, SElemType e)
{
	if (S.top - S.base == S.stacksize) {
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));     //ջ����׷�Ӵ洢�ռ�
		if (!S.base)
			return OVERFLOW;                                               //�洢����ʧ��
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;                                                      //Ԫ��eѹ��ջ����ջ��ָ���һ
	return OK;
}


//˳��ջ�ĳ�ջ
Status Pop(SqStack& S, SElemType& e)                            //         
{
	if (S.top == S.base)
		return ERROR;                                          //ջ�գ�����ERROR
	e = *--S.top;                                              //ջ��ָ���һ����ջ��Ԫ�ظ���e
	return e;
}


//������
int main()
{
	int choice=1;
	char c;
	int n, m;
	SElemType e;
	SqStack S;
	InitStack(S);
	printf("**********����ת��**********\n");
	printf("1.������һ��ʮ������n\n");
	printf("2.������ת���Ľ���m\n");
	printf("3.����ת��\n");
	printf("4.�������˳�(y/n)\n");
	while (choice)                                          //��֤������ѡ��ѭ������
	{
		printf("��ѡ�����1--4:\n");
		scanf("%d", &choice);
		if (choice > 4 || choice <= 0)                          //�������Ĳ��������������������˳�����
		{
			printf("���������������!\n");
			return 0;                                      //����0������ѭ�����˳�����
		}
		while (choice <= 4)                                 //���в���1--4��ѡ��
		{
			if (choice == 1)
			{
				printf("������һ��ʮ������:\n");
				scanf("%d", &n);
				break;
			}
			if (choice == 2)
			{
				printf("������ת���Ľ���:\n");
				scanf("%d", &m);
				break;
			}
			if (choice == 3)
			{
				printf("����ת��:\n");
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
				printf("������y/nѡ��������˳�\n");
				getchar();
				scanf("%c", &c);
				if (c == 'y')
				{
					printf("���������1--4�������г���:\n");
					scanf("%d", &choice);
				}
				if (c == 'n')
					return 0;                                     //����0������ѭ�����˳�����
			}
		}
	}
}
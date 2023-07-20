#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void menu()
{
	printf("********************************\n");
	printf("***** 1. add     2. del    *****\n");
	printf("***** 3. search  4. modify *****\n");
	printf("***** 5. show    6. sort   *****\n");
	printf("***** 7.clear    0. exit   *****\n");
	printf("********************************\n");
}
void test()
{
	contact con;
	int input = 0;
	InitContact(&con);
	do
	{
		menu(); 
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case CLEAR:
			ClearContact(&con);
			break;
		case EXIT:
			SaveContact(&con);
			DestroyContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����, ����ѡ��\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
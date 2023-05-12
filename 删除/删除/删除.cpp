#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define max 10
typedef int ElemType;
typedef struct {
	ElemType data[max];
	int length;
}SqList;
void CreateX(SqList* L)
{
	int i, j;
	scanf("%d", &j);
	L->length = j;
	printf("请输入%d个数值：", j);
	for (i = 0; i<L->length; i++)
		scanf("%d", &L->data[i]);
}
void DeleteX(SqList* L,ElemType *e)
{
	int i,flag=0;
	for (i = 0; i < L->length; i++)
	{
		if (L->data[i] == *e)
			flag = 1;
		if (flag==1)
			L->data[i] = L->data[i + 1];
	}
	L->length--;
	printf("删除后的数据为：");
	for (i = 0; i < L->length; i++)
		printf("%d", L->data[i]);
}
int main() {
	SqList L;
	ElemType x;
	printf("请输入数值的长度：");
	CreateX(&L);
	printf("请输入你要删除的数值：\n");
	scanf("%d", &x);
	DeleteX(&L,&x);
}
#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
/*旧版
void InitContact(contact* pc)
{
	assert(pc);
	memset(pc->data, 0, sizeof(pc->data));
	pc->sz = 0;
}*/
/*静态开辟
void AddContact(contact* pc)
{
	if (pc->sz == MAX)
	{
		printf("已满");
		return;
	}
	printf("请输入名字：");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄：");
	scanf("%d", &pc->data[pc->sz].age);
	printf("请输入性别：");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话：");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址 ：");
	scanf("%s", pc->data[pc->sz].address);
	pc->sz++;
	printf("成功增加一位联系人");
}*/

//动态开辟
/*void InitContact( contact* pc)
{
	assert(pc);
	pc->data = (PeoInfo*)malloc(DEFAULT_SIZE * sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->sz = 0;
	pc->max = DEFAULT_SIZE;
}*/

static int CheckCapacity(contact *pc)
{
	if (pc->sz == pc->max)
	{
		PeoInfo* ptr = realloc(pc->data, (pc->max + INC_SIZE) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			perror("CheckCapacity");
			return 0;
		}
		else
		{
			pc->data = ptr;
			pc->max += INC_SIZE;
			return 1;
		}
	}
	return 1;
}
static void LoadContact(contact *pc)
{
	FILE* pf = fopen("data.dat", "rb");
	if (pf == NULL)
	{
		perror("LoadContact");
		return;
	}
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		if (CheckCapacity(pc) == 0)
		{
			return;
		}
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	fclose(pf);
	pf = NULL;
}

void SaveContact(contact* pc)
{
	FILE* pf = fopen("data.dat", "wb");
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;

}
void InitContact( contact* pc)
{
	assert(pc);
	pc->data = (PeoInfo*)malloc(DEFAULT_SIZE * sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->sz = 0;
	pc->max = DEFAULT_SIZE;
	LoadContact(pc);
}
void AddContact( contact* pc)
{
	assert(pc);
	if ( CheckCapacity(pc) == 0)
	{
		return;
	}
	printf("请输入名字：");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄：");
	scanf("%d", &pc->data[pc->sz].age);
	printf("请输入性别：");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话：");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址 ：");
	scanf("%s", pc->data[pc->sz].address);
	pc->sz++;
	printf("成功增加一位联系人\n");
}

void ShowContact(const contact* pc)
{
	int i = 0;
	if (pc->sz != 0)
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
		for (i = 0; i < pc->sz; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\n",
				pc->data[i].name,
				pc->data[i].age,
				pc->data[i].sex,
				pc->data[i].tele,
				pc->data[i].address);
		}
	}
	else
	{
		printf("表为空无法输出！\n");
	}
	
}

int FindByName(contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void SearchContact(contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找的名字");
	scanf("%s", name);
	int pos = FindByName(pc,name);
	if (pos == -1)
	{
		printf("要查找的人不在");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].address);
	}
}

void DelContact(contact* pc)
{
		if (pc->sz == 0)
		{
			printf("通讯录为空，无法删除\n");
			return;
		}
		char name[MAX_NAME] = { 0 };
		assert(pc);
		//删除
		printf("请输入要删除的人名字:>");
		scanf("%s", name);
		//找到要删除的人
		int del = FindByName(pc, name);
		if (del == -1)
		{
			printf("要删除的人不存在\n");
			return;
		}
		int i = 0;
		//删除坐标位del的联系人方法1
		for (i = del; i < pc->sz - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("成功删除联系人\n");
		//方法2：
		/*memmove(&(pc->data[del]), &pc->data[del + 1], ((pc->sz) - del - 1) * (sizeof(pc->data[0])));
		pc->sz--;*/
		//方法3：
		/*PeoInfo tmp = pc->data[del];
		pc->data[del] = pc->data[pc->sz - 1];
		pc->data[pc->sz - 1] = tmp;
		pc->sz--;*/
}

void ModifyContact(contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
		printf("要修改的人不存在\n");
	else
	{
		printf("请输入名字:>");
		scanf("%s", pc->data[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &(pc->data[pos].age));
		printf("请输入性别:>");
		scanf("%s", pc->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", pc->data[pos].tele);
		printf("请输入地址:>");
		scanf("%s", pc->data[pos].address);

		printf("修改成功\n");
	
}
}

void ClearContact(contact* pc)
{
	assert(pc);
	pc->sz = 0;
	printf("表已清空\n");
}

int cmp_by_name(const void* p1, const void* p2)
{
	return (int)strcmp((*(PeoInfo*)p1).name, (*(PeoInfo*)p2).name);
}
void SortContact(contact* pc)
{
	assert(pc);
	if (pc->sz < 2)
	{
		printf("表记录少于两条，无法排序\n");
		return;
	}
	else qsort(pc, pc->sz, sizeof(pc->data[0]), cmp_by_name);

}

void DestroyContact(contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->max = pc->sz = 0;
}
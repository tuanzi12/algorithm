#pragma once
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#define DEFAULT_SIZE 3
#define INC_SIZE 2

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	CLEAR
};
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char address[MAX_ADDR];
}PeoInfo;
//初阶固定大小
//typedef struct contact
//{
//	PeoInfo data[MAX];
//	int sz;
//}contact;

//动态内存改进
typedef struct contact
{
	PeoInfo *data;
	int sz;
	int max;
}contact;
void InitContact(contact* pc);//创建表

void AddContact(contact* pc);//添加联系人信息

void ShowContact(const contact* pc);//显示所有联系人信息

void ModifyContact(contact* pc);//修改指定联系人信息

void DelContact(contact* pc);//删除指定联系人信息

void SearchContact(contact* pc);//查找指定联系人信息

void ClearContact(contact* pc);//清空所有联系人

void SortContact(contact* pc);//根据名字排序

void SaveContact(contact* pc);//保存在本地

void DestroyContact(contact* pc);//销毁表

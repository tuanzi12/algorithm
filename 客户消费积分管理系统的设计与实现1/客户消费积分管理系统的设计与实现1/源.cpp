#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct customer {
    char num[10];
    char name[10];
    char phone[20];
    char sex[10];
    int mon;
    struct customer* next;
};

typedef struct customer cu;

cu* head = NULL;  //头节点

/*函数声明*/
void CreatList();  //创建表
void printmenu();  //打印菜单
void InsertList();  //插入新纪录并返回菜单
void LocateList();  //查找信息
void AlterList();  //修改信息
void DeleteList();  //删除记录
void DisplayList();  //显示记录
void DestroyList();  //退出菜单

/*主函数*/
int main() {

    printmenu();
    return 0;
}

/*函数定义*/
void printmenu() {
    int n;
    printf("\n\n\t\t客户消费积分管理系统\n");
    printf("\t--------------------------------------------------\n");
    printf("\t|                                                |\n");
    printf("\t|     1.创建表                2.插入新纪录       |\n");
    printf("\t|                                                |\n");
    printf("\t|     3.查找信息              4.修改信息         |\n");
    printf("\t|                                                |\n");
    printf("\t|     5.删除记录              6.显示记录         |\n");
    printf("\t|                                                |\n");
    printf("\t|     7.退出菜单                                 |\n");
    printf("\t|                                                |\n");
    printf("\t--------------------------------------------------\n");
    printf("请选择功能（1-7）：");
    scanf("%d", &n);
    switch (n) {
    case 1:
        CreatList();
        break;
    case 2:
        InsertList();
        break;
    case 3:
        LocateList();
        break;
    case 4:
        AlterList();
        break;
    case 5:
        DeleteList();
        break;
    case 6:
        DisplayList();
        break;
    case 7:
        DestroyList();
        break;
    default:
        printf("输入有误，请重新选择（1-7）：");
        printmenu();
    }
}

void CreatList() {
    cu* p, * q=NULL;
    int n, i;
    printf("请输入客户信息的个数：");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        p = (cu*)malloc(sizeof(cu));
        printf("\n\n请输入第%d个客户信息：\n", i + 1);
        printf("客户号：");
        scanf("%s", p->num);
        printf("客户姓名：");
        scanf("%s", p->name);
        printf("客户电话：");
        scanf("%s", p->phone);
        printf("客户性别：");
        scanf("%s", p->sex);
        printf("客户积分：");
        scanf("%d", &(p->mon));
        if (head == NULL) {
            head = p;
            q = p;
        }
        else {
            q->next = p;
            q = p;
        }
    }
    q->next = NULL;
    printf("已成功创建表！\n");
    printmenu();
}

void InsertList() {
    cu* p, * q;
    p = (cu*)malloc(sizeof(cu));
    printf("\n\n请输入要插入的客户信息：\n");
    printf("客户号：");
    scanf("%s", p->num);
    printf("客户姓名：");
    scanf("%s", p->name);
    printf("客户电话：");
    scanf("%s", p->phone);
    printf("客户性别：");
    scanf("%s", p->sex);
    printf("客户积分：");
    scanf("%d", &(p->mon));
    if (head == NULL) {
        head = p;
        q = p;
    }
    else {
        q = head;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
    p->next = NULL;
    printf("插入成功！\n");
    printmenu();
}

void LocateList() {
    cu* p;
    char num[10];
    int flag = 0;
    printf("\n\n请输入要查找的客户号：");
    scanf("%s", num);
    p = head;
    while (p != NULL) {
        if (strcmp(p->num, num) == 0) {
            printf("-----------------------------------------\n");
            printf("\t客户号\t客户姓名\t客户电话\t客户性别\t客户积分\n");
            printf("-----------------------------------------\n");
            printf("\t%s\t%s\t%s\t%s\t%d\n", p->num, p->name, p->phone, p->sex, p->mon);
            printf("-----------------------------------------\n");
            flag = 1;
            break;
        }
        else {
            p = p->next;
        }
    }
    if (flag == 0) {
        printf("未找到该客户信息！\n");
    }
    printmenu();
}

void AlterList() {
    cu* p;
    char num[10];
    int flag = 0;
    printf("\n\n请输入要修改的客户号：");
    scanf("%s", num);
    p = head;
    while (p != NULL) {
        if (strcmp(p->num, num) == 0) {
            printf("-----------------------------------------\n");
            printf("\t客户号\t客户姓名\t客户电话\t客户性别\t客户积分\n");
            printf("-----------------------------------------\n");
            printf("\t%s\t%s\t%s\t%s\t%d\n", p->num, p->name, p->phone, p->sex, p->mon);
            printf("-----------------------------------------\n");
            printf("请输入新的客户信息：\n");
            printf("客户号：");
            scanf("%s", p->num);
            printf("客户姓名：");
            scanf("%s", p->name);
            printf("客户电话：");
            scanf("%s", p->phone);
            printf("客户性别：");
            scanf("%s", p->sex);
            printf("客户积分：");
            scanf("%d", &(p->mon));
            printf("修改成功！\n");
            flag = 1;
            break;
        }
        else {
            p = p->next;
        }
    }
    if (flag == 0) {
        printf("未找到该客户信息！\n");
    }
    printmenu();
}

void DeleteList() {
    cu* p, * q=NULL;
    char num[10];
    int flag = 0;
    printf("\n\n请输入要删除的客户号：");
    scanf("%s", num);
    p = head;
    while (p != NULL) {
        if (strcmp(p->num, num) == 0) {
            if (head == p) {
                head = p->next;
            }
            else {
                q->next = p->next;
            }
            free(p);
            printf("删除成功！\n");
            flag = 1;
            break;
        }
        else {
            q = p;
            p = p->next;
        }
    }
    if (flag == 0) {
        printf("未找到该客户信息！\n");
    }
    printmenu();
}

void DisplayList() {
    cu* p;
    if (head == NULL) {
        printf("暂无客户信息！\n");
    }
    else {
        p = head;
        printf("\n\n\t客户号\t客户姓名\t客户电话\t客户性别\t客户积分\n");
        printf("--------------------------------------------------\n");
        while (p != NULL) {
            printf("\t%s\t%s\t%s\t%s\t%d\n", p->num, p->name, p->phone, p->sex, p->mon);
            p = p->next;
        }
        printf("--------------------------------------------------\n");
    }
    printmenu();
}

void DestroyList() {
    cu* p;
    while (head != NULL) {
        p = head;
        head = head->next;
        free(p);
    }
    printf("已退出程序！\n");
}
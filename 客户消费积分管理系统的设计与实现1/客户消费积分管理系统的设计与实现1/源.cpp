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

cu* head = NULL;  //ͷ�ڵ�

/*��������*/
void CreatList();  //������
void printmenu();  //��ӡ�˵�
void InsertList();  //�����¼�¼�����ز˵�
void LocateList();  //������Ϣ
void AlterList();  //�޸���Ϣ
void DeleteList();  //ɾ����¼
void DisplayList();  //��ʾ��¼
void DestroyList();  //�˳��˵�

/*������*/
int main() {

    printmenu();
    return 0;
}

/*��������*/
void printmenu() {
    int n;
    printf("\n\n\t\t�ͻ����ѻ��ֹ���ϵͳ\n");
    printf("\t--------------------------------------------------\n");
    printf("\t|                                                |\n");
    printf("\t|     1.������                2.�����¼�¼       |\n");
    printf("\t|                                                |\n");
    printf("\t|     3.������Ϣ              4.�޸���Ϣ         |\n");
    printf("\t|                                                |\n");
    printf("\t|     5.ɾ����¼              6.��ʾ��¼         |\n");
    printf("\t|                                                |\n");
    printf("\t|     7.�˳��˵�                                 |\n");
    printf("\t|                                                |\n");
    printf("\t--------------------------------------------------\n");
    printf("��ѡ���ܣ�1-7����");
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
        printf("��������������ѡ��1-7����");
        printmenu();
    }
}

void CreatList() {
    cu* p, * q=NULL;
    int n, i;
    printf("������ͻ���Ϣ�ĸ�����");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        p = (cu*)malloc(sizeof(cu));
        printf("\n\n�������%d���ͻ���Ϣ��\n", i + 1);
        printf("�ͻ��ţ�");
        scanf("%s", p->num);
        printf("�ͻ�������");
        scanf("%s", p->name);
        printf("�ͻ��绰��");
        scanf("%s", p->phone);
        printf("�ͻ��Ա�");
        scanf("%s", p->sex);
        printf("�ͻ����֣�");
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
    printf("�ѳɹ�������\n");
    printmenu();
}

void InsertList() {
    cu* p, * q;
    p = (cu*)malloc(sizeof(cu));
    printf("\n\n������Ҫ����Ŀͻ���Ϣ��\n");
    printf("�ͻ��ţ�");
    scanf("%s", p->num);
    printf("�ͻ�������");
    scanf("%s", p->name);
    printf("�ͻ��绰��");
    scanf("%s", p->phone);
    printf("�ͻ��Ա�");
    scanf("%s", p->sex);
    printf("�ͻ����֣�");
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
    printf("����ɹ���\n");
    printmenu();
}

void LocateList() {
    cu* p;
    char num[10];
    int flag = 0;
    printf("\n\n������Ҫ���ҵĿͻ��ţ�");
    scanf("%s", num);
    p = head;
    while (p != NULL) {
        if (strcmp(p->num, num) == 0) {
            printf("-----------------------------------------\n");
            printf("\t�ͻ���\t�ͻ�����\t�ͻ��绰\t�ͻ��Ա�\t�ͻ�����\n");
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
        printf("δ�ҵ��ÿͻ���Ϣ��\n");
    }
    printmenu();
}

void AlterList() {
    cu* p;
    char num[10];
    int flag = 0;
    printf("\n\n������Ҫ�޸ĵĿͻ��ţ�");
    scanf("%s", num);
    p = head;
    while (p != NULL) {
        if (strcmp(p->num, num) == 0) {
            printf("-----------------------------------------\n");
            printf("\t�ͻ���\t�ͻ�����\t�ͻ��绰\t�ͻ��Ա�\t�ͻ�����\n");
            printf("-----------------------------------------\n");
            printf("\t%s\t%s\t%s\t%s\t%d\n", p->num, p->name, p->phone, p->sex, p->mon);
            printf("-----------------------------------------\n");
            printf("�������µĿͻ���Ϣ��\n");
            printf("�ͻ��ţ�");
            scanf("%s", p->num);
            printf("�ͻ�������");
            scanf("%s", p->name);
            printf("�ͻ��绰��");
            scanf("%s", p->phone);
            printf("�ͻ��Ա�");
            scanf("%s", p->sex);
            printf("�ͻ����֣�");
            scanf("%d", &(p->mon));
            printf("�޸ĳɹ���\n");
            flag = 1;
            break;
        }
        else {
            p = p->next;
        }
    }
    if (flag == 0) {
        printf("δ�ҵ��ÿͻ���Ϣ��\n");
    }
    printmenu();
}

void DeleteList() {
    cu* p, * q=NULL;
    char num[10];
    int flag = 0;
    printf("\n\n������Ҫɾ���Ŀͻ��ţ�");
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
            printf("ɾ���ɹ���\n");
            flag = 1;
            break;
        }
        else {
            q = p;
            p = p->next;
        }
    }
    if (flag == 0) {
        printf("δ�ҵ��ÿͻ���Ϣ��\n");
    }
    printmenu();
}

void DisplayList() {
    cu* p;
    if (head == NULL) {
        printf("���޿ͻ���Ϣ��\n");
    }
    else {
        p = head;
        printf("\n\n\t�ͻ���\t�ͻ�����\t�ͻ��绰\t�ͻ��Ա�\t�ͻ�����\n");
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
    printf("���˳�����\n");
}
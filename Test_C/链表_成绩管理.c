/*测试数据
2015 xiaoming nan 19 89
2014 liuhu nan 20 75
2202 xiaopang nv 19 80
2005 liuliu nan 22 81
8900 xiaohong nv 21 80
0 0 0 0 0
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define len sizeof(struct student)
typedef struct student
{
	long num;
	char s[10];
	char sex[6];
	int y;
	double sj;
	struct student *next;
} stu;
int n; //统计节点数

//链表创建
stu *creat()
{
	stu *head, *p1, *p2;
	n = 0;
	p1 = p2 = (stu *)malloc(len);
	printf("学号-姓名-性别-年龄-计算机\n");
	scanf("%ld %s %s %d %lf", &p1->num, p1->s, p1->sex, &p1->y, &p1->sj);
	head = NULL;
	while (p1->num != 0)
	{
		n++;
		if (n == 1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (stu *)malloc(len);
		scanf("%ld %s %s %d %lf", &p1->num, p1->s, p1->sex, &p1->y, &p1->sj);
	}
	free(p1);
	p2->next = NULL;
	return (head);
}
//按学号删除
stu *del(stu *head, double nu) //nu代表学号
{
	stu *t = head, *in;
	in = t;
	int flag = 0;

	while (t != NULL)
	{
		if (t->num == nu)
		{
			flag = 1;
			if (head == t)
			{
				head = t->next;
				free(t);
				in = t = head;
				continue;
			}
			else if (t->next == NULL)
			{
				in->next = NULL;
				free(t);
				t = in;
			}
			else
			{
				in->next = t->next;
				free(t);
				t = in;
			}
		}
		in = t;
		t = t->next;
	}
	if (!flag)
		printf("未找到该学号\n");
	return head;
}
//输出链表
void print(stu *head)
{
	stu *p1 = head;
	if (head != NULL)
	{
		while (p1 != NULL)
		{
			printf("%-10ld %-10s %-5s %-2d %-4.2lf\n", p1->num, p1->s, p1->sex, p1->y, p1->sj);
			p1 = p1->next;
		}
	}
	else
	{
		puts("空链表");
	}
}
//把链表分成b，c
void apart(stu *head)
{
	stu *t = head;
	stu *c, *c1 = NULL, *hc = NULL, *b, *hb = NULL, *b1 = NULL;
	while (t != NULL)
	{
		if (t->sj >= 80)
		{
			b = (stu *)malloc(len);
			b->num = t->num;
			strcpy(b->s, t->s);
			strcpy(b->sex, t->sex);
			b->sj = t->sj;
			b->y = t->y;
			if (b1 == NULL)
			{
				b1 = b;
				hb = b;
			}
			else
				b1->next = b;
			b1 = b;
		}
		else
		{
			c = (stu *)malloc(len);
			c->num = t->num;
			strcpy(c->s, t->s);
			strcpy(c->sex, t->sex);
			c->sj = t->sj;
			c->y = t->y;
			if (c1 == NULL)
			{
				c1 = c;
				hc = c;
			}
			else
				c1->next = c;
			c1 = c;
		}
		t = t->next;
	}
	c->next = b->next = NULL;
	printf("链表b:\n");
	print(hb);
	printf("链表c:\n");
	print(hc);
	free(hb);
	free(hc);
}
//链表排序（选择）
stu *change(stu *head)
{
	stu *t = head, *p = t->next;
	long t1;
	char q[10];
	int t2;
	double t3;
	while (t != NULL)
	{
		while (p != NULL)
		{
			if (t->sj > p->sj)
			{
				t3 = t->sj;
				t->sj = p->sj;
				p->sj = t3;
				t1 = t->num;
				t->num = p->num;
				p->num = t1;
				t2 = t->y;
				t->y = p->y;
				p->y = t2;
				strcpy(q, t->s);
				strcpy(t->s, p->s);
				strcpy(p->s, q);
				strcpy(q, t->sex);
				strcpy(t->sex, p->sex);
				strcpy(p->sex, q);
			}
			p = p->next;
		}
		t = t->next;
		if (t != NULL)
			p = t->next;
		else
			p = NULL;
	}
	return head;
}
//插入新的节点
stu *insert(stu *head)
{
	int flag = 1;
	stu *t = head, *pnew, *p = head;
	pnew = (stu *)malloc(len);
	printf("输入新节点的学号-姓名-性别-年龄-计算机\n");
	scanf("%ld %s %s %d %lf", &pnew->num, pnew->s, pnew->sex, &pnew->y, &pnew->sj);
	getchar();
	while (t != NULL)
	{
		if (pnew->sj <= t->sj)
		{
			if (t == head)
			{
				head = pnew;
				pnew->next = p;
			}
			else
			{
				p->next = pnew;
				pnew->next = t;
			}
			flag = 0;
			break;
		}
		p = t;
		t = t->next;
	}
	if (flag)
	{
		p->next = pnew;
		pnew->next = NULL;
	}

	return head;
}
//按姓名删除节点
stu *del_name(stu *head)
{
	stu *t = head, *p = head;
	char s[10];
	int flag = 0;
	printf("删除的节点姓名:\n");
	gets(s);
	while (t != NULL)
	{
		if (strcmp(t->s, s) == 0)
		{
			flag = 1;
			if (t == head)
			{
				head = t->next;
				free(t);
				p = t = head;
				continue;
			}
			else if (t->next == NULL)
			{
				p->next = NULL;
				free(t);
				t = p;
			}
			else
			{
				p->next = t->next;
				free(t);
				t = p;
			}
			flag = 0;
			//break;    //是否需要删除重复的名字
		}
		p = t;
		t = t->next;
	}
	if (!flag)
		printf("找不到该节点\n");

	return head;
}
int main()
{
	stu *head = creat();
	print(head);
	double k = 0;
	apart(head);
	printf("输入删除学号:\n");
	scanf("%lf", &k);
	head = del(head, k);
	printf("删除后:\n");
	print(head);
	head = change(head);
	printf("排序后:\n");
	print(head);
	head = insert(head);
	printf("插入节点后\n");
	print(head);
	head = del_name(head);
	printf("删除节点后:\n");
	print(head);

	return 0;
}

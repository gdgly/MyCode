

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
#include<math.h>
#include<windows.h>

//定义链表bai节点
typedef struct LNode
{
	int data;
	struct LNode *next;
} LNode, *Linklist;
 
//创建链表
Linklist create()
{
	int i, n;
	//i用于下面du循环,n用来存放有效节点的字数zhi
	Linklist p, L;
	
	scanf("%d", &n);
	printf("\r\n");
	L = (Linklist)malloc(sizeof(LNode));
	// 分配一个不存放有效数据的头结点dao
	L->next = NULL;
	for(i = 0; i < n; i++)
	{
		p = (Linklist)malloc(sizeof(LNode)); //生成新节点
		scanf("%d", &p->data);	//输入元素值
		p->next = L->next;
		L->next = p;
	}
	return L;
	//返回头节点 ;
}
//链表反转输出 
Linklist ReverseList(Linklist L, int st)    //st为1时输出结点数据
{
	if(L->next != NULL)
		ReverseList(L->next, 1);
	if(st)
		printf("%d ", L->data);
		
	return L;
}
 
void my_put(Linklist L)
{
	Linklist p;
	p = L->next;
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
 
int main()
{
	Linklist L;
	printf("Please input N = ");
	
	//while(1);
	L = create();
	printf("A: ");
	my_put(L);
	printf("B: ");
	ReverseList(L, 0);
	my_put(L);
	//附加结点未保存数据，故第二参数为0
	return 0;
}



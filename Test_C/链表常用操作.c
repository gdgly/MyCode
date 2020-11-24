#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#define DATA_TYPE int

struct Node
{
	DATA_TYPE data;
	struct Node *next;
};


struct Node *PHEAD;


void print_list(struct Node *head)
{
	struct Node *temp = head;

	while (temp != NULL)
	{
		printf("%d ", temp->data);
		
		temp = temp->next;
		
	}
	
	printf("\r\n");
}

void list_append(struct Node *cur, DATA_TYPE data)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

	temp->data = data;
	temp->next = NULL;

	cur->next = temp;
}

struct Node *list_creat(DATA_TYPE buff[], int len)
{
	struct Node * head = NULL;

	struct Node * tail = NULL;

	int i = 0;

	for (i = 0; i < len; i++)
	{
#if 1 
		struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = buff[i];
		temp->next = NULL;
		
		if(head == NULL)
		{
			head = temp;
			tail = temp;
			
			
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
			
		}

#else
		list_append(tail, buff[i]);
		tail = tail->next;
#endif
	}

	return head;
}

// 头插法
/***
list_node * dummy = new list_node();
dummy->next = nullptr;

list_node * cur = head;
list_node * temp;
while(cur)
{
	temp = cur;
	cur = cur->next;
	temp->next = dummy->next;
	dummy->next = temp;
}
return dummy->next;
***/
//链表反序 
struct Node * reverse_list(struct Node * head)
{
	//三指针法
	struct Node *q, *cur, *p;
	q = NULL;
	cur = head;
	p = head;
	
	printf("%s \r\n", __FUNCTION__);
	
	
	while (cur != NULL)
	{
		p = p->next;
		cur->next = q;
		q = cur;
		cur = p;
		
		//print_list(q);

	}
	return q;
}

//链表反转输出 
struct Node * reverse_print(struct Node * head, int st)	//st为1时输出结点数据
{
	static int cnt = 0;
	if(cnt++ == 0)
	{
		printf("%s \r\n", __FUNCTION__);
	}
	
	
	if(head->next != NULL)
		reverse_print(head->next, 1);
	if(st)
		printf("%d ", head->data);
		
	return head;
}


void list_insert(struct Node * head, int pos, DATA_TYPE data)
{
	//struct Node * temp = &head;
}


void main(void)
{

	int data[] = {10, 12, 33, 41, 25, 26, 87, 48};

	PHEAD = list_creat(data, 8);
	print_list(PHEAD);

	PHEAD = reverse_list(PHEAD);
	print_list(PHEAD);
	
	
	reverse_print(PHEAD, 1);
}



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#define DATA_TYPE	int

typedef struct Node
{
	DATA_TYPE data;
	struct Node * next;
	
}NODE;

typedef NODE* P_NODE;


void print_list(NODE* head)
{
	NODE* temp = head;
	
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void list_append(NODE* head, DATA_TYPE data)
{
	NODE *temp = malloc(sizeof(NODE));
	
	temp->data = data;
	
	head->next = temp;
}


void list_creat(NODE * head, DATA_TYPE buff[], int len)
{
	head = malloc(sizeof(NODE));
	
	NODE * temp = head;
	int i = 0;

	for(i=1; i<len; i++)
	{
		list_append(temp, i);
		temp = temp->next;
		
	}
	
	print_list(head);
	
}

void list_insert(NODE* head, int pos, DATA_TYPE data)
{
	//NODE * temp = &head;
	
}

NODE * P_HEAD;

void main(void)
{
	
	int data[100] = {0};
	for(int i=0; i<100; i++)
	{
		data[i] = i;
	}
	list_creat(P_HEAD, data, 100);

}


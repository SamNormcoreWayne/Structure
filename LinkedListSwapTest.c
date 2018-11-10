#include <stdio.h>
#include <stdlib.h>

struct LinkedList
{
	int val;
	struct LinkedList * next;
};

struct LinkedList swap(struct LinkedList * head)
{
	struct LinkedList prev = *head;
	struct LinkedList cur = *head;
	if(head && head->next)
	{
		head = head->next;
		head->next = &prev;
		
	}
	return cur;
}

int main()
{
	struct LinkedList *head, *ele_1, *ele_2;
	ele_2 = (struct LinkedList *)malloc(sizeof(struct LinkedList *));
	ele_1 = (struct LinkedList *)malloc(sizeof(struct LinkedList *));
	head = (struct LinkedList *)malloc(sizeof(struct LinkedList *));

	ele_2->val = 2;
	ele_2->next = NULL;
	ele_1->val = 1;
	ele_1->next = ele_2;
	head->val = 0;
	head->next = ele_1;
	printf("%d %x\n", head->val, head);
	printf("%d %x\n", head->next->val, head->next);
	printf("%d %x\n", head->next->next->val, head->next->next);
	printf("start, \n");
	*head = swap(head);
	printf("%d %x\n", head->val, head);
	printf("%d %x\n", head->next->val, head->next);
	printf("%d %x\n", head->next->next->val, head->next->next);
}

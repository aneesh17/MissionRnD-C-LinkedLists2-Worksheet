/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node* reverse(struct node* head, struct node* newnode)
{
	if (newnode->next == NULL)
	{
		return newnode;
	}
	head = reverse(head, newnode->next);
	struct node* tempNode = newnode->next;
	tempNode->next = newnode;
	newnode->next = NULL;
	return(head);
}


struct node * reverseLinkedList(struct node *head) {
	if (head != NULL)
		head = reverse(head, head);
	return head;
}

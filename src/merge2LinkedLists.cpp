/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node* newNode(int ele)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->num = ele;
	newnode->next = NULL;
	return(newnode);
}

void addNewnum(struct node** newnode, int ele)
{
	struct node* temp = *newnode;
	if (*newnode == NULL)
	{
		(*newnode) = newNode(ele);
		(*newnode)->next = NULL;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = (struct node*)malloc(sizeof(struct node));
		temp->next->num = ele;
		temp->next->next = NULL;
	}
}

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node* result = NULL;
	while (head1 != NULL && head2 != NULL)
	{
		if (head1->num<head2->num)
		{
			addNewnum(&result, head1->num);
			head1 = head1->next;
		}
		else
		{
			addNewnum(&result, head2->num);
			head2 = head2->next;
		}
	}
	while (head1 != NULL)
	{
		addNewnum(&result, head1->num);
		head1 = head1->next;
	}
	while (head2 != NULL)
	{
		addNewnum(&result, head2->num);
		head2 = head2->next;
	}
	return(result);
	return NULL;
}

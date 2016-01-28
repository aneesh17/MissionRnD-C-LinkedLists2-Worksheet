/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5
2->8->9    2->1->8->1->9->1
INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	int count = 0;	
	struct node *prev;
	struct node *temp_head = head;	
	while (temp_head != NULL)
	{				
		count++;
		if (count == K)
		{			
			struct node* temp = (struct node*)malloc(sizeof(struct node));
			temp->next = temp_head->next;
			temp->num = K;
			temp_head->next = temp;
			temp_head = temp_head->next;
			count = 0;
		}
		temp_head = temp_head->next;
	}
	return head;
	return NULL;
}

/*
OVERVIEW: Given a single sorted linked list find the median num of the single linked list.
Median is the middle num.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list nums.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {

	if (head != NULL)
	{
		struct node* temp = head;
		int numOfNodes = 0, counter;
		int result;
		while (temp->next != NULL)
		{
			numOfNodes++;
			temp = temp->next;
		}
		counter = (numOfNodes) / 2;

		while (counter>0)
		{
			head = head->next;
			counter--;
		}
		result = (numOfNodes % 2 == 1) ? ((head->num + head->next->num) / 2) : (head->num);
		return(result);
	}
	return -1;
}

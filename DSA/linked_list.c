#include<stdio.h>
#include<stdlib.h>
int main()
{
	struct node{
		int data;
		struct node *next;
	}

	int choice;

	struct node *newNode, *head, *temp;
	head = NULL;

	newNode = (struct node *) malloc(sizeof(struct node));
	printf("\nEnter data for newNode: ");
	scanf("%d",&newNode->data);
	newNode->next = NULL;

	if(head ==NULL){
		head = temp = newNode;
	}else{
		temp -> next = newNode;
		temp = newNode;
	}

	printf("\nDo you want to add mode node (yes for 0/ No for 1): ");
	scanf("%d",&choice);

	return 0;
}
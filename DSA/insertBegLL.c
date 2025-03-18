#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *newNode, *temp;
    int choice;

    do {
        newNode = (struct node*)malloc(sizeof(struct node));

        if(newNode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL; // important step

        if(head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }

        printf("Enter 1 to continue, 0 to stop: ");
        scanf("%d", &choice);

    } while(choice);

    printf("\nElements of the linked list and their next memory addresses:\n");

    temp = head;
    while(temp != NULL) {
        printf("%d -> %p\t", temp->data, (void*)temp->next);
        temp = temp->next;
    }

    printf("\nHead pointer address: %p\n", (void*)head);
    printf("\nHead pointer address: %d\n", head);

    //Inserting element at the begining;

    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data for new node: ");
    scanf("%d",&newNode->data);

    newNode->next=head;
    head = newNode;


    printf("\nElements of the linked list and their next memory addresses after insert data in beginign:\n");

    temp = head;
    while(temp != NULL) {
        printf("%d -> %p\t", temp->data, (void*)temp->next);
        temp = temp->next;
    }


    return 0;
}

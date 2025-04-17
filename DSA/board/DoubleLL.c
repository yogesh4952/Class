#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct Node
    {
        int data;
        struct Node *prev;
        struct Node *next;
    };

    struct Node *newNode, *head;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data:\n");
    scanf("%d", &newNode->data);
    head = newNode;
    newNode->prev = NULL;
    newNode->next = NULL;

    // For delete

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("%d\n", temp->data);

    return 0;
}
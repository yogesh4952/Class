#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct node {
        int data;
        struct node *next;
    };

    char choice;
    struct node *newNode, *temp, *head;
    head = NULL;

    do {
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("\nEnter data for new Node: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }

        printf("Do you want to add more nodes? (y/n): ");
        scanf(" %c", &choice); // note the space before %c to consume newline

    } while (choice == 'y' || choice == 'Y');

    // Display the linked list
    printf("\nLinked List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

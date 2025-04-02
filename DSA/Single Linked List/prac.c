#include <stdlib.h>
#include <stdio.h>
int main()
{
    struct node
    {
        int data;
        struct node *next;
    };

    struct node *head = NULL, *newnode, *temp;
    char choice;
    do
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            temp = head = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to add more value (y/n):");
        scanf(" %c", &choice);
    } while (choice == 'y');

    temp = head;
    while (temp != 0)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }

    return 0;
}

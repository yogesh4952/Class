#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct Node
    {
        int data;
        struct Node *next;
    };

    struct Node *temp, *newnode, *head;

    newnode = (struct Node *)malloc(sizeof(struct Node));
}
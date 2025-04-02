#include <stdio.h>
#include <stdlib.h>

// Node structure for the stack
struct Node
{
    int data;
    struct Node *next;
};

// Push operation (add to top)
struct Node *push(struct Node *top, int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = top;
    return newnode;
}

// Pop operation (remove from top)
struct Node *pop(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return NULL;
    }
    struct Node *temp = top;
    top = top->next;
    printf("Popped: %d\n", temp->data);
    free(temp);
    return top;
}

// Display stack
void display(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = top;
    printf("Stack: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main()
{
    struct Node *top = NULL;

    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    display(top);

    top = pop(top);
    display(top);

    top = pop(top);
    display(top);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
struct Node
{
    int data;
    struct Node *next;
};

// Enqueue (add to rear)
struct Node *enqueue(struct Node *front, struct Node **rear, int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    if (front == NULL)
    {
    *rear = newnode;
        return newnode;
    }
    (*rear)->next = newnode;
    *rear = newnode;
    return front;
}

// Dequeue (remove from front)
struct Node *dequeue(struct Node *front, struct Node **rear)
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return NULL;
    }
    struct Node *temp = front;
    front = front->next;
    if (front == NULL)
        *rear = NULL; // Queue becomes empty
    printf("Dequeued: %d\n", temp->data);
    free(temp);
    return front;
}

// Display queue
void display(struct Node *front)
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue: ");
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
    struct Node *front = NULL;
    struct Node *rear = NULL;

    front = enqueue(front, &rear, 10);
    front = enqueue(front, &rear, 20);
    front = enqueue(front, &rear, 30);
    display(front);

    front = dequeue(front, &rear);
    display(front);

    front = dequeue(front, &rear);
    display(front);

    return 0;
}
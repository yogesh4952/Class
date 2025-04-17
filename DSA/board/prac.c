
#include <stdio.h>

#define SIZE 100
int rear = -1;
int front = -1;

int queue[SIZE];

void enqueue(int x)
{
    if (rear == SIZE - 1)
    {
        printf("Queue is full!\n");
        return;
    }
    else
    {
        front = 0;
        queue[++rear] = x;
    }
}

void dequeue()
{
    printf("%d is dequeud\n", front);
    front++;
}

void display()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t", queue[i]);
    }
}
int main()
{
    enqueue(4);
    enqueue(42);
    enqueue(544);
    enqueue(566);
    enqueue(55555);

    dequeue();

    display();

    return 0;
}
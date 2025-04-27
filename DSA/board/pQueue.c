#include <stdio.h>
#define SIZE 5
int arr[SIZE];
int top = -1;

int isFull()
{
    return top == SIZE - 1 ? 1 : 0;
}

int isEmpty()
{
    return top == -1 ? 1 : 0;
}
void push(int x)
{
    if (isFull())
    {
        printf("Stack overflow/n");
        return;
    }

    arr[++top] = x;
    // if()
}

void pop()
{
    if (isEmpty())
    {
        printf("Stack underflow\n");
        return;
    }
    top--;
    printf("\n%d is popped from the stack\n", arr[top]);
}

void display()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d\t", arr[i]);
    }
}

int main()
{
    push(50);
    push(70);
    push(60);
    push(1100);
    push(100);
    display();

    pop();
    pop();

    display();
}
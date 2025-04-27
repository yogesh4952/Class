#include <stdio.h>
#define size 5

int arr[size];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if ((rear + 1) % size == front)
    {
        return;
    }
    front = 0;
    rear = (rear + 1) % size;
    arr[front] = x;
}


void dequeu()
{
    if()
}

int main()
{
}
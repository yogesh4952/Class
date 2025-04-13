#include<stdio.h>
#define MAX 100

int queue[MAX];

int front = -1;
int rear = -1;

void enqueue(int x){
    if(rear == MAX -1){
        printf("Overlfow\n");
        return;
    }else{
        front = 0; 
        queue[++rear] = x;
    }
}

void dequeue()
{
    if(rear == -1){
        printf("Underflow");
        return;
    }else{
        printf("%d dequed\n",queue[front]);
        ++front;


    }
}

void display()
{
    for(int i = front; i <=rear ; i++)
    printf("%d\t",queue[i]);
}

int main()
{
    enqueue(51);
    enqueue(25);
    enqueue(1);
    enqueue(545);

    dequeue();
    dequeue();

    display();
    return 0 ;
}
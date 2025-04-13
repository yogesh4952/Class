#include<stdio.h>

#define SIZE 4
int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int x){
    if(rear == SIZE)
    {
        printf("Overflow\n");
        return;
    }else{
        front = 0;
        rear = (rear+1)%SIZE;
    }
    queue[rear]=x;
}

void dequeue()
{
    if(front ==-1)
    {
        printf("Underflow\n");
        return;
    }else{
        printf("%d is dequed\t",queue[front]);
        front = (front + 1 )%SIZE;
    }
}

void display()
{
    for(int i = front;i<=rear;i++)
    {
        printf("%d\t",queue[i]);
    }
}
int main(){

    enqueue(5);
    enqueue(7);
    enqueue(12);
    enqueue(785);

    dequeue();
    dequeue();
    dequeue();
    display();

    enqueue(1);
    enqueue(5);
    enqueue(15);
   
    display();
    return 0;
}
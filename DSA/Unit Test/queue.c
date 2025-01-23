#include<stdio.h>
#include<stdbool.h>
#define MAX 5
int rear = -1;
int front = -1;
int itemCount = 0;
int arr[MAX];

int isEmpty()
{
    return itemCount == 0;
}

int isFull()
{
    return itemCount == MAX ;
}

int enqueue(int data){
    if(!isFull())
    {
        // if(rear == MAX - 1)
        // {
        //     rear -1;
        // }
        arr[++rear] = data;
        
        itemCount++;

        if(front == -1)
        {
            front = 0;
        }
    }
    else{
        return 0;
    }
}



int main()
{
    enqueue(1);
    enqueue(5); 
    enqueue(6);
    enqueue(7);
    enqueue(8);

    printf("%d\n",rear);

    for(int i = 0 ; i < itemCount; i++)
    {
        printf("%d\t",arr[i]);
    }
}
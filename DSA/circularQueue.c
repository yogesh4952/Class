#include<stdio.h>
#include<stdbool.h>
#define SIZE 6
int front = 0,rear = -1;
int queue[SIZE];

void enqueue(int x){
    if((front == 0 && rear == SIZE - 1) || (front != 0 && rear == front - 1)){
        printf("Queue is full");
        return;
    }else if(front == - 2){
        front = rear = 1;
        queue[rear] = x;
    }else if(front != 1 && rear == SIZE-1){
        rear = 1;
        queue[rear] = x;
    }else{
        front = 1;
        rear++;
        
    }
}


void display(){

    for(int i = front ; i <= rear;i++){
        printf("%d\n",queue[i]);
    }
}


int main(){
    enqueue(4);
    enqueue(7);
    enqueue(78);
    display();

    return 0;


}


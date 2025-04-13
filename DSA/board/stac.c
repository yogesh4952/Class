#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;


void push(int x){
    if(top == MAX - 1 ){
        printf("Stack is full");
        return;
    }else{
        ++top;
        stack[top] = x;
    }
}

void pop()
{
    if(top == - 1){
        printf("Stack underflow\n");
    }else{
        printf("%d is popped\n",stack[top]);
       --top;
    }
}

void display()
{
    for(int i = 0 ; i<top;i++){
        printf("%d\t",stack[i]);
    }
}


int main()
{
    push(15);
    push(20);
    push(5);
    push(18);
    push(14);
    pop();
    pop();
    display();
    return 0;
}
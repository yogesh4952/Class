#include<stdio.h>
#define SIZE 5
int stack[SIZE];
int top = -1;

void push(int x){
    if(top == SIZE -1){
        printf("Stack Overflow\n");
    }else{
        top++;
        stack[top]=x;
        printf("%d pushed to stack\n",x);
    }
}
int main(){
    push(40);
    push(2);
    push(1);
    push(50);
    return 0;
}
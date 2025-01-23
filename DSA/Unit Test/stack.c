#include <stdio.h>

#define MAX_SIZE 8 // Define maximum size of stack
int STACK[MAX_SIZE]; // Stack array
int top = -1; // Initialize top

// Check if stack is full
int isFull() {
    return top == MAX_SIZE - 1; // Check if top is at last index
}

// Push operation
void push(int data) {
    if (!isFull()) {
        top = top + 1; // Increment top
        STACK[top] = data; // Add data to stack
    } else {
        printf("Stack is full\n");
    }
}

// Check if stack is empty
int isEmpty() {
    return top == -1; // Return 1 if empty, otherwise 0
}

// Peek operation
int peek() {
    if (!isEmpty()) { // Call isEmpty() with parentheses
        return STACK[top]; // Return top element
    }
    return -1; // Return an error code (e.g., -1) if empty
}


void pop()
{
    if(!isEmpty())
    {
        printf("Popped elements is %d\n",STACK[top]);
        top = top-1;
    }
    else{
        printf("The stack is empty\n");
    }

}


int main() {
    push(5);
    push(14);
    push(17);
    push(89);
    push(789);
    pop();

    int lastElement = peek();
    if (lastElement != -1) { // Check if peek returned a valid element
        printf("%d is the top element\n", lastElement);
    } else {
        printf("Stack is empty, no top element\n");
    }

    // Print all elements in the stack up to top index
    for (int i = 0; i <= top; i++) {
        printf("%d\n", STACK[i]);
    }

    return 0;
}

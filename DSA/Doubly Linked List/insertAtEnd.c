#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev, *next;
};
struct node *head = NULL;
struct node *tail = NULL;


void createNode(int x){
    struct node *newNode;

    newNode =  (struct node*)malloc(sizeof(struct node));;
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = tail = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

}

void display()
{
    struct node *temp = head;

    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtBeg(int x)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    } else {
        tail = newNode; // If list was empty
    }

    head = newNode;

}

void insertAtEnd(int x)
{
    struct node *newNode;
    newNode  = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->prev = tail;

    tail->next = newNode;

    if(tail!=NULL)
    {
        tail->next = newNode;
    }else{
        head = newNode;
    }
    tail = newNode;

}


int main()
{
    createNode(5);
    createNode(15);
    createNode(0);
    createNode(28);



    printf("Linked List elements are: \n");
    display();

    insertAtBeg(147);
    printf("After inserting in beginning  List elements are: \n");
    display();

    insertAtEnd(250);
    printf("After inserting in end  List elements are: \n");
    display();
    
    return 0;
}
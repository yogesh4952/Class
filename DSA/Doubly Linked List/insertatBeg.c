#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev, *next;
};
struct node *head = NULL;


void createNode(int x){
    struct node *newNode,*temp;

    newNode =  (struct node*)malloc(sizeof(struct node));;
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = temp = newNode;
    }else{
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }

}

void display()
{
    struct node *temp;
    temp = head;

    while(temp!=0)
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
    newNode->next = head;
    newNode->data = x;
    newNode->prev = NULL;
    head = newNode;

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
    printf("After inserting  List elements are: \n");
    display();
    
    return 0;
}
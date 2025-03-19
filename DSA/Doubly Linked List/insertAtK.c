#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;
struct node *tail = NULL;
static int count = 0;

void creatLinkedList(int x)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    count++;
    newNode->data = x;
    newNode->prev = NULL; 
    newNode->next = NULL;

    if(head == NULL)
    {
        head = tail =  newNode;
    }else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }
}

void insertAtBeg(int x)
{
    struct node *newNode;
    newNode =  (struct node*)malloc(sizeof(struct node));
    count++;
    newNode->data = x;
    newNode->next = head;
    newNode->prev = NULL;
    if(head!=NULL){
        head->prev = newNode;
    }else{
        tail = newNode;
    }
    
    head = newNode;

}


void insertAtK(int data,int position){
    if(position<count)
    {
        struct node *temp;
        int i = 1;
        temp = head;
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;

        while(i<(position-1))
        {
            temp=temp->next;
            i++;
        }
     
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
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

int main()
{

    creatLinkedList(5);
    creatLinkedList(15);
    creatLinkedList(20);
    creatLinkedList(525);
    creatLinkedList(30);

    display();
    insertAtBeg(30);
    printf("Insert at beginning\n");
    display();

    int x = 3;
    insertAtK(245,x);
    printf("Insert at %d\n",x);
    display();

}
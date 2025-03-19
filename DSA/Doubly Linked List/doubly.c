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
int main()
{

    // struct node *newNode,*temp;
    // int choice;

    // do{
    //     newNode = (struct node*)malloc(sizeof(struct node));
    //     printf("Enter data:\n");
    //     scanf("%d",&newNode->data);
    //     newNode->prev = NULL;
    //     newNode->next = NULL;

    //     if(head == NULL){
    //        temp =  head = newNode;
    //     }else{

    //         temp->next = newNode;
    //         newNode->prev = temp;
    //         temp = newNode;
    //     }

    //     printf("1 for continue 0 for stop: \n");
    //     scanf("%d",&choice);
    // }while(choice);



    // temp = head;
    // while(temp != NULL){
    //     printf("%d",temp->data);
    //     temp = temp->next;

    // }
    // printf("\n");

    createNode(5);
    createNode(15);
    createNode(0);
    createNode(28);

    printf("Linked List elements are: \n");
    display();
    
    return 0;
}
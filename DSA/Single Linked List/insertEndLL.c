#include<stdio.h>
#include<stdlib.h>
int main()
{
    struct node{
        int data;
        struct node *next;
    };

    struct node *temp,*head,*newNode;
    head = 0 ;
    int choice;
    do{
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newNode->data);
        newNode->next =NULL;

        if(head==0)
        {
            temp = head =newNode;
        }else{
            temp->next=  newNode;
            temp = newNode;
        }
        printf("Enter choice: ");
        scanf("%d",&choice);

    }while(choice);


    temp = head;
    printf("Element of linkedList:\n");
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp = temp ->next;

    }


    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d",&newNode->data);
    newNode->next = 0;
    temp = head;

    while(temp->next != 0){
        temp = temp->next;
        
    }
    temp->next = newNode;
    
    temp = head;
    printf("Element of linkedList:\n");
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp = temp ->next;

    }

}


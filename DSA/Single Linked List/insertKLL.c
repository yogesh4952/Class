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
    int count =0;
    do{
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newNode->data);
        count++;
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


    int i = 1;
    int pos;
    printf("Enter position: ");
    scanf("%d",&pos);
    if(pos>count)
    {
        printf("Invalid position\n");
        return 0;
    }else{
        temp = head;
        while(i<pos)
        {
            temp = temp->next;
            i++;
        }

        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter new Data: ");
        scanf("%d",&newNode->data);

        newNode->next = temp->next;
        temp->next = newNode;

        temp = head;
        printf("Element of linkedList:\n");
        while(temp!=0)
        {
            printf("%d\t",temp->data);
            temp = temp ->next;
    
        }
    
    }
}


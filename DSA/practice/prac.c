#include<stdio.h>
#include<stdlib.h>
int main()
{
    struct node {
        int data;
        struct node *next;
    };


    struct node *temp,*newnode,*head;

    head = 0;
    int choice;

    do{
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: \n");
        scanf("%d",&newnode->data);

        if(head == 0){
            temp = head=  newnode;
        }else{
            temp->next = newnode;
            temp =  newnode;
        }

        printf("Enter choice: \n");
        scanf("%d",&choice);
    }while(choice);


    temp = head;

    while(temp!=0)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }

    printf("\n");
    return 0;
}
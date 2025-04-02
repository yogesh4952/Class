#include <stdio.h>
#include <stdlib.h>

// Node Structures
typedef struct SNode
{
    int data;
    struct SNode *next;
} SNode;
typedef struct DNode
{
    int data;
    struct DNode *prev, *next;
} DNode;
typedef struct CNode
{
    int data;
    struct CNode *next;
} CNode;

// Singly Linked List Functions
SNode *sInsert(SNode *head, int data)
{
    SNode *newnode = malloc(sizeof(SNode));
    newnode->data = data;
    newnode->next = head;
    return newnode;
}
SNode *sDelete(SNode *head)
{
    if (!head)
        return NULL;
    SNode *temp = head;
    head = head->next;
    free(temp);
    return head;
}
void sDisplay(SNode *head)
{
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Doubly Linked List Functions
DNode *dInsert(DNode *head, int data)
{
    DNode *newnode = malloc(sizeof(DNode));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = head;
    if (head)
        head->prev = newnode;
    return newnode;
}
DNode *dDelete(DNode *head)
{
    if (!head)
        return NULL;
    DNode *temp = head;
    head = head->next;
    if (head)
        head->prev = NULL;
    free(temp);
    return head;
}
void dDisplay(DNode *head)
{
    while (head)
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Circular Linked List Functions
CNode *cInsert(CNode *head, int data)
{
    CNode *newnode = malloc(sizeof(CNode));
    newnode->data = data;
    if (!head)
    {
        newnode->next = newnode;
        return newnode;
    }
    newnode->next = head->next;
    head->next = newnode;
    return head;
}
CNode *cDelete(CNode *head)
{
    if (!head)
        return NULL;
    if (head->next == head)
    {
        free(head);
        return NULL;
    }
    CNode *temp = head->next;
    head->next = temp->next;
    free(temp);
    return head;
}
void cDisplay(CNode *head)
{
    if (!head)
    {
        printf("Empty\n");
        return;
    }
    CNode *temp = head->next;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head->next);
    printf("(head)\n");
}

// Main Function
int main()
{
    SNode *sHead = NULL;
    DNode *dHead = NULL;
    CNode *cHead = NULL;
    sHead = sInsert(sHead, 1);
    sHead = sInsert(sHead, 2);
    printf("Singly: ");
    sDisplay(sHead);
    sHead = sDelete(sHead);
    printf("After Delete: ");
    sDisplay(sHead);

    dHead = dInsert(dHead, 3);
    dHead = dInsert(dHead, 4);
    printf("Doubly: ");
    dDisplay(dHead);
    dHead = dDelete(dHead);
    printf("After Delete: ");
    dDisplay(dHead);

    cHead = cInsert(cHead, 5);
    cHead = cInsert(cHead, 6);
    printf("Circular: ");
    cDisplay(cHead);
    cHead = cDelete(cHead);
    printf("After Delete: ");
    cDisplay(cHead);

    return 0;
}

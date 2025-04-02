#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next, *prev;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insertFront(Node **head, int data, int type)
{
    Node *newNode = createNode(data);
    if (!*head)
    {
        *head = newNode;
        if (type == 3)
            newNode->next = newNode; // Circular list
        return;
    }
    if (type == 1)
    { // Singly
        newNode->next = *head;
        *head = newNode;
    }
    else if (type == 2)
    { // Doubly
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    else if (type == 3)
    { // Circular
        Node *temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

void deleteNode(Node **head, int key, int type)
{
    if (!*head)
        return;
    Node *curr = *head, *prev = NULL;
    if (type == 3 && (*head)->data == key)
    { // Circular
        Node *temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        if (temp == *head)
        {
            free(*head);
            *head = NULL;
            return;
        }
        temp->next = (*head)->next;
        free(*head);
        *head = temp->next;
        return;
    }
    while (curr && curr->data != key)
    {
        prev = curr;
        curr = curr->next;
        if (type == 3 && curr == *head)
            return;
    }
    if (!curr)
        return;
    if (prev)
        prev->next = curr->next;
    else
        *head = curr->next;
    if (type == 2 && curr->next)
        curr->next->prev = prev;
    free(curr);
}

void display(Node *head, int type)
{
    if (!head)
    {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp && (type != 3 || temp != head));
    printf(type == 3 ? "HEAD\n" : "NULL\n");
}

int main()
{
    Node *head = NULL;
    int type;
    printf("Enter type (1-Singly, 2-Doubly, 3-Circular): ");
    scanf("%d", &type);

    insertFront(&head, 3, type);
    insertFront(&head, 2, type);
    insertFront(&head, 1, type);
    display(head, type);

    deleteNode(&head, 2, type);
    display(head, type);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void printList(Node *head)
{
    Node *current = head;
    printf("NULL <- ");
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
        {
            printf(" <-> ");
        }
        else
        {
            printf(" -> NULL\n");
        }
        current = current->next;
    }
}
int lengthList(Node *head)
{
    Node *current = head;
    int length = 0;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}
void phanTuGiua(Node *head)
{
    int length = lengthList(head);
    int mid = length / 2;
    Node *current = head;
    int count = 0;

    for(int i = 0 ; i< mid; i++){
        count++;
        current = current->next;
    }
    if(length%2==0){
        count++;
        current= current->next;
    }
    printf("Node %d: %d",count, current->data);
}
int main()
{
    Node *head = createNode(10);
    Node *node2 = createNode(20);
    Node *node3 = createNode(30);
    Node *node4 = createNode(40);
    Node *node5 = createNode(50);
    Node *node6 = createNode(60);
    head->next = node2;
    node2->prev = head;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;
    node4->prev = node3;

    node4->next = node5;
    node5->prev = node4;

    node5->next = node6;
    node6->prev = node5;

    printList(head);
    phanTuGiua(head);
    return 0;
}
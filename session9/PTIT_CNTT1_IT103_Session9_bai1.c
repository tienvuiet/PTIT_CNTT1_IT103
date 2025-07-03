#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
// in toan bo thong tin cua node
void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL");
}
int main()
{
    Node *head = createNode(10);
    Node *node2 = createNode(20);
    Node *node3 = createNode(30);
    Node *node4 = createNode(40);
    Node *node5 = createNode(50);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    printList(head);
    return 0;
}
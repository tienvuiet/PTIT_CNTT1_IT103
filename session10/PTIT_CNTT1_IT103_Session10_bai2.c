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
void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("data:%d \n", current->data);
        current=current->next;
    }
    printf("NULL");

}
int main()
{
    Node* head = createNode(10);
    Node* node2 = createNode(20);
    head->next = node2;
    printf("danh sach lien ket: \n");
    printList(head);
    return 0 ;
}
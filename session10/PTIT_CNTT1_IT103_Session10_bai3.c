#include <stdio.h>
#include <stdlib.h>
typedef struct Note
{
    int data;
    struct Note *next;
} Node;
Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void printList(Node*head){
    Node* current = head;
    while(current->next!=NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
Node *insertEnd(Node *head, int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
    {
        return head;
    }
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return head;
}
int main()
{
    Node *head = createNode(10);
    Node *node2 = createNode(20);
    Node *node3 = createNode(30);
    head->next = node2;
    node2->next = node3;
    printf("before: ");
    printList(head);
    int data;
    printf("nhap vao gia tri muon them: ");
    scanf("%d", &data);
    printf("aftr: ");
    head = insertEnd(head, data);
    printList(head);
    return 0 ;
}
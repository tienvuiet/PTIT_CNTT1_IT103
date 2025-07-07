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
int lengthList(Node *head)
{
    Node *current = head;
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
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
Node *deleteOne(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
    return head;
}
Node *deleteEnd(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
    return 0;
}
Node *deleteAt(Node *head, int index)
{

    if (index < 0 || index > lengthList(head))
    {
        printf("index ko hop le");
        return head;
    }
    if (index == 0)
    {
        return deleteOne(head);
    }
    if (index == lengthList(head))
    {
        return deleteEnd(head);
    }
    Node *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    Node *prev = current->prev;
    Node *next = current->next;
    prev->next = next;
    next->prev = prev;
    free(current);
    return head;
}
int indexAllNode(Node *head, int x)
{
    Node *current = head;
    int index = 0;
    while (current != NULL)
    {
        if (current->data == x)
        {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}
Node* deleteAllValue(Node* head, int x){
    int index = indexAllNode(head, x);
    while (index!= -1)
    {
        head = deleteAt(head, index);
        index = indexAllNode(head,x );
    }
    return head;
}
int main()
{
    Node *head = createNode(10);
    Node *node2 = createNode(20);
    Node *node3 = createNode(30);
    Node *node4 = createNode(30);
    Node *node5 = createNode(50);
    head->next = node2;
    node2->prev = head;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;
    node4->prev = node3;

    node4->next = node5;
    node5->prev = node4;

    int length = lengthList(head);
    printf("%d", length);
    printList(head);
    
    int data;
    printf("nhap gia tri muon xoa: ");
    scanf("%d", &data);
    head = deleteAllValue(head, data);
    printList(head);
    return 0;

}
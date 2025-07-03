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
// tao ham lay ra do dai cua danh sach
int  getLength(Node* head){
    Node* current = head;
    int length = 0;

    while(current!=NULL){
        length++;
        current = current->next;
    }
    return length;
}
//in ra toan bo thong tin cua danh sach
void printList(Node* head){
    Node* current = head;
    while(current!=NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main(){
    Node* head = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);
    Node* node4 = createNode(40);
    Node* node5 = createNode(50);
    head->next = node2;
    node2->next = node3;
    node3->next= node4;
    node4->next = node5;
    printf("danh sach lien ket:\n ");
    printList(head);
    return 0;
}
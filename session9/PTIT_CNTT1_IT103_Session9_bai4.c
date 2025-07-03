#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;
Node* createNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
int getLength(Node* head){
    Node* current = head;
    int length = 0 ;
    while(current!=NULL){
        length++;
        current= current->next;
    }
    return length;
}
int main (){
    Node* head = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);

    head->next = node2;
    node2->next =node3;
    int length= getLength(head);
    printf("danh sach lien ket co %d phan tu", length);
    return 0;
}
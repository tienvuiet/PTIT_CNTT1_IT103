#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;

}Node;
Node *createNode(int data){
    Node* node = (Node*)malloc(sizeof(node));
    node->data= data;
    node->next = NULL;
    return node;
}
Node* insertHead(Node* head, int data){
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}
void printList(Node* head){
    Node* current = head;
    while(current!=NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL");
}
int main (){
    Node* head = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    printf("before:\n");
    printList(head);
    int value;
    printf("\nnhap vao gia tri muon chen vao dau ds: ");
    scanf("%d", &value);
    
    head= insertHead(head, value);
    printf("after:\n ");
    printList(head);
    return 0 ;

}

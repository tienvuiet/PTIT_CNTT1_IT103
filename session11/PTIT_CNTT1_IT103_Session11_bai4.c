#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode ->next = NULL;
    newNode ->prev = NULL;
    return newNode;
}
void printList(Node* head){
    Node* current = head;
    printf("NULL <- ");
    while(current!= NULL){
        printf("%d", current->data);
        if(current->next!= NULL){
            printf(" <-> ");

        }else{
            printf(" -> NULL\n");
        }
        current = current->next;
    }
}
int lengthList(Node* head){
    Node* current = head;
    int count = 0 ;
    while(current!=NULL){
        count++;
        current = current->next;
    }
    return count;
}
int main() {
    Node* head = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);
    
    head->next = node2;
    node2->prev = head;
    node2-> next = node3;
    node3-> prev = node2;
    printList(head);
    int result = lengthList(head);
    printf("danh sach lien ket co %d phan tu", result);
    return 0 ;
}
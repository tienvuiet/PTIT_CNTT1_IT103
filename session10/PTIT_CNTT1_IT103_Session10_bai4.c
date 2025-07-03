#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* createNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node ->data=data;
    node ->next =NULL;
    return node;
}
void printList(Node* head){
    Node* current = head;
    while(current->next!=NULL){
        printf("%d -> ", current->data);
        current=current->next;
    }
    printf("NULL\n");
}
Node* removeEnd(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* current  = head;
    while(current->next->next!=NULL){
        current= current->next;
    }
    Node* removeNode = current->next;
    current->next = NULL;
    free(removeNode);
    return head;

}
int main(){
   Node* head = createNode(10);
   Node* node2 = createNode(20);
   Node* node3 = createNode(30);
   head->next = node2;
   node2->next= node3;
   printf("before: ");
   printList(head);
   printf("after: ");
   removeEnd(head);
   printList(head);
   return 0;
}
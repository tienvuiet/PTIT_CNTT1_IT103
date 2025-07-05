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
    Node *newnNode = (Node *)malloc(sizeof(Node));
    newnNode->data = data;
    newnNode->next = NULL;
    newnNode->prev = NULL;
    return newnNode;
}
void printNode(Node* head){
    Node* current = head;
    printf("NULL <- ");
    while(current!= NULL){
        printf("%d", current->data);
        if(current->next!=NULL){
            printf(" <-> ");
        }else{
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
Node *deleteOne(Node *head)
{
    if (head==NULL){
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    return head;
}
Node* deleteEnd(Node* head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        free(head);
        return NULL;
    }
    Node* current = head;
    while(current->next!= NULL){
        current= current->next;
    }
    current->prev->next=NULL;
    free(current);
    return head;

}
Node* deleteAt(Node* head, int index){
    if(index<0 || index> lengthList(head)){
        printf("index ko hop le");
        return head;
    }
    if(index ==0){
        return deleteOne(head);
    }
    if(index == lengthList(head)){
        return deleteEnd(head);
    }
    Node* current = head;
    for(int i = 0 ; i< index; i++){
        current = current->next;
    }
    Node* nextNode = current->next;
    Node* temp = current;
    Node* prevNode = current->prev;
    prevNode->next= nextNode;
    nextNode->prev= prevNode;
    free(temp);
    return head;


}
int main()
{
    Node *head = createNode(10);
    Node *node2 = createNode(20);
    Node *node3 = createNode(30);

    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;

    printNode(head);
    int index ;
    printf("nhap vi tri index muon xoa: ");
    scanf("%d", &index);
    head = deleteAt(head, index);
    printNode(head);
    return 0;
}
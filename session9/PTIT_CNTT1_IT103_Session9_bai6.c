#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;

}Node;
Node* createNode(int data){
    Node* node = (Node* )malloc(sizeof(Node));
    node->data= data;
    node->next= NULL;
    return node;
}
void printList(Node* head){
    Node* current = head;
    while(current!=NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
Node* removeHead(Node* head){
    //b1: kiem tra danh sach lien ket co rong ko 
    if(head==NULL){
        return NULL;
    }
    //b2: luu tru node dau tien, hien tai vao 1 bien temp
    Node* temp = head;
    
    //b3: di chuyen head sang node ke tiep
    head = head->next;
    //b4: tien hanh xoa node dang duoc luu tri trong temp
    free(temp);
    //b5: tien hanh tra ve node head moi tuong ung voi dslk da
    //duoc xoa bo phan tu dau tien
    return head;

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
    
    head = removeHead(head);

    printf("after:\n ");
    printList(head);
    return 0 ;

}
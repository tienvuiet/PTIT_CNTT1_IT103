#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;

}Node;
Node* createNode(int data){
    Node* node = (Node* )malloc(sizeof(node));
    node->data= data;
    node->next= NULL;
    return node;
}
int  getLength(Node* head){
    Node* current = head;
    int length = 0;

    while(current!=NULL){
        length++;
        current = current->next;
    }
    return length;
}
void printList(Node* head){
    Node* current = head;
    while(current!=NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
//them moi phan tu vao vi tri dau tien danh sach
Node* insertHead(Node* head, int data){
    //b1 too ra node moi chua data
    Node* newNode = createNode(data);
    //b2: tro node moi toi node cu
    newNode->next = head;
    //b3: tra ve node moi vua duoc them vao dau danh sah lien ket
    //de dong vai tro lam danh sach lien ket da duoc them node ms vao dau
    return newNode;
}
//them moi phan tu vao vi tri cuoi cung

Node* insertEnd(Node* head, int data){
    //b1: tao ra 1 node moi chua du lieu data
    Node* newNode = createNode(data);
    //b2: kiem tra xem danh sach rong khong -> tra ve node moi 
    if(head ==NULL){
        return newNode;
    }
    //b3: duyet qua toan bo node co trong danh sach lien ket den node cuoi cung
    Node* current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    //n4: gan next cua node cuoi cung = node moi 
    current->next = newNode;
    return head;
}
Node* insertAt(Node* head, int data, int index){
    if(index< 0||index>getLength(head)){
        printf("index ko hop le");
        return head;
    }
    //2.neu index = 0
    //neu index = length
    if(index == 0 ){
        return insertHead(head, data);
    }
    if(index == getLength(head)){
        return insertEnd(head, data);
    }
    //3. duyet den vi tri can voi vi tri index can chen (index-1)
    Node* current = head;
    for(int i  =0; i< index-1; i++){
        current = current->next;

    }
    //tao ra 1 node moi
    Node* newNode = createNode(data);
    //b5: cap nhat, chen node moi vao giua bang cach cap nhat con tro
    //luu not canh node ke can vao 1 bien
    Node* nextNode = current->next;
    current->next=newNode;
    newNode->next= nextNode;
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
    int value;
    printf("\nnhap vao gia tri muon chen vao dau ds: ");
    scanf("%d", &value);
    int viTri;
    printf("nhap vao vi tri can chen : ");
    scanf("%d", &viTri);
    head= insertAt(head, value, viTri);
    printf("after:\n ");
    printList(head);
    return 0 ;

}
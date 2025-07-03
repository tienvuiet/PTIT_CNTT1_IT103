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

//xoa vi tri dau
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

//xoa vi tri cuoi
Node* removeLast(Node* head){
    //b1: kt xem danh sach lien ket co rong ko 
    if(head == NULL){
        return NULL;
    }
    
    //b2: duyet den node ke cuoi
    Node* current = head;
    while(current->next->next!=NULL){
        current = current->next;
    }
    //while-current
    //b3: lay ra thong tin node cuoi cung thong qua node ke cuoi
    Node* removeNode = current->next;
    //luu vao bien tạm (temp)
    //b4: ngat ket noi node ke cuoi va node cuoi
    current->next = NULL;
    //b5: giai phong, xoa node cuoi(temp)
    free(removeNode);

    //b6: tra ve danh sach lien ket moi
    return head;
}
//xoa di phan tu tai vi tri bat ki 
Node* removeAt(Node* head, int index){
    //b1: kiem tra xem gia tri index co hop le khong 
    //0 -> lenght --> khong hop le return head thong bao loi
    if(index<0 || index> getLength(head)){
        printf("index is not valid");
        return head;
    }
    //b2: neu index = 0
    if(index == 0) return removeHead(head);
    //b3: index = length - 1;
    if(index == getLength(head)-1) {
        return removeLast(head);
    }
    //b4: duyet den not ke can voi node can xoa
    Node* current = head;
    for(int i = 0 ; i< index -1; i++){
        current= current->next;
    }
    //b5: lay thong tin cua node can xoa (thong qua node ke can) va luu node do vao 1 bien tam
    Node* removeNode = current->next;
    Node* next = removeNode->next;
    //b6: ngat ket noi cua node ke can den node can xoa
    //b7: tra lai vi tri cua node ke can do -> node dang sau node can xoa
    current->next = next;
    //n8: ngat 
    free(removeNode);
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
    int viTri;
    printf("nhap vao vi tri can xoa : ");
    scanf("%d", &viTri);
    head = removeAt(head, viTri);
    printf("after:\n ");
    printList(head);
    return 0 ;

}
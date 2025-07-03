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
//tra ve con tro vi tra ve dia chi cua cai node
// tao ham lay ra do dai cua danh s ach
int  getLength(Node* head){
    Node* current = head;
    int length = 0;

    while(current!=NULL){
        length++;
        current = current->next;
    }
    return length;
}

Node *getOne(Node *head, int index)
{
    //b1: kiem tra xem index co hop le khong 
    if(index< 0 || index> getLength(head)){
        printf("index nho hon 0 \n");
        return NULL;
    }
    // b2:tu head -->lay ranode tai vi tri index
    //-tao ra 1 bien goi la current - luu tru thong tin cua 1 node dau tien , lien tuc di chuyen note dau tien den note tiep theo cho den khi bang node index

    Node *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current;
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
    //1.kiem tra xem index có  hop le khong
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
    //lay cai gia tri dang sau remove
    Node* next = removeNode->next;
    //b6: ngat ket noi cua node ke can den node can xoa
    
    //b7: tra lai vi tri cua node ke can do -> node dang sau node can xoa
    current->next = next;
    //n8: ngat 
    free(removeNode);
    return head;
}
int main()
{
    Node *head = createNode(10);
    Node *node2 = createNode(20);
    Node *node3 = createNode(30);
    Node *node4 = createNode(40);
    Node *node5 = createNode(70);
    Node *node6 = createNode(90);
    // head->node2
    head->next = node2;

    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    // int thog tin node dang duoc current tro toi
 
    Node* findNote = getOne(head, 4);

    printf("%d\n", node5->data);
    printf("%d\n", findNote->data);
    //in thong tin toan bo node co trong danh sach lien ket
    printList(head);
    //lay ra do dai cua danh sach lien ket don 
    int length = getLength(head);
    printf("leghth: %d\n", length);
    
    //them moi 1 node vao trong danh sach lien ket kead
    head =  insertHead(head, 99);
    //them moi 1 node vao danh sach o vi tri cuoi cung
    head = insertEnd(head, 39);
    printList(head);

    head =  insertAt(head, 199, 3);
    printList(head);

    head = removeHead(head);
    printList(head);
    head = removeLast(head);
    printList(head);

    head = removeAt(head, 2);
    printList(head);
    return 0;
}

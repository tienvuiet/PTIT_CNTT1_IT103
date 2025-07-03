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
void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL");
}
int getLength(Node *head)
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
Node* deleteStart(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* temp = head;
    head= head->next;
    free(temp);
    return head;


}
Node* deleteEnd(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    Node* removeNode = current->next;
    current->next=NULL;
    free(removeNode);
    return head;
}
int indexNode(Node* head, int x){
    Node* current = head;
    int index = 0;

    while(current!=NULL){
        if(current->data==x){
            return index;
        }
        current= current->next;
        index++;
    }
    return -1;
}
Node* deleteAt(Node* head, int index){
    if(index<0||index> getLength(head)){
        printf("index ko hop le");
        return head;
    }
    if(index == 0){
        return deleteStart(head);
    }
    if(index == getLength(head)-1){
        return deleteEnd(head);
    }
    Node* current = head;
    for(int i = 0 ; i< index-1; i++){
        current = current->next;
    }
    Node* removeNode = current->next;
    Node* next = removeNode->next;
    current->next = next;
    free(removeNode);
    return head;
}

Node* removeAllByValue(Node* head, int x){
    int index = indexNode(head,x);
    while(index!= -1){
        head = deleteAt(head, index);
        index = indexNode(head, x);

    }
    return head;

}
int main()
{
    Node *head = createNode(1);
    Node *note2 = createNode(2);
    Node *note3 = createNode(3);
    Node *note4 = createNode(3);
    head->next = note2;
    note2->next = note3;
    note3->next = note4;
    printList(head);
    int x;
    printf("nhap vao gia tri muon xoa");
    scanf("%d", &x);
    head = removeAllByValue(head, x);
    printList(head);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;

}Node;
typedef struct{
    Node *top;
}Stack;
void initStack(Stack *s){
    s->top=NULL;
}
void push (Stack *s, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}
int main (){
    Stack s;
    initStack(&s);
    
    int val;
    printf("nhap vao gia tri list danh sach: ");
    scanf("%d", &val);
    push(&s, val);
    return 0;
}
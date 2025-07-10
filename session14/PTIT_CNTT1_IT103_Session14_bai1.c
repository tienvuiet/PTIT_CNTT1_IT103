#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;
typedef struct{
    Node *top;
}Stack;
void initStack(Stack* s){
    s->top=NULL;
}

int main (){
    Stack s;
    initStack(&s);
    return 0;
}
#include<stdio.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
typedef struct Stack{
    Node* head;
}Stack;
Stack *createStack(Stack* stack){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    
}
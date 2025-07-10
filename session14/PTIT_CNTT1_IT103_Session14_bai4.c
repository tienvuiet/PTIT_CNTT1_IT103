#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

void initStack(Stack *s)
{
    s->top = NULL;
}
int isEmpty(Stack *stack)
{
    if (stack->top ==NULL){
        return 1;
    }
    return 0;
}
void push(Stack *s, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}
int pop(Stack *s){
    if(isEmpty(s)){
        return -1;
    }
    Node * temp = s->top;
    int value = temp->data;
    s->top = temp->next;
    free(temp);
    return value;
}
int peek(Stack *s){
    if(isEmpty(s)){
        return -1;
    }
    return s->top->data;
}
void printStack(Stack *s)
{
    Node *temp = s->top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(void)
{
    Stack s;
    initStack(&s);
    printf("check rong: %d\n", pop(&s));
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printStack(&s);
    printf("lay ra phan tu o dinh: %d\n", peek(&s));
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct {
    Node *top;
}Stack;

void initStack(Stack *s) {
    s->top = NULL;
}

void push(Stack *s, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

void printStack(Stack *s) {
    Node *temp = s->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(void) {
    Stack s;
    initStack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printStack(&s);
    return 0;
}
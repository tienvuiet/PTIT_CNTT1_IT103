#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;

}Node;
Node *createNode(int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
typedef struct Queue{
    Node *front;
    Node *rear;
}Queue;
Queue *createQueue(){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}
int main (){
    
}
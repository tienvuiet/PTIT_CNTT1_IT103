#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node *createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
typedef struct Queue{
    Node *front;
    Node *rear;

}Queue;
Queue *createQueue(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
void enQueue(Queue *queue, int data){
    Node *newNode = createNode(data);
    if(queue->front == NULL){
        queue->front = queue->rear = newNode;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}
void dislayQueue(Queue *queue){
    Node *temp  = queue->front;
    printf("phan tu dau la: %d", temp->data);

}
int main (){
    Queue *queue = createQueue();
    enQueue(queue, 1);
    enQueue(queue, 5);
    dislayQueue(queue);
    
    return 0;
}
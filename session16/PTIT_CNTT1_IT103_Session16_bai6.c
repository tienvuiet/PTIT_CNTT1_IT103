#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;
Node* createNode(int data){
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
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}
void enQueue(Queue *queue, int data){
    Node* newNode = createNode(data);
    if(newNode==NULL){
        printf("Queue is full");
        return ;
    }
    if(queue->front == NULL){
        queue->front = queue->rear = newNode;
        return ;

    }
    queue->rear->next = newNode;
    queue->rear = newNode;


}
void displayQueue(Queue *queue){
    if (queue->front == NULL)
    {
       printf("queue is empty");
       return ;
    }
    Node *temp = queue->front;
    while (temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp ->next;
    }
    
}
int main (){
    Queue *queue = createQueue();
    enQueue(queue, 1);
    enQueue(queue, 2);
    displayQueue(queue);
    return 0;
}
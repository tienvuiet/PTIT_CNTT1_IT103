#include<stdio.h>
#include<stdlib.h>
typedef struct Queue{
    int *arr;
    int front ;
    int rear;
    int cap;
}Queue;
Queue *createQueue(int cap){
    Queue *q =(Queue*)malloc(sizeof(Queue));
    q ->arr = (int *)malloc(sizeof(int)*cap);
    q->front = 0;
    q->rear = -1;
    q->cap = cap;
    return q; 
}

void enQueue(Queue *queue, int value){
    if(queue->rear==queue->cap-1){
        return ;
    }
    queue->rear++;
    queue->arr[queue->rear] = value;
}
void deQueue(Queue *queue){
    if(queue->front>queue->rear){
        printf("hang doi trong");
        return;
    }
    queue->front = queue->front+1;
}
int getFront(Queue *queue){
    if(queue->rear<queue->front){
        printf("queue is rong");
        return -1;
    }
    
    return queue->arr[queue->front];
    deQueue(queue);
}

int main (){
    Queue *queue = createQueue(5);
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    int ketQua = getFront(queue);
    printf("%d", ketQua);
    return 0;
}
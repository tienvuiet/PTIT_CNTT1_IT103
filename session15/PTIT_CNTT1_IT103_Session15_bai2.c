#include<stdio.h>
#include<stdlib.h>
typedef struct Queue{
    int *arr;
    int front;
    int rear;
    int capacity;
}Queue;
Queue *createQueue(int capacity){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->arr = (int *)malloc(sizeof(int )*capacity);
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
    return q;
}
void enQueue(Queue *queue, int value){
    if(queue->rear==queue->capacity-1){
        printf("queue overflow");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = value;
}
int main(){
    Queue* queue = createQueue(5);
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    enQueue(queue, 5);
    return 0;
}
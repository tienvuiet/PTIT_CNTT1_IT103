#include<stdio.h>
#include<stdlib.h>
typedef struct Queue{
   int *arr;
   int front;
   int rear;
   int cap;
}Queue;
Queue *createQueue(int cap){
    Queue * q = (Queue*)malloc(sizeof(Queue));
    q->arr = (int *)malloc(sizeof(int)* cap);
    q->front = 0;
    q->rear = -1;
    q->cap = cap;
    return q;
}
void enQueue(Queue *queue, int data){
    if(queue->rear == queue->cap-1){
        return ;
    }
    queue->rear++;
    queue->arr[queue->rear]=data;
}
void kiemTraRong(Queue *queue){
    if(queue->front>queue->rear){
        printf("true\n");
        return;
    }
    printf("false\n");

}
int main (){
    Queue *queue = createQueue(5);
    kiemTraRong(queue);
    enQueue(queue, 1);
    kiemTraRong(queue);
    return 0;
}
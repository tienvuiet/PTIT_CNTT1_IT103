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
    q->arr = (int *)malloc(sizeof(int)*capacity);
    q->front= 0;
    q->rear = -1;
    q->capacity = capacity;
    return q;
}
int main (){
    return 0;
}
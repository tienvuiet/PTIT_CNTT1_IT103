#include <stdio.h>
#include <stdlib.h>
typedef struct Queue
{
    int *arr;
    int front;
    int rear;
    int cap;
} Queue;
Queue *createQueue(int capacity)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->arr = (int *)malloc(sizeof(int) * capacity);
    q->front = 0;
    q->rear = -1;
    q->cap = capacity;
    return q;
}
void enQueue(Queue *queue, int val)
{
    if (queue->rear == queue->cap - 1)
    {
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = val;
}
void displayQueue(Queue *queue)
{
    if (queue->front > queue->rear)
    {
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->arr[i]);
    }
}
int main()
{
    Queue *queue = createQueue(5);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 24);
    enQueue(queue, 26);
    enQueue(queue, 6);
    displayQueue(queue);
    return 0;
}
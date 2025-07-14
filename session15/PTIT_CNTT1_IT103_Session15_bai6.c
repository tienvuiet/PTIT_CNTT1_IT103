#include <stdio.h>
#include <stdlib.h>
typedef struct Queue
{
    int *arr;
    int front;
    int rear;
    int cap;
} Queue;
Queue *createQueue(int cap)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->arr = (int *)malloc(sizeof(int) * cap);
    q->front = 0;
    q->rear = -1;
    q->cap = cap;
    return q;
}
void enQueue(Queue *queue, int val)
{
    if (queue->front == queue->cap - 1)
    {
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = val;
}

void displayQueue(Queue *queue)
{
    if (queue->rear < queue->front)
    {
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->arr[i]);
    }
}
int dayLienTuc(Queue *queue)
{
    for (int i = queue->front + 1; i <= queue->rear; i++)
    {
        if (queue->arr[i] - queue->arr[i - 1] != 1)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    scanf("%d", &n);
    Queue *queue = createQueue(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        scanf("%d", &m);
        enQueue(queue, m);
    }
    printf("hang doi vua nhap: \n");
    displayQueue(queue);
    if (dayLienTuc(queue))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    return 0;
}
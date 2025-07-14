#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
// xay dung cau truc queue
typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;
// xay dung khoi tao hang doi
Queue *createQueue()
{
    // cap phat bo nho
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    // gan cac gia tri
    queue->front = queue->rear = NULL;
    return queue;
}

// them ptu vao hang doi
void enQueue(Queue *queue, int data)
{
    // b1 khoi tao node va kt bo nho
    Node *newNode = createNode(data);
    if (newNode == NULL)
    {
        printf("Queue is full");
        return;
    }
    // b2 xu ly hang doi trong( queue->front==NULL)
    if (queue->front == NULL)
    {
        queue->front = queue->rear = newNode;
        return;
    }
    // b3 them node moi vao cuoi danh sach
    queue->rear->next = newNode;
    // b4 cap nhat phan tu cuoi hang doi
    queue->rear = newNode;
}
// xoaphan tu khoi hang doi
void deQueue(Queue *queue)
{
    // b1: xu ly truong hop hang doi trong (queue->front ==null)
    if (queue->front == NULL)
    {
        printf("queue is empty");
        return;
    }
    // b2: luu lai node dau hang doi hien tai
    Node *temp = queue->front;
    // b3: cap nhat con tro head
    queue->front = queue->front->next;
    // xu ly truong hop hang doi chi co 1 node
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    // b4: giai phong node dau hang cu
    free(temp);
}
// xay dung ham in toan bo hang doi
void displayQueue(Queue *queue)
{
    // b1: xu ly truong hop hang doi trong
    if (queue->front == NULL)
    {
        printf("queue is empty");
        return;
    }
    // b2: duyet
    Node *temp = queue->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    Queue *queue = createQueue();
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    displayQueue(queue);
    deQueue(queue);
deQueue(queue);
deQueue(queue);
     displayQueue(queue);
    return 0;
}
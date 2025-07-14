
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *arr;
    int front;//chi so dau 
    int rear;//chi so cuoi
    int capacity;
} Queue;

Queue *createQueue(int capacity) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q -> arr = (int *)malloc(capacity * sizeof(int));
    q -> front = 0;
    q -> rear = -1;
    q -> capacity = capacity;
    return q;
}

void enQueue(Queue *queue, int value) {
    // B1: Kiem tra hang doi (Mang khong con vi tri de them)
    if (queue -> rear == queue -> capacity - 1) {
        return;
    }
    // B2: Tang chi so rear len
    queue -> rear++;
    // B3: Them gia tri vao vi tri rear
    queue -> arr[queue -> rear] = value;
}

//xay dung ham lay khoi ham doi
void deQueue(Queue* queue){
    //b1: kiem tra hang doi trong
    if(queue->rear<queue->front){
        printf("hang doi trong");
        return ;
    }
    //b2:tang gia tri fornt len
    queue->front= queue->front+1;
}

//ham xem phan tu dau hang doi
int getFront(Queue *queue){
    //b1: kt hang doi trong
    if (queue -> rear == queue -> capacity - 1) {
        printf("Queue is empty");
        return -1;
    }
    //n2: tra ve phan tu co chi so la front
    return queue->arr[queue->rear];

}
//xay dung ham in toan bo hang doi
void displayQueue(Queue *queue){
    //kiem tra hang doi trong
    if(queue->rear<queue->front){
        return ;
    }
    //in cac ptu co chi so tu front den rear
    for(int i = queue->front; i<= queue->rear; i++ ){
        printf("%d ", queue->arr[i]);
    }
}
int main() {

    return 0;
}
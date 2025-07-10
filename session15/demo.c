#include<stdio.h>
// khai bao cau truc hang doi
#define MAX 100
typedef struct
{
    int data[MAX];
    int front; // chi so phan tu dau hang
    int rear;  // chi so phan tu cuoi cung
} Queue;
// khoi tao hang doi
void initQueuye(Queue *q)
{
    q->front = 0; // san sang lay phan tu dau tien neu co

    q->rear = -1; // hang doi chua co phan tu nao
}
// kiem tra hang doi co phan tu hay ko
int isEmpty(Queue *q) { 
    return q->front>q->rear;

}

// kiem tra hang doi da day hay chua
int isFull(Queue* q){
    return q->rear==MAX-1;//1: day con khac 1 thi se co phan tu roi 
}
// them phan tu
void enQueue(Queue* q, int x){
    if(isFull(q)){
        printf("Queue is full\n");
        return ;
    }
    q->rear++;
    q->data[q->rear]=x;
}
// xoa phan tu
int deQueue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;

    }
    int val = q->data[q->front];
    q->front++;
    return val;
}
// xem phan tu dau tien trong hang doi
int frontValue(Queue* q){
    if(isEmpty(q)){
        printf("khong co phan tu");
        return -1;
    }
    return q->data[q->front];
}
// in danh sach cac phan tu trong hang doi
void printQueue(Queue* q){
    if(isEmpty(q)){
        printf("hang doi trong");
        return ;
    }
    for(int i = q->front ; i<= q->rear; i++){
        printf("%d ", q->data[i]);
    }
}
int main (){
    Queue q;
    initQueuye(&q);
    enQueue(&q, 10);
    enQueue(&q, 20);
    enQueue(&q, 30);
    enQueue(&q, 40);
    enQueue(&q, 50);
    printQueue(&q);
}

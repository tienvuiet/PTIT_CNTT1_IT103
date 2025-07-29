#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Request
{
    int id;
    char issue[100];
    int priority;
} Request;
typedef struct Queue
{
    Request *data;
    int front;
    int rear;
    int cap;
} Queue;
Queue *createQueue(int cap)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->cap = cap;
    q->front = 0;
    q->rear = -1;
    q->data = (Request *)malloc(sizeof(Request) * cap);
    return q;
}
int isQueueFull(Queue *queue)
{
    if (queue->rear == queue->cap - 1)
    {
        return 1;
    }
    return 0;
}
int isQueueEmpty(Queue *queue)
{
    if (queue->front > queue->rear)
    {
        return 1;
    }
    return 0;
}
int enQueue(Queue *queue, Request request)
{
    if (isQueueFull(queue))
    {
        return 0;
    }
    queue->rear++;
    queue->data[queue->rear] = request;
    return 1;
}
Request deQueue(Queue *q)
{
    Request empty = {-1, "", -1};
    if (isQueueEmpty(q))
    {
        return empty;
    }
    return q->data[q->front++];
}
Request font(Queue *q)
{
    Request empty = {-1, "", -1};
    if (isQueueEmpty(q))
    {
        return empty;
    }
    return q->data[q->front];
}
void printQueue(Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Khong co yeu cau \n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("ID: %d, Issue: %s, Priority: %s\n", q->data[i].id, q->data[i].issue, q->data[i].priority == 1 ? "cao" : "thap");
    }
}

int main()
{
    int choice, idCount = 1;
    Queue *hightQueue = createQueue(100);
    Queue *lowQueue = createQueue(100);

    do
    {
        printf("1.Gui yeu cau ho tro\n");
        printf("2.Xu ly yeu cau\n");
        printf("3.Xem yeu cau gan nhat can xu ly\n");
        printf("4.Hien thi toan bo yeu cau\n");
        printf("5.Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
        {
            Request re;
            re.id = idCount++;
            printf("Nhap yeu cau: ");
            fgets(re.issue, 100, stdin);
            re.issue[strcspn(re.issue, "\n")] = '\0';
            printf("Nhap muc do uu tien (1: cao, 2: thap): ");
            scanf("%d", &re.priority);
            getchar();
            if (re.priority == 1)
            {
                enQueue(hightQueue, re);
            }
            else
            {
                enQueue(lowQueue, re);
            }
            break;
        }

        case 2:
        {
            Request re;
            if (!isQueueEmpty(hightQueue))
            {
                re = deQueue(hightQueue);
            }
            else
            {
                re = deQueue(lowQueue);
            }
            printf("Da xu ly yeu cau: %d, %s, %s", re.id, re.issue, re.priority == 1 ? "cao" : "thap");
            break;
        }
        case 3:
        {
            Request re;
            if (!isQueueEmpty(hightQueue))
            {
                re = font(hightQueue);
            }
            else
            {
                re = font(lowQueue);
            }
            printf("Yeu cau can xu ly gan nhat: %d, %s", re.id, re.issue);
            break;
        }

        case 4:
            printf("Yeu cau uu tien cao:\n ");
            printQueue(hightQueue);
            printf("Yeu cau uu tien thap: \n");
            printQueue(lowQueue);
            break;
        case 5:
            printf("Da thoat chuong trinh!");
            break;
        default:
            printf("Lua chon khong hop le!");
        }
    } while (choice != 5);
    return 0;
}
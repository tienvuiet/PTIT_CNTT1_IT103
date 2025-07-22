#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Cấu trúc bài hát
typedef struct {
    char name[MAX_LEN];
} Song;

// Stack – Lưu lịch sử các bài hát đã phát
typedef struct {
    Song *data;
    int top;
    int cap;
} Stack;

// Queue – Danh sách phát (không dùng size)
typedef struct {
    Song *data;
    int front, rear, cap;
} Queue;

// ---------- STACK FUNCTIONS ---------- //
Stack* createStack(int cap) {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->cap = cap;
    stack->top = -1;
    stack->data = (Song*) malloc(sizeof(Song) * cap);
    return stack;
}

int isStackFull(Stack *stack) {
    return stack->top == stack->cap - 1;
}

int isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

int push(Stack *stack, Song song) {
    if (isStackFull(stack)) {
        printf("Lich su phat day!\n");
        return 0;
    }
    stack->data[++stack->top] = song;
    return 1;
}

Song pop(Stack *stack) {
    Song empty = {""};
    if (isStackEmpty(stack)) {
        printf("Khong co bai hat truoc do!\n");
        return empty;
    }
    return stack->data[stack->top--];
}

void printHistory(Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Chua co bai hat nao duoc phat.\n");
        return;
    }
    printf("Lich su phat:\n");
    for (int i = 0; i <= stack->top; i++) {
        printf("%s\n", stack->data[i].name);
    }
}

// ---------- QUEUE FUNCTIONS ---------- //
Queue* createQueue(int cap) {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->cap = cap;
    queue->data = (Song*) malloc(sizeof(Song) * cap);
    queue->front = -1;
    queue->rear = 0;  // Theo yêu cầu
    return queue;
}

int isQueueEmpty(Queue *queue) {
    return queue->front == -1;
}

int isQueueFull(Queue *queue) {
    return (!isQueueEmpty(queue) && (queue->rear + 1) % queue->cap == queue->front);
}

int enqueue(Queue *queue, Song song) {
    if (isQueueFull(queue)) {
        printf("Hang doi phat day!\n");
        return 0;
    }
    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->cap;
    }
    queue->data[queue->rear] = song;
    return 1;
}

Song dequeue(Queue *queue) {
    Song empty = {""};
    if (isQueueEmpty(queue)) {
        printf("Khong co bai nao trong hang doi!\n");
        return empty;
    }
    Song song = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = 0;  // Reset rear về 0 khi rỗng
    } else {
        queue->front = (queue->front + 1) % queue->cap;
    }
    return song;
}

// ---------- MAIN PROGRAM ---------- //
int main() {
    Stack *historyStack = createStack(100);
    Queue *nextQueue = createQueue(100);
    Song currentSong = {""};

    int choice;
    do {
        printf("\n——————— MUSIC PLAYER ———————\n");
        printf("1. ADD (Them bai hat vao queue)\n");
        printf("2. PLAY NEXT (Phat bai tiep theo)\n");
        printf("3. PLAY PREVIOUS (Quay lai bai truoc)\n");
        printf("4. HISTORY (Xem lich su phat)\n");
        printf("5. EXIT\n");
        printf("Chon: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1: {
                Song newSong;
                printf("Nhap ten bai hat: ");
                fgets(newSong.name, MAX_LEN, stdin);
                newSong.name[strcspn(newSong.name, "\n")] = '\0';
                if (enqueue(nextQueue, newSong)) {
                    printf("Da them '%s' vao hang doi.\n", newSong.name);
                }
                break;
            }
            case 2: {
                if (!isQueueEmpty(nextQueue)) {
                    if (strlen(currentSong.name) > 0) {
                        push(historyStack, currentSong);
                    }
                    currentSong = dequeue(nextQueue);
                    printf("Dang phat: %s\n", currentSong.name);
                } else {
                    printf("Khong co bai nao trong queue de phat!\n");
                }
                break;
            }
            case 3: {
                if (!isStackEmpty(historyStack)) {
                    if (strlen(currentSong.name) > 0)
                        enqueue(nextQueue, currentSong);
                    currentSong = pop(historyStack);
                    printf("Quay lai dang phat: %s\n", currentSong.name);
                } else {
                    printf("Khong co bai hat truoc do de quay lai!\n");
                }
                break;
            }
            case 4: {
                printHistory(historyStack);
                break;
            }
            case 5:
                printf("Da thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 5);

    // Free memory
    free(historyStack->data);
    free(historyStack);
    free(nextQueue->data);
    free(nextQueue);
    return 0;
}
    
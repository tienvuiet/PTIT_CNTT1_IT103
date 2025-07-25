#include <stdio.h>
#include<stdlib.h>
typedef  struct  Graph {
    int V;//so dinh ben trong do thi
    int **matrix;//mang 2 chieu dai dien cho do th
}Graph;
//xay dung ham khoi tao do thi
Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    //cap phat bo nho cho mang 2 chieu
    graph->matrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        //cap phat bo nho cho tung mang con trong mang 2 chieu
        graph->matrix[i] = (int *)calloc(V ,sizeof(int));
    }
    return graph;
}
//xay dung ham ket noi 2 dinh
void addEdge(Graph *graph,int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}
//in ma tran
void printMatrix(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ",graph->matrix[i][j]);
        }
        printf("\n");
    }
}
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d: ",i);
        for (int j = 0; j < graph->V; j++) {
            if (graph->matrix[i][j] == 1) {
                printf("%d ",j);
            }
        }
        printf("\n");
    }
    //0: 1 3
    //1: 0
    //2:
    //3: 0
}
//duyet dfs
void DFSUtil(Graph *graph, int src, int *visited) {
    //b1:in ra dinh src va danh dau da di qua
    printf("%d ", src);
    visited[src] = 1;
    //b2:kiem tra cac duong co the di tu dinh src
    //su dung vong lap voi tat ca dinh trong do thi
    for (int i = 0; i < graph->V; i++) {
        //b3 neu co duong (matrix[src][i]=1;
        //va dinh tiep theo chua duoc di qua
        if (graph->matrix[src][i] == 1 && visited[i] == 0) {
            //b4: di den tinh tiep theo va thuc hien lai toan bo logic
            DFSUtil(graph, i, visited);
        }

    }
}
void DFS(Graph *graph, int src) {
    int *visited = (int *)calloc(graph->V, sizeof(int));
    printf("bat  dau duyet DFS tu dinh %d: ", src);
    DFSUtil(graph, src, visited);
    printf("\n");
    free(visited);

}






//duyet bfs
typedef struct Queue {
    int *arr;
    int capacity;
    int front;
    int rear;
}Queue;
Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int *)calloc(capacity, sizeof(int));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}
void enqueue(Queue *queue, int vertex) {
    if (queue->rear == queue->capacity - 1) {
        printf("queue is full\n");
        return ;
    }
    queue->rear++;
    queue->arr[queue->rear] = vertex;
}
int isEmpty(Queue *queue) {
    if (queue->front > queue->rear) {
        return 1;
    }
    return 0;
}
int deQueue(Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    return queue->arr[queue->front++];
}
void BFS(Graph *graph, int src) {
    //khoi tao va gan gia tri cho mang visited
    int *visited = (int *)calloc(graph->V, sizeof(int));
    //khoi tao hang doi
    Queue *queue = createQueue(graph->V);
    //int dinh src, dua dinh src vao dau hang doi va danh dau da qua
    enqueue(queue, src);
    visited[src] = 1;
    printf("bat  dau duyet DFS tu dinh %d: ", src);
    //trien khai vong lap den khi hang doi trong
    while (!isEmpty(queue)) {
        int vertex = deQueue(queue);
        //lay dinh o dau hang doi ra
        printf("%d ", vertex);
        //kiem tra toan bo  dg co the di tu dinh
        for (int i = 0; i < graph->V; i++) {
            //neu co dg di va chua tung duoc di qua
            if (graph->matrix[vertex][i] == 1 && visited[i] == 0) {
                //danh dau da di qua va day vao hang doi
                visited[i] = 1;
                enqueue(queue, i);
            }

        }

    }
    printf("\n");
    free(visited);
    free(queue->arr);
    free(queue);
}


int main(void) {
    Graph *graph = createGraph(4);
    addEdge(graph,0,1);
    addEdge(graph,0,3);
    addEdge(graph,0,2);
    addEdge(graph,1,3);
    printGraph(graph);
    printf("Hello, World!\n");
    printMatrix(graph);
    DFS(graph,0);
    BFS(graph,0);
    return 0;
}
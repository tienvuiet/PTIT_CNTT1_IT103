#include<stdio.h>
#include<stdlib.h>
typedef struct Graph {
    int V;
    int **matrix;
}Graph;
Graph *createGraph (int V){
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->matrix = (int**)malloc(V*sizeof(int*));
    for(int i = 0 ; i< V; i++){
        graph->matrix[i]= (int*)calloc(V, sizeof(int));
    }
    return graph;
}
void addEdge(Graph *graph , int src, int dest){
    graph->matrix[src][dest]=1;
    graph->matrix[dest][src]=1;
}
typedef struct Queue{
    int *arr;
    int capacity;
    int front;
    int rear;
}Queue;
Queue *createQueue(int capacity){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->arr = (int*)calloc(capacity, sizeof(int));
    q->capacity= capacity;
    q->front = 0;
    q->rear = -1;
    return q;
}
void enQueue(Queue *queue, int data){
    if (queue->rear== queue->capacity-1)
    {
        return ;
    }
    queue->rear++;
    queue->arr[queue->rear]= data;
}
int isEmpty(Queue *queue){
    if (queue->front > queue->rear)
    {
        return 1;
    }
    return 0;
}
int deQueue(Queue *queue){
    if(isEmpty(queue)){
        return -1;
    }
    return queue->arr[queue->front++];
}
void BFS(Graph *graph, int src){
    int *visitted = (int*)calloc(graph->V, sizeof(int));
    Queue *queue = createQueue(graph->V);
    enQueue(queue, src);
    visitted[src]=1;
    printf("bat dau duyet BFS tu dinh %d: ", src);
    while(!isEmpty(queue)){
        int vertex = deQueue(queue);
        printf("%d ", vertex);
        for(int i =0 ; i< graph->V; i++){
            if (graph->matrix[vertex][i]==1&&visitted[i]==0)
            {
                visitted[i]=1;
                enQueue(queue, i);
            }
            
        }
    }
    printf("\n");
    free(visitted);
    free(queue->arr);
    free(queue);
}
int main (){
    int V, E;
    printf("nhap so dinh: ");
    scanf("%d", &V);
    Graph *graph = createGraph(V);
    printf("nhap so canh: ");
    scanf("%d", &E);
    for (int i = 0; i < E; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    BFS(graph, 0);
    return 0;
}
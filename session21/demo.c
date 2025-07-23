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
int main(void) {
    Graph *graph = createGraph(4);
    addEdge(graph,0,1);
    addEdge(graph,0,3);
    printGraph(graph);
    printf("Hello, World!\n");
    printMatrix(graph);
    return 0;
}
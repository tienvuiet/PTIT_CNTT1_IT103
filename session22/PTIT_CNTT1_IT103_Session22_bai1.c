#include <stdio.h>
#include <stdlib.h>
typedef struct Graph
{
    int V;
    int **matrix;
} Graph;
Graph *createGraph(int V)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->matrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
    {
        graph->matrix[i] = (int *)calloc(V, sizeof(int));
    }
    return graph;
}
void addEdge(Graph *graph, int src, int dest){
    graph->matrix[src][dest]= 1;
    graph->matrix[dest][src]= 1;
}
void printMatrix(Graph *graph){
    for(int i = 0 ;i< graph->V; i++){
        for(int j = 0 ; j< graph->V; j++){
            if(graph->matrix[i][j]==1){
                printf("%d ", graph->matrix[i][j]);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}
int main (){
    Graph *graph = createGraph(5);
    addEdge(graph, 0,1);
    addEdge(graph, 0,2);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);
    printMatrix(graph);
    return 0;
}
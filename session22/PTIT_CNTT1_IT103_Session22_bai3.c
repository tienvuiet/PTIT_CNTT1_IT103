#include<stdio.h>
#include<stdlib.h>
typedef struct Graph {
    int V;
    int **matrix;
}Graph;
Graph *createGraph(int V){
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->V= V;
    graph->matrix = (int **)malloc(V*sizeof(int *)); 
    for(int i = 0 ; i< V; i++){
        graph->matrix[i]= (int *)calloc(V, sizeof(int));

    }
    return graph;
}
void addEdge(Graph *graph, int src, int dest){
    graph->matrix[src][dest]= 1;
    graph->matrix[dest][src]= 1;
}
void printMatrix(Graph *graph){
    for(int i = 0 ; i< graph->V; i++){
        for(int j = 0 ; j< graph->V; j++){
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}
void printGraphList(Graph *Graph){
    for(int i = 0 ; i< Graph->V; i++){
        printf("%d: ", i);
        for(int j = 0; j< Graph->V; j++){
            if (Graph->matrix[i][j]==1)
            {
                printf("%d->", j);
            }
            
        }
        printf("NULL\n");
    }
}
int main (){
    int V, E;
    printf("nhap so dinh: ");
    scanf("%d", &V);
    Graph *graph = createGraph(V);
    printf("nhap so canh: ");
    scanf("%d", &E);
    for(int i = 0 ; i< E; i++){
        int src, dest;
        scanf("%d %d ", &src, &dest);
        addEdge(graph, src, dest); 
    }
    
    printf("Before: \n");
    printMatrix(graph);
    printf("After: \n");
    printGraphList(graph);
    return 0;
}
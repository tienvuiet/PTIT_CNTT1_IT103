#include<stdio.h>
#include<stdlib.h>
typedef struct Graph{
    int V;
    int **matrix;
}Graph;
Graph *createGraph(int V){
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->matrix = (int **)malloc(V*sizeof(int*));
    for(int i = 0 ; i< V; i++){
        graph->matrix[i]= (int*)calloc(V, sizeof(int));

    }
    return graph;
}
void addEdge(Graph *graph, int src, int dest){
    graph->matrix[src][dest]= 1;
    graph->matrix[dest][src]= 1;
}
void printGraph(Graph *graph){
    for(int i = 0 ; i< graph->V; i++){
        printf("%d: ", i);
        for(int j =0 ; j< graph->V; j ++){
            if (graph->matrix[i][j]==1)
            {
               printf("%d ", j);
            }
        }
        printf("\n");
    }
}
int main (){
    
    int V, E;
    printf("nhap co luong dinh V: ");
    scanf("%d", &V);
    Graph *graph = createGraph(V);
    printf("Nhap canh E: ");
    scanf("%d", &E);
    for(int i = 0 ; i< E; i++){
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    printGraph(graph);
    return 0;
}
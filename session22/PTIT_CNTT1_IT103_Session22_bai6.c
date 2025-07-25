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
void DFSUtil(Graph *graph, int src, int *visited){
    printf("%d ", src);
    visited[src]=1;
    for(int i = 0 ; i< graph->V; i++){
        if (graph->matrix[src][i]==1&&visited[i]==0)
        {
            DFSUtil(graph, i, visited);
        }
        
    }
}
void DFS(Graph *graph, int src){
    int *visited = (int*)calloc(graph->V, sizeof(int));
    printf("Bat dau duyet DFS tu dinh %d: ", src);
    DFSUtil(graph, src, visited);
    printf("\n");
    free(visited);
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
    DFS(graph, 0);
    return 0;
}
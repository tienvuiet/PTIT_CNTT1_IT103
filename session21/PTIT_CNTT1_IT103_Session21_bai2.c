#include <stdio.h>
#include <Stdlib.h>
#define SIZE 4
void addEdge(int graph[SIZE][SIZE], int firstNode, int secondNode)
{
    graph[firstNode][secondNode] = 1;
    graph[secondNode][firstNode] = 1;
}
void printfGraph(int graph[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int graph[SIZE][SIZE] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    };
    addEdge(graph, 0,1);
    addEdge(graph, 0,2);
    addEdge(graph, 1,2);
    addEdge(graph, 2,3);
    printfGraph(graph);
    return 0;
}
#include<stdio.h>
int graph[3][3]= {  
    {0,0,0},
    {0,0,0},
    {0,0,0},
};
void addEdge(int startNode, int endNode){
    if(startNode>=0&&startNode<3&&endNode>=0&&endNode<3){
        graph[startNode][endNode]=1;
    }
}
void printGraph(){
    for(int i=0 ; i< 3; i++){
        for(int j = 0 ; j< 3; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main (){
    printf("ban dau:\n ");
    printGraph();
    addEdge(1,0);
    addEdge(1,2);
    addEdge(2,0);
    printf("luc sau:\n");
    printGraph();
    return 0;

}
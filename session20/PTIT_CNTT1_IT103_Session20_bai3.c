#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node *createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
typedef struct Queue{
    Node **arr;
    int front ;
    int rear;
    int capacity;
}Queue;
Queue *createQueue(int capacity){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->arr = (Node**)malloc(capacity*sizeof(Node*));
    q->front = 0;
    q->rear = -1;
    return q;
}
int isEmpty(Queue *queue){
    if(queue->rear<queue->front){
        return 1;
    }
    return 0;
}
void enQueue(Queue *queue, Node *node){
    if(queue->rear == queue->capacity-1){
        return ;
    }
    queue->rear++;
    queue->arr[queue->rear]= node;
}
Node *dequeue(Queue *queue){
    if(isEmpty(queue)){
        return NULL;
    }
   return  queue->arr[queue->front++];
}
void levelorderBFS(Node *root){
    if(root==NULL){
        printf("tree is empty");
        return ;
    }
    Queue *queue = createQueue(100);
    enQueue(queue, root);
    while(!isEmpty(queue)){
        Node *node = queue->arr[queue->front++];
        printf("%d ", node->data);
        if(node->left!= NULL){
            enQueue(queue, node->left);
        }
        if(node->right!= NULL){
            enQueue(queue, node->right);
        }
    }
}
Node *insert(Node *root, int value){
    Node *newNode = createNode(value);
    if(root == NULL){
        return newNode;
    }
    Queue *queue = createQueue(100);
    enQueue(queue, root);
    while(!isEmpty(queue)){
        Node *node = dequeue(queue);
        if(node->left!= NULL){
            enQueue(queue, node->left);
        }else{
            node->left = newNode;
            free(queue->arr);
            free(queue);
            return root;
        }
        if(node->right!= NULL){
            enQueue(queue, node->right);
        }else{
            node->right = newNode;
            free(queue->arr);
            free(queue);
            return root;
        }
    }
    return root;
}
int main (){
    Node *root = createNode(1);
    Node *node1 = createNode(2);
    Node *node2 = createNode(3);
    Node *node3 = createNode(4);
    Node *node4 = createNode(5);
    Node *node5 = createNode(6);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4; 
    node2->left = node5;
    levelorderBFS(root);
    int value;
    printf("gia tri muon them :");
    scanf("%d", &value);
    insert(root, value);
    levelorderBFS(root);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
// cai dat dfs
// b1: cau truc node
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;
// ham tao node

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("cap phat khong thanh cong");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// b2: trien hai dfs bang de quy
// 2.ore_order(NLR)
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
// in order(LNR)
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// 3. post order(LRN)
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
// b3: xay cay va trien khai trong main
// BFS: theo chieu rong
// leverorder
// b1: xay dung cau truc hang doi
typedef struct Queue
{
    Node **arr;
    int capacity;
    int front;
    int rear;
} Queue;
// 2: ham khoi tao hang di
Queue *createQueue(int capacity)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->arr = (Node**)malloc(capacity * sizeof(Node));
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
    return q;
}
// xay dung ham kiem tra hang doi trong
int isEmpty(Queue *queue)
{
    if (queue->rear<queue->front)
    {
        return 1;
    }
    return 0;
}
// them vao hang doi
void enQueue(Queue *queue, Node *node)
{
    // B1: Kiem tra hang doi (Mang khong con vi tri de them)
    if (queue->rear == queue->capacity - 1)
    {
        return;
    }
    // B2: Tang chi so rear len
    queue->rear++;
    // B3: Them gia tri vao vi tri rear
    queue->arr[queue->rear] = node;
}
void levelorderBFS(Node *root)
{
    // kiem tra rong
    if (root == NULL)
    {
        printf("tree is empty");
        return;
    }
    // khoi tao hang doi
    Queue *queue = createQueue(100);

    // dua root vao hang doi
    enQueue(queue, root);
    while (!isEmpty(queue))
    {
        // thuc hien vong lap den khi hang doi trong
        // lay root ra khoi hang doi
        Node *node = queue->arr[queue->front++];
        printf("%d ", node->data);
        // kiem tra va them con trai vao hang doi
        if(node->left!= NULL){
            enQueue(queue, node->left);
        }
        // kiem tra va them con phai vao hang doi
        if(node->right!= NULL){
            enQueue(queue, node->right);
        }
    }
}
int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("Inorder(LNR): ");
    inorder(root);
    printf("\n");
}
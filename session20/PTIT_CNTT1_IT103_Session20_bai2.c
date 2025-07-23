#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
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
typedef struct Queue
{
    Node **arr;
    int capacity;
    int front;
    int rear;
} Queue;
Queue *createQueue(int capacity)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->arr = (Node **)malloc(capacity * sizeof(Node*));
    q->front = 0;
    q->rear = -1;
    return q;
}
int isEmpty(Queue *queue)
{
    if (queue->rear <  queue->front)
    {
        return 1;
    }
    return 0;
}
void enQueue(Queue *queue, Node *node)
{
    if (queue->rear == queue->capacity - 1)
    {
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = node;
}
void levelOrderBFS(Node *root)
{
    if (root == NULL)
    {
        printf("tree is empty");
        return;
    }
    Queue *queue = createQueue(100);
    enQueue(queue, root);
    while (!isEmpty(queue))
    {
        Node *node = queue->arr[queue->front++];
        printf("%d ", node->data);
        if (node->left != NULL)
        {
            enQueue(queue, node->left);
        }
        if (node->right != NULL)
        {
            enQueue(queue, node->right);
        }
    }
}
int main()
{
    Node *root = createNode(2);
    Node *node1 = createNode(3);
    Node *node2 = createNode(4);
    Node *node3 = createNode(5);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    printf("preorder: ");
    preorder(root);
    printf("\ninorder: ");
    inorder(root);
    printf("\npostorder: ");
    postorder(root);
    printf("\nlevelorderBFS: ");
    levelOrderBFS(root);
    return 0;
}
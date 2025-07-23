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
typedef struct Queue
{
    Node **arr;
    int front;
    int rear;
    int capacity;
} Queue;
Queue *createQueue(int capacity)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->arr = (Node **)malloc(sizeof(Node *) * capacity);
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
    return q;
}
int isEmpty(Queue *queue)
{
    if (queue->rear < queue->front)
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
Node *deQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        return NULL;
    }
    return queue->arr[queue->front++];
}
int levelOrderBFS(Node *root, int value)
{
    if (root == NULL)
    {
        printf("tree is empty");
        return NULL;
    }

    Queue *queue = createQueue(100);
    enQueue(queue, root);
    int level = 0;
    while (!isEmpty(queue))
    {
        int nodeCount = queue->rear - queue->front + 1;
        while (nodeCount > 0)
        {
            Node *node = deQueue(queue);
            if(node->data==value){
                return level;
            }
            if (node->left != NULL)
            {
                enQueue(queue, node->left);
            }
            if (node->right != NULL)
            {
                enQueue(queue, node->right);
            }
            nodeCount--;
        }
        level++;
    }
    return -1;
}
int main()
{
    Node *root = createNode(2);
    Node *node1 = createNode(3);
    Node *node2 = createNode(4);
    Node *node3 = createNode(5);
    Node *node4 = createNode(6);
    Node *node5 = createNode(7);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    int value;
    printf("nhap gai tri muon tim tang: ");
    scanf("%d", &value);
    int tang = levelOrderBFS(root, value);
    printf("%d o level %d", value, tang);
    return 0;
 
}
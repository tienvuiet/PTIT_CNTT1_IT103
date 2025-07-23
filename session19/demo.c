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
    q->arr = (Node **)malloc(capacity * sizeof(Node *));
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
    return q;
}
// xay dung ham kiem tra hang doi trong
int isEmpty(Queue *queue)
{
    if (queue->rear < queue->front)
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
        if (node->left != NULL)
        {
            enQueue(queue, node->left);
        }
        // kiem tra va them con phai vao hang doi
        if (node->right != NULL)
        {
            enQueue(queue, node->right);
        }
    }
}
Node *dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        return;
    }
    queue->arr[queue->front++];
}
// xay dung ham them vao cay
Node *insert(Node *root, int data)
{
    // b1 khoi tao node sex duoc them
    Node *newNode = createNode(data);
    if (root == NULL)
    {
        return newNode;
    }
    // kiem tra cay trong
    // b2 khoi tao hang doi va dua node goc vao hang doi
    Queue *queue = createQueue(100);
    enQueue(queue, root);
    // b3 trien khai vong lap khi hang doi trong
    while (!isEmpty(queue))
    {
        Node *node = dequeue(queue);
        if (node->left != NULL)
        {
            enQueue(queue, node->left);
        }
        else
        {
            node->left = newNode;
            free(queue->arr);
            free(queue);
            return root;
        }
        if (node->right != NULL)
        {
            enQueue(queue, node->right);
        }
        else
        {
            node->right = newNode;
            free(queue->arr);
            free(queue);
            return root;
        }
    }
    // b4 lay node dau hang doi ra

    // b5 kiem tra con ben trai node duoc lay
    // neu co thi day con ben trai vao hang doi
    // neo khong thi chen node moi vao vi tri con trai
    // b6 kiem tra con ben phai node
    // neo co thi day vao hang doi
    // neu khong thi ngay lap tuc chen vao
}
// xay dung phuong thuc xoa
Node *delete(Node *root, int data)
{
    // b1: kiem tra cay trong
    if (root == NULL)
    {
        return NULL;
    }
    // b2: khoi taoh hang doi va day root vao hang doi
    Queue *queue = createNode(120);
    enQueue(queue, root);
    // b2: khoi tao 3 node can thiet target, lastNode, lastParent
    Node *target = NULL;
    Node *lastNode = NULL;
    Node *lastParent = NULL;
    // b4:trien khai vonf lap den khi hang doi trong
    while (!isEmpty(queue))
    {
        Node *node = dequeue(queue);
        if (node->data == data)
        {
            target = node;
        }
        if (node->left != NULL)
        {
            enQueue(queue, node->left);
            lastParent = node;
            lastNode = node->left;
        }
        if (node->right != NULL)
        {
            enQueue(queue, node->right);
            lastParent = node;
            lastNode = node->right;
        }
    }
    // b5: lay node dau hang doi ra
    // kiem tra node co phai node can xoa khong va cap nhat target

    // b6: kiem tra con ben trai cua node
    // neu day con ben trai vao hang doi
    // cap nhat gia tri lastParent = node
    // cap nhat gia tri lastNode

    // b6: kiem tra con ben phai cua node
    // neu day con ben phai vao hang doi
    // cap nhat gia tri lastParent = node
    // cap nhat gia tri lastNode

    // kiem tra target

    // truong hop cay co nhieu hon 1 node
    // cap nhat du lieu cua node can xoa
    // cap nhat con cua lastParent
    // kiem tra xem lastNode la con ben trai hay ben phai
    // giai phong lastNode
    // truong hop chi co 1 node
    // giai ophong node
    // gan lai root = NULL;

    // giai phong cac vug nho va tra ve
    if (target == NULL)
    {
        free(queue->arr);
        free(queue);
        return root;
    }
    if (lastParent != NULL)
    {
        target->data = lastNode->data;
        if (lastParent->left == lastNode)
        {
            lastParent->left = NULL;
        }
        else
        {
            lastParent->right = NULL;
        }
        free(lastNode);
    }

    else
    {
        free(root);
        root = NULL;
    }
    free(queue->arr);
    free(queue);
    return root;
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
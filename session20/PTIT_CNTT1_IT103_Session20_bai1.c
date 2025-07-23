#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node *creatNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int main (){
    Node* root = createNode(2);
    Node* node1 = createNode(3);
    Node* node2 = createNode(4);
    Node* node3 = createNode(5);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    
    return 0;
}
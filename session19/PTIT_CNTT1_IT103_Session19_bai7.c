#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node *createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void preorder(Node *root){
    if(root==NULL){
        return ;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
int main (){
    Node *root = createNode(1);
    return 0;
}
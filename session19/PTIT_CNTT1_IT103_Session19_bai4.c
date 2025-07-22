#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right= NULL;
    return newNode;
}
void inorder(Node* root){
    if(root ==NULL){
        return ;
    }
    inorder(root->left);
    printf("%d \n", root->data);
    inorder(root->right);

}
int main (){
    Node* root = createNode(2);
    Node* node1 = createNode(3);
    Node* node2 = createNode(4);
    Node* node3 = createNode(5);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    inorder(root);
    return 0;
}
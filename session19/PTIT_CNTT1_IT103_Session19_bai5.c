#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
bool dfsSearch(Node* root, int target){
    if(root==NULL){
        return false;
    }
    if(root->data==target){
        return true;
    }
    bool foundInLeft = dfsSearch(root->left, target);
    if(foundInLeft){
        return true;
    }
    bool foundInRight = dfsSearch(root->right, target);
    return foundInRight;
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
    int value;
    printf("nhap vao gia tri muon tim kiem: ");
    scanf("%d", &value);
    if(dfsSearch){
        printf("true");
    }else{  
        printf("false");
    }
    return 0;
}
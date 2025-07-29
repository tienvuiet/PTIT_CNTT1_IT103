#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node *createNode(int value){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main()
{
    int choice;
    do
    {
        printf("1.Them gia tri\n");
        printf("2.Xoa gia tri\n");
        printf("3.Duyet gia tri\n");
        printf("4.Dem la\n");
        printf("5.Chieu cao\n");
        printf("6.Thoat\n");
        printf("Lua chon cua ban: \n");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        }
    } while (choice != 6);
    return 0;
}
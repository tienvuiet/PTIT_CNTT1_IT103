#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Book
{
    int id;
    char title[100];
    char author[100];
    char category[50];
    float price;
} Book;
typedef struct SNode
{
    Book book;
    struct SNode *next;
} SNode;
typedef struct DNode
{
    Book book;
    struct DNode *next;
    struct DNode *prev;
} DNode;
SNode *currentBook = NULL;
DNode *completedBook = NULL;
SNode *createSNode(Book book)
{
    SNode *newNode = (SNode *)malloc(sizeof(SNode));
    newNode->book = book;
    newNode->next = NULL;
    return newNode;
}
DNode *createDNode(Book book)
{
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    newNode->book = book;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void addBook()
{
    Book b;
    printf("Nhap id sach: ");
    scanf("%d", &b.id);
    getchar();
    printf("Nhap ten sach: ");
    fgets(b.title, 100, stdin);
    b.title[strcspn(b.title, "\n")] = '\0';
    printf("Nhap ten tac gia: ");
    fgets(b.author, 100, stdin);
    b.author[strcspn(b.author, "\n")] = '\0';
    printf("Nhap the loai: ");
    fgets(b.category, 100, stdin);
    b.category[strcspn(b.category, "\n")] = '\0';
    printf("nhap gia sach: ");
    scanf("%f", &b.price);
    SNode *newNode = createSNode(b);
    if (currentBook == NULL)
    {
        currentBook = newNode;
    }
    else
    {
        SNode *temp = currentBook;
        while (temp->next != NULL)
        {

            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Them thanh cong \n");
}
void displayBook()
{
    if (currentBook == NULL)
    {
        printf("khong co sach de hien thi!\n");
        return;
    }
    SNode *temp = currentBook;
    while (temp != NULL)
    {
        printf("ID: %d,Title: %s, Author: %s, Category: %s, Price: %f", temp->book.id, temp->book.title, temp->book.author, temp->book.category, temp->book.price);
        temp = temp->next;
    }
}
void deleteAtBook()
{
    int id;
    printf("Nhap id can xoa: ");
    scanf("%d", &id);
    if (currentBook == NULL)
    {
        printf("khong co quyen sach nao ma xoa");
        return;
    }
    SNode *temp = currentBook, *prev = NULL;
    while (temp != NULL, temp->book.id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("khong co phan tu nao ma xoa :))");
        return;
    }
    if (prev == NULL)
    {
        currentBook = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    free(temp);
    printf("da xoa");
}
void updateBook()
{
    int id;
    printf("nhap id sach can cap nhat: ");
    scanf("%d", &id);
    getchar();
    SNode *temp = currentBook;
    while (temp != NULL && temp->book.id != id)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("khong co sach de cap nhat");
        return;
    }
    printf("nhap vao ten sach moi: ");
    fgets(temp->book.title, 100, stdin);
    temp->book.title[strcspn(temp->book.title, "\n")] = '\0';
    printf("nhap vao ten tac gia moi: ");
    fgets(temp->book.author, 100, stdin);
    temp->book.author[strcspn(temp->book.author, "\n")] = '\0';
    printf("nhap vao the loai moi: ");
    fgets(temp->book.category, 100, stdin);
    temp->book.category[strcspn(temp->book.category, "\n")] = '\0';
    printf("Nhap gia moi: ");
    scanf("%f", &temp->book.price);
    printf("cap nhat thanh cong!!");
}
void tickBook()
{
    int id;
    printf("nhap vao id sach muon danh dau: \n");
    scanf("%d", &id);
    getchar();
    SNode *temp = currentBook, *prev = NULL;
    while(temp!= NULL&& temp->book.id!= id){
        prev = temp;
        temp = temp->book.id;
    }
    if (temp == NULL)
    {
        printf("khong co sach ma danh dau:))\n");
        return ;
    }
    if (prev==NULL)
    {
        currentBook = temp->next;
    }
    


    
}
int main()
{
    int choice;
    do
    {
        printf("\n------Menu------\n");
        printf("1.Them sach\n");
        printf("2.Hien thi danh sach tat ca quyen sach\n");
        printf("3.Xoa sach\n");
        printf("4.Cap nhat thong tin mot quyen sach\n");
        printf("5.Danh dau sach da doc xong\n");
        printf("6.Sap xep sach theo gia tri tang dan\n");
        printf("7.tim kiem sach theo tieu de\n");
        printf("8.Thoat chuong trinh\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            displayBook();
            break;
        case 3:
            deleteAtBook();
            break;
        case 4:
            updateBook();
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        default:
            printf("lua chon khong hop le!");
        }

    } while (choice != 8);
    return 0;
}
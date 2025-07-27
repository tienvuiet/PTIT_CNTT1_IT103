#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Manager
{
    int id;
    char title[100];
    int priority;
    char deadline[100];
} Manager;
typedef struct SNode
{
    Manager manager;
    struct SNode *next;
} SNode;
typedef struct DNode
{
    Manager manager;
    struct DNode *next;
    struct DNode *prev;
} DNode;
SNode *currentManager = NULL;
DNode *completedManager = NULL;
SNode *createSNode(Manager manager)
{
    SNode *newNode = (SNode *)malloc(sizeof(SNode));
    newNode->manager = manager;
    newNode->next = NULL;
    return newNode;
}
DNode *createDNode(Manager manager)
{
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    newNode->manager = manager;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

int idManager = 1;
void addManager()
{
    Manager m;
    m.id = idManager++;
    printf("Ten nhiem vu: ");
    fgets(m.title, 100, stdin);
    m.title[strcspn(m.title, "\n")] = '\0';
    printf("Muc do uu tien: ");
    scanf("%d", &m.priority);
    getchar();
    printf("Thoi gian hoan thanh nhiem vu (dd/mm/yyyy): ");
    fgets(m.deadline, 100, stdin);
    m.deadline[strcspn(m.deadline, "\n")] = '\0';
    SNode *newNode = createSNode(m);
    if (currentManager == NULL)
    {
        currentManager = newNode;
    }
    else
    {
        SNode *temp = currentManager;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Them thanh cong\n");
}
void displaySNode()
{
    if (currentManager == NULL)
    {
        printf("danh sach nhiem vu trong\n");
        return;
    }
    printf("Nhiem vu:\n");
    SNode *temp = currentManager;
    while (temp != NULL)
    {
        printf("Id: %d, Title: %s, Priority: %d, Dealine: %s", temp->manager.id, temp->manager.title, temp->manager.priority, temp->manager.deadline);
        temp = temp->next;
    }
}
void deletedAtManager()
{
    int id;
    printf("Nhap id nhiem vu muon xoa: ");
    scanf("%d", &id);
    SNode *temp = currentManager, *prev = NULL;
    while (temp != NULL && temp->manager.id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("khong co nhiem vu trong danh sach");
        return;
    }
    if (prev == NULL)
    {
        currentManager = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    free(temp);
    printf("da xoa");
}
void updateAtManager()
{
    int id;
    printf("Nhap id nhiem vu can cap nhat: ");
    scanf("%d", &id);
    getchar();
    SNode *temp = currentManager;
    while (temp != NULL && temp->manager.id != id)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Khong co nhiem vu co id can cap nhat!");
        return;
    }

    printf("Title moi: ");
    fgets(temp->manager.title, 100, stdin);
    temp->manager.title[strcspn(temp->manager.title, "\n")] = '\0';
    printf("Muc do uu tien moi: ");
    scanf("%d", &temp->manager.priority);
    getchar();
    printf("Thoi gian hoan thanh nhiem vu moi: ");
    fgets(temp->manager.deadline, 100, stdin);
    temp->manager.deadline[strcspn(temp->manager.deadline, "\n")] = '\0';
}
void tickManager()
{
    int id;
    printf("nhap id nhiem vu can danh dau: ");
    scanf("%d", &id);
    getchar();
    SNode *temp = currentManager, *prev = NULL;
    while (temp != NULL && temp->manager.id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("khong tim thay id san pham muon danh dau");
        return;
    }
    if (prev == NULL)
    {
        currentManager = temp->next;
    }
    else
    {
        prev->next = temp->next;
        DNode *done = createDNode(temp->manager);
        done->next = completedManager;
        if (completedManager != NULL)
        {
            completedManager->prev = done;
        }
        completedManager = done;
        free(temp);
        printf("Danh dau thanh cong!!");
    }
}
void sortManager()
{
    if (currentManager == NULL)
    {
        printf("Khong co khoa hoc nao de sort");
        return;
    }
    for (SNode *i = currentManager; i != NULL; i = i->next)
    {
        for (SNode *j = i->next; j != NULL; j = j->next)
        {
            if (i->manager.priority > j->manager.priority)
            {
                Manager tmp = i->manager;
                i->manager = j->manager;
                j->manager = tmp;
            }
        }
    }
    printf("Sau khi xap xep:\n");
    displaySNode();
}
void searchManager()
{
    char search[100];
    printf("Nhap ten nhiem vu can tim: ");
    fgets(search, 100, stdin);
    search[strcspn(search, "\n")] = '\0';
    SNode *temp = currentManager;
    int found = 0;
    while (temp != NULL)
    {
        if (strcmp(temp->manager.title, search) == 0)
        {
            printf("Id: %d, Title: %s, Priority: %d, Dealine: %s", temp->manager.id, temp->manager.title, temp->manager.priority, temp->manager.deadline);
            found = 1;
        }
        temp = temp->next;
            
    }
    if (found==0)
    {
        printf("khong tim thay nhiem vu\n");
    }
    
}
int main()
{
    int choice;
    do
    {
        printf("\nMENU:\n");
        printf("1.Them nhiem vu\n");
        printf("2.Hien thi danh sach nhiem vu:\n");
        printf("3.Xoa nhiem vu\n");
        printf("4.Cap nhat thong tin nhiem vu\n");
        printf("5.Danh dau nhiem vu hoan thanh\n");
        printf("6.Xap xep nhiem vu\n");
        printf("7.Tim kiem nhiem vu\n");
        printf("8.Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            addManager();
            break;
        case 2:
            displaySNode();
            break;
        case 3:
            deletedAtManager();
            break;
        case 4:
            updateAtManager();
            break;
        case 5:
            tickManager();
            break;
        case 6:
            sortManager();
            break;
        case 7:
            searchManager();
            break;
        case 8:
            printf("Da thoat chuong trinh");
            break;
        }
    } while (choice != 8);
    return 0;
}
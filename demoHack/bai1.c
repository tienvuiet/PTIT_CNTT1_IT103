#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Course
{
    int id;
    char title[100];
    int credit;
} Course;
typedef struct SNode
{
    Course course;
    struct SNode *next;

} SNode;
typedef struct DNode
{
    Course course;
    struct DNode *prev;
    struct DNode *next;

} DNode;
SNode *currentCourses = NULL;
DNode *completedCourses = NULL;

SNode *createSNode(Course course)
{
    SNode *newNode = (SNode *)malloc(sizeof(SNode));
    newNode->course = course;
    newNode->next = NULL;
    return newNode;
}

DNode *createDNode(Course course)
{
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    newNode->course = course;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void addCourse()
{
    Course c;
    printf("Nhap ID khoa hoc:");
    scanf("%d", &c.id);
    getchar();
    printf("nhap ten khoa hoc: ");
    fgets(c.title, 100, stdin);
    c.title[strcspn(c.title, "\n")] = '\0';
    printf("nhap so tin chi: ");
    scanf("%d", &c.credit);
    SNode *newNode = createSNode(c);
    if (currentCourses == NULL)
    {
        currentCourses = newNode;
    }
    else
    {
        SNode *temp = currentCourses;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("them thanh cong\n");
}

void displaySNode()
{
    if (currentCourses == NULL)
    {
        printf("danh sach khoa hoc rong");
        return;
    }
    printf("khoa hoc: ");
    SNode *temp = currentCourses;
    while (temp != NULL)
    {
        printf("ID: %d, title: %s, credit: %d\n", temp->course.id, temp->course.title, temp->course.credit);
        temp = temp->next;
    }
}
void deletAtCourse()
{
    int id;
    printf("nhap id can xoa:");
    scanf("%d", &id);
    SNode *temp = currentCourses, *prev = NULL;
    while (temp != NULL && temp->course.id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("khong co khoa hoc trong danh sach");
        return;
    }
    if (prev == NULL)
    {
        currentCourses = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    free(temp);
    printf("da xoa");
}
void updateAtCourse()
{
    int id;
    printf("nhap id khoa hoc can cap nhat: ");
    scanf("%d", &id);
    getchar();
    SNode *temp = currentCourses;
    while (temp != NULL && temp->course.id != id)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("khong tim thay khoa hoc co id phu hop");
        return;
    }
    printf("nhap ten khoa hoc can cap nhat:");
    fgets(temp->course.title, 100, stdin);
    temp->course.title[strcspn(temp->course.title, "\n")] = '\0';
    printf("nhap so tin: ");
    scanf("%d", &temp->course.credit);
}
void tickAtCourse()
{
    int id;
    printf("nhap id khoa hoc hoan thanh: ");
    scanf("%d", &id);
    getchar();
    SNode *temp = currentCourses, *prev = NULL;
    while (temp != NULL && temp->course.id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("ko tim thay id khoa hoc can danh dau!!");
        return;
    }
    if (prev == NULL)
    {
        currentCourses = temp->next;
    }
    else
    {
        prev->next = temp->next;
        DNode *done = createDNode(temp->course);
        done->next = completedCourses;
        if (completedCourses != NULL)
        {
            completedCourses->prev = done;
        }
        completedCourses = done;
        free(temp);
        printf("Danh dau thanh cong!!");
    }
}
void sortCreate()
{
    if (currentCourses == NULL)
    {
        printf("khong co khoa hoc nao de sort :))");
        return;
    }
    for (SNode *i = currentCourses; i != NULL; i = i->next)
    {
        for (SNode *j = i->next; j != NULL; j = j->next)
        {
            if (i->course.credit>j->course.credit)
            {
                Course tmp = i->course;
                i->course = j->course;
                j->course = tmp;
            }
        }
    }
    printf("da xap xep\n");
    displaySNode();

}
void searchNameCourse(){
    char search[100];
    getchar();
    printf("nhap vao khoa hoc muon tim kiem: ");
    fgets(search, 100, stdin);
    search[strcspn(search, "\n")]='\0';
    SNode* temp = currentCourses;
    int found = 0;
    while(temp!=NULL){
        if(strstr(temp->course.title, search)){
            printf("ID: %d, Title: %s, Creadit: %d\n", temp->course.id,temp->course.title, temp->course.credit);
            found = 1;
        }
        temp= temp->next;
    }
    if(!found){
        printf("khong tim thay khoa hoc\n");
    }

}

int main()
{
    int choice;
    do
    {   
        printf("Quan ly khoa hoc:\n");
        printf("1.Them khoa hoc\n");
        printf("2.Hien thi danh sach khoa hoc\n");
        printf("3.Xoa khoa hoc theo id\n");
        printf("4.Cap nhat thong tin khoa hoc\n");
        printf("5.Danh dau khoa hoc da hoan thanh\n");
        printf("6.Sap xep khoa hoc theo so tin chi\n");
        printf("7.Tim kiem khoa hoc theo ten\n");
        printf("8.Thoat\n");
        printf("Lua chon cua ban:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addCourse();
            break;
        case 2:
            displaySNode();
            break;
        case 3:
            deletAtCourse();
            break;
        case 4:
            updateAtCourse();
            break;
        case 5:
            tickAtCourse();
            break;
        case 6:
            sortCreate();
            break;
        case 7:
            searchNameCourse();
            break;
        case 8:
            printf("da thoat chuong trinh");
            break;
        default:
            printf("Lua chon khong hop le");
        }

    } while (choice != 8);
    return 0;
}
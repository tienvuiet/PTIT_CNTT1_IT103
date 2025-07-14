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
    Course data;
    struct SNode *next;

} SNode;
typedef struct DNode
{
    Course data;
    struct DNode *prev;
    struct DNode *next;

} DNode;
SNode *currentCourses = NULL;
DNode *completeCourses = NULL;
void addCourse()
{
    Course c;
    printf("Nhap id khoa hoc: ");
    scanf("%d", &c.id);
    printf("Nhap ten khoa hoc: ");
    getchar();
    fgets(c.title, 100, stdin);
    c.title[strcspn(c.title, "\n")] = '\0';
    printf("Nhap so tin chi: ");
    scanf("%d", &c.credit); 

    SNode *newNode = (SNode *)malloc(sizeof(SNode));
    newNode->data = c;
    newNode->next = currentCourses;
    currentCourses = newNode;
    printf("Da them.\n");
}
void displayCurrentCourse()
{
    SNode *temp = currentCourses;
    if (!temp)
    {
        printf("danh sach khoa hoc trong\n");
        return;
    }
    printf("\n Danh sach cac khoa hoc: \n");
    while (temp)
    {
        printf("ID: %d, Ten: %s, Tin chi: %d\n", temp->data.id, temp->data.title, temp->data.credit);
        temp = temp->next;
    }
}
void deleteCourse(){
    int id;
    printf("Nhap id khoa hoc: ");
    scanf("%d", &id);
    SNode *temp = currentCourses, *prev = NULL;
    while(temp){
        if(temp->data.id==id){
            if(prev){
                prev->next = temp->next;
                
            }else{
                currentCourses = temp->next;
            }
            free(temp);
            printf("Xoa thanh cong\n");
            return;
        }
        prev= temp;
        temp = temp->next;
    }
    printf("ko tim thay khoa hoc co id can xoa\n");
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
        case 1 :
            addCourse();
            break;
        case 2:
            displayCurrentCourse();
            break;
        case 3:
            deleteCourse();
            break;    
        default:
            printf("Lua chon khong hop le");
        }

    } while (choice != 8);
    return 0;
}
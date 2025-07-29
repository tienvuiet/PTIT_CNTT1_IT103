#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Student
{
    int id;
    char name[100];
    bool status;
    int avg;
} Student;
typedef struct DNode
{
    Student student;
    struct DNode *next;
    struct DNode *prev;
} DNode;
Student students[1000];
int studentCount = 0;
int nextId = 1;
void addStudent()
{
    if (studentCount >= 1000)
    {
        printf("Danh sach day\n");
        return;
    }
    Student s;
    s.id = nextId++;
    printf("Nhap ten sinh vien:");
    fgets(s.name, 100, stdin);
    s.name[strcspn(s.name, "\n")] = '\0';
    s.status = true;
    printf("Nhap diem trung binh: ");
    scanf("%d", &s.avg);
    students[studentCount++] = s;
    printf("Them thanh cong!\n");
}
void displayStudent()
{
    if (studentCount == 0)
    {
        printf("Danh sach trong\n");
        return;
    }
    printf("Danh sach sinh vien: \n");
    for (int i = 0; i < studentCount; i++)
    {
        printf("ID: %d, Ten: %s, Diem TB: %d, Trang thai: %s\n", students[i].id, students[i].name, students[i].avg, students[i].status == true ? "hoat dong" : "khong hoat dong");
    }
}
void deleteStudent(){
    printf("Nhap ");
}
int main()
{
    int choice;
    do
    {
        printf("1.Them sinh vien\n");
        printf("2.Hien thi danh sach sinh vien\n");
        printf("3.Xoa sinh vien\n");
        printf("4.Cap nhat thong tin sinh vien\n");
        printf("5.Thay doi trang thai sinh vien\n");
        printf("6.Sap xep sinh vien\n");
        printf("7.Tim kiem sinh vien\n");
        printf("8.Thoat chuong trinh\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudent();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            printf("Da thoat chuong trinh\n");
            break;
        default:
            printf("Lua chon khong hop le\n");
        }
    } while (choice);
    return 0;
}
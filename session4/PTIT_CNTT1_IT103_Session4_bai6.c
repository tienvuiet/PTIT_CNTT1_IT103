#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Student{
    int id;
    char name[50];
    int age;
};
int main (){
    int n;
    printf("nhap so luong sinh vien:\n ");
    scanf("%d", &n);
    struct Student *students = (struct Student *)malloc (n*sizeof(struct Student));
    printf("nhap thong tin cua sinh vien:\n");
    for(int i =0 ; i< n ; i++){
        printf("\nSinh vien %d", i+1);
        printf("ID:" );
        scanf("%d", &students[i].id);
        getchar();
        printf("Name: ");
        fgets(students[i].name, 50 , stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        printf("Age: ");
        scanf("%d", &students[i].age);
    }
    printf("Danh sach sinh vien: ");
    for(int i =0 ; i< n ; i++){
        printf("SV %d: ID= %d, Name= %s, Age= %d\n", i+1, students[i].id, students[i].name, students[i].age);

    }
    int searchId;
    printf("Id sinh vien can tim: ");
    scanf("%d", &searchId);
    int found=0;
    for(int i =0; i< n ; i++){
        if(students[i].id == searchId){
            printf("Id: %d, Name: %s, Age: %d", students[i].id, students[i].name, students[i].age);
            found = 1;
            break;
        }
    }
    if(found ==0 ){
        printf("khong tim thay sinh vien co id day");
    }
    return 0;
}
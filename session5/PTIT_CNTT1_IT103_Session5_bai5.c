#include<stdio.h>
#include<string.h>
int chuoiDoiXung(char str[],int start,int end){
    if(start>=end){
        return 1;
    }
    if(str[start]!=str[end])
    {
        return 0;
    }
    return chuoiDoiXung(str, start+1, end-1);
    
}
int main(){
    char str[100];
    printf("nhap vao mot chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str,"\n")]=0;
    if(chuoiDoiXung(str, 0, strlen(str)-1)){
        printf("chuoi doi xung");

    }else{
        printf("khong la chuoi doi xung: ");
    }


}

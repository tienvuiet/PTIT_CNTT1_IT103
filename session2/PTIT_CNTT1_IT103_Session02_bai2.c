#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    int search;
    int count;
    printf("nhap so luong phan tu mang:");
    scanf("%d",&n);
    int *arr= (int *)malloc(n*sizeof(int));
    for(int i =0; i< n; i++){
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("nhap vao phan tu muon kiem tra trung lap: ");
    scanf("%d", &search);
    for(int i =0 ;i<n; i++){
        if(arr[i]==search){
            count ++;
        }
    }
    if(count ==0){
        printf("khong co phan tu trung lap");
    }else{
        printf("phan tu %d lap lai %d", search, count );
    }

}
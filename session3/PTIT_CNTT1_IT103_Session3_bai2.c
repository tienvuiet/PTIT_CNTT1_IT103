#include<stdio.h>
#include<stdlib.h>
int main (){
    int n ; 
    printf("nhap so luong phan tu mang: \n");
    scanf("%d", &n);
    if(n<= 0){
        printf("gia tri khong hop le!!");
        return 1;
    }
    int *a = (int *)malloc(n * sizeof(int));
    for(int i =0 ; i< n; i++){
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    int max = a[0];
    for(int i=1; i< n ; i++){
        if(a[0]<a[i]){
            max= a[i];
        }
    }
    printf("gia tri lon nhat trong mang la: %d",max );
    free(a);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
int main (){
    int n ; 
    printf("nhap so luong phan tu mang: \n");
    scanf("%d", &n);
    if(n<=0){
        printf("so luong phan tu ko hop le");
        return 1;
    }
    int *a = (int *)malloc(n*sizeof(int));
    for(int i =0; i< n; i++){
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    for(int i =0 ; i< n ; i++){
        printf("So thu %d = %d\n", i+1, a[i]);
    }
    free(a);
    return 0;
}
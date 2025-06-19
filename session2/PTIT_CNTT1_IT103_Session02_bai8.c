#include<stdio.h>
#include<stdlib.h>
int main (){
    int n ; 
    printf("nhap so luong phan tu mang: \n");
    scanf("%d", &n);
    int *a = (int *)malloc(n *sizeof(int));
    for(int i =0; i< n ; i++){
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("mang ban dau la: \n");
    for(int i =0; i< n ; i++){
        printf("%d ", a[i]);
    }
    printf("cac gia tri dung sua lon hon dung trc la: ");
    for(int i =0 ; i< n ; i++){
        if(a[i+1]<a[i]){
            printf("%d ", a[i]);
        }
    }
    free(a);
    return 0;
}
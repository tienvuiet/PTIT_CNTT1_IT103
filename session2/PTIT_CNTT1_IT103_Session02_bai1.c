#include<stdio.h>
#include<stdlib.h>
int main(){
    int n ;
    printf("nhap vao so luong phan tu mang: ");
    scanf("%d",&n);
    // int arr[n];
    int *arr= (int *)malloc(n*sizeof(int));
    for(int i =0; i< n; i++){
        printf("arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    int max = arr[0];
    for(int i =1; i<n ; i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    printf("gia tri max la: %d", max);
    free(arr);
    return 0;
}
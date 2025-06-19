#include<stdio.h>
#include<stdlib.h>
int main (){
    int n ;
    scanf("%d", &n);
    int *arr = (int *)malloc(n *sizeof(int ));
    for(int i =0; i< n;  i++){
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    } 
    int index;
    printf("nhap vao vi tri muon sua: ");
    scanf("%d", &index);
    if(index>n ){
        printf("khong ton tai vi tri muon sua");
    }
    for(int i =0; i<n ; i++){
        if(arr[i]==index){
            printf("nhap vao gia tri muon sua: ");
            int giaTri ;
            scanf("%d", &giaTri);
            arr[i]=giaTri;

        }
    }
    printf("mang sao khi sua la: ");
    for(int i =0; i< n; i++){
        printf("arr[%d]: ",arr[i] );
    }
    free(arr);
    return 0;
}
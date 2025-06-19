#include<stdio.h>
#include<stdlib.h>
int main (){
    int n ;
    printf("nhap so luong phan tu trong mang: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n *sizeof(int));
    for(int i =0; i< n; i++){
        printf("arr[%d] ", i);
        scanf("%d", &arr[i]);
    }
    printf("mang ban dau: ");
    for(int i =0; i<n ; i++){
        printf("%d ",arr[i] );
    }
    int indexDelete;
    printf("nhap vao vi tri index muon xoa: ");
    scanf("%d", &indexDelete);
    if(indexDelete>n||indexDelete<0){
        printf("vi tri index ko hop le");
        return 0;
    }else{
        for(int i =indexDelete; i< n-1;i++  ){
            arr[i]= arr[i+1];

        }
        n--;
        printf("mang sau khi xoa la: ");
        for(int i =0; i<n; i++){
            printf("%d ", arr[i]);
        }
    }

    free(arr);
    return 0;
}
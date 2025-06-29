#include<stdio.h>
int  maxValue(int arr[], int size){
    if(size ==1){
        return arr[0];
    }
    int max = maxValue(arr,size-1);
    if(arr[size-1]>max){
        return arr[size-1];
    }else{
        return max;
    }
}
int minValue(int arr[], int size){
    if(size==1){
        return arr[0];
    }
    int min = minValue(arr, size-1);
    if(arr[size-1]<min){
        return arr[size-1];
    }else{
        return min;
    }
}
int main (){
    int n ; 
    printf("nhap so luong phan tu mang: ");
    scanf("%d", &n);
    int a[n];
    for(int i =0; i< n ; i++){
        printf("a[%d]: ",i);
        scanf("%d",&a[i]);
    }
    for(int i =0; i< n ; i++){
        printf("%d ", a[i]);
    }
    int ketQuaMax = maxValue(a,n);
    printf("\nket qua lon nhat: %d", ketQuaMax);
    int ketQuaMin = minValue(a, n);
    printf("\nket qua nho nhat: %d", ketQuaMin);
    return 0;
}
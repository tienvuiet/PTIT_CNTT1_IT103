#include<stdio.h>
void insertionSort(int a[], int n){
    for(int i =0 ; i<n ; i++){
        int j = i;
        while(j> 0 && a[j]<a[j-1]){
            int temp = a[j];
            a[j]= a[j-1];
            a[j-1]= temp;
            j--;
        }

    }
}
int main (){
    int n ; 
    printf("nhap vao so luong phan tu mang ");
    scanf("%d", &n);
    int a[n];
    for(int i =0 ; i< n; i++){
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);

    }
    printf("before: ");
    for(int i =0 ; i< n; i++){
        printf("%d ", a[i]);
    }
    insertionSort(a , n);
    printf("\nafter: ");
    for(int i =0 ; i< n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
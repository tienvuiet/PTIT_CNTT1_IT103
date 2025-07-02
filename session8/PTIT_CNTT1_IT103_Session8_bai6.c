#include <stdio.h>
void swap(int a[], int n , int x, int y){
    int temp = a[x];
    a[x]=a[y];
    a[y]= temp;
}
int partition(int a[], int n , int left, int right){
    int pivot = a[left];
    int count = 0;
    for(int i = left+1; i<=right; i++ ){
        if(a[i]<pivot){
            count ++;
        }
    }
    int pivotIndex = left + count ;
    swap(a, n , left, pivotIndex);
    int i = left;
    int j = right ;
    while(i< pivotIndex && j >pivotIndex ){
        while(a[i]<a[pivotIndex]){
            i++;
        }
        while(a[j]>a[pivotIndex]){
            j--;
        }
        if(i<pivotIndex&&j>pivotIndex){
            swap(a, n , i, j);

        }
    }
    return pivotIndex;

}
void quickSort(int a[], int n ,int left, int right ){
    if(left>=right){
        return ;
    }
    int pivot = partition(a, n, left, right);
    quickSort(a, n , left, pivot-1);
    quickSort(a, n , pivot+1, right);
}
int main()
{
    int n;
    printf("nhap so luong phan tu mang: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        printf("a[%i]: ", i);
        scanf("%d", &a[i]);
    }
    printf("before: ");
    for(int i = 0; i< n; i++){
        printf("%d ", a[i]);
    }

    quickSort(a, n, 0 , n-1);
    printf("after: ");
    for(int i = 0; i< n; i++){
        printf("%d ", a[i]);
    }
}

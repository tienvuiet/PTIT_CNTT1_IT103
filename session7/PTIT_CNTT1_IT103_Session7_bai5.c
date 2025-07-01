#include<stdio.h>
void swap(int a[], int n, int x, int y){
    int temp = a[x];
    a[x]=a[y];
    a[y]=temp;
}
int partition(int a[], int n, int left, int right){
    //gia tri pivot bang gia tri phan tu dau tien
    int pivot = a[left];
    int count = 0 ;
    //dem so luong phan tu nam ben trai pivot
    for(int i =left+1; i<=right; i++){
        if(a[i]<=pivot){
            count++;
        }
    }
    //lay vi tri cho gia tri pivot
    int pivotIndex = left+count;
    //hoa vi 
    swap(a, n, left, pivotIndex);
    int i = left;
    int j = right;
    //doi cho phan tu ben trai lon hon pivot va phan tu ben phai be hon pivot
    while(i<pivotIndex&&j>pivotIndex){
        while (a[i]<pivot)
        {
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<pivotIndex&&j>pivotIndex){
            swap(a, n, i, j);
        }
        
    }
    return pivotIndex;
}
void quickSort(int a[], int n , int left, int right){
    if(left>=right){
        return ;
    }
    //chia
    int pivot = partition(a, n, left, right);
    //tri
    //xap xep day ben trai
    quickSort(a, n , left, pivot-1);
    //xap xep day ben phai
    quickSort(a, n, pivot+1, right);

}
int main (){
    int n ;
    printf("nhap so luong phan tu mang: \n");
    scanf("%d", &n);
    int a[n];
    for(int i =0 ; i< n ; i++){
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("before: \n");
    for(int i =0; i< n ; i++){
        printf("%d ", a[i]);
    }
    quickSort(a, n, 0, n-1);
    printf("\nafter: \n");
    for(int i =0; i< n ; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
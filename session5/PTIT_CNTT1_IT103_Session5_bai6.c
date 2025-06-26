#include <stdio.h>
int tongMang(int arr[], int size)
{
     
    if(size<=0){
        return 0;
    }
    return arr[size-1]+tongMang(arr,size-1);
}
int main()
{
    int n;
    printf("nhap so luong phan tu mang: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int ketQua = tongMang(arr,n);
    printf("tong cac phan tu cua mang la: %d", ketQua);
    return 0;
}
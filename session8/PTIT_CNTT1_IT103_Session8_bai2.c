#include <stdio.h>
void xapXep(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int  timKiemNhiPhan(int a[], int n , int search){
    int left = 0 ; 
    int right = n-1;
    // int found= -1;
    while(left<= right){
        int mid = (right+ left)/2;
        if(a[mid]==search){
            return mid+1;
        }else if(a[mid]<search){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return 0 ;
}
int main()
{
    int n;
    printf("nhap so luong phan tu mang: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("before: \n");
    for(int i =0 ;i< n; i++){
        printf("%d ", a[i]);
    }

    xapXep(a, n);
    printf("\nafter: \n");
    for(int i =0 ;i< n; i++){
        printf("%d ", a[i]);
    }
    int search;
    printf("\nnhap vao phan tu muon tim: ");
    scanf("%d", &search);
    int ketQua = timKiemNhiPhan(a, n, search);
    if(ketQua){
        printf("phan tu duoc tim thay o vi tri: %d", ketQua);
    }else{
        printf("khong tim thay phan tu trong mang");
    }
    return 0;

}
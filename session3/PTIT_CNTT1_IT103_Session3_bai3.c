#include <stdio.h>
#include <stdlib.h>

float trungBinhCong(int *arr, int n)
{
    int sum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            sum += arr[i];
            count++;
        }
    }
    return count > 0 ? (float)sum / count : 0;
}

int main()
{
    int n;
    printf("nhap so luong phan tu mang: \n");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("gia tri khong hop le!!");
        return 1;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    float ketQua = trungBinhCong(arr, n);
    if(ketQua ==0||!trungBinhCong(arr, n)){
        printf("mang khong co so chan");
    }else{
        printf("trung binh cong cua mang la: %.2f",ketQua);
    }
    free(arr);
    return 0;
}
#include <stdio.h>
int main()
{
    int n;

    printf("nhap vao so luong phan tu mang: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("cac phan tu trong mang vua nhap la: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    int index = 0;
    int min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            index = i;
        }
    }
    printf("\nindex cua so nho nhat dau tien trong mang la: %d",index);
    return 0;
}
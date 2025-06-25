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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("\nmang sau khi xap xep la: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    int target ;
    printf("\nnhap vao gia tri muon tim : ");
    scanf("%d",&target);
    int left = 0;
    int right = n - 1;
    int found = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == target)
        {
            found = mid;
            break;
        }
        else if (a[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if (found != -1)
    {
        printf("phan tu co trong mang");
    }
    else
    {
        printf("phan tu ko co trong mang");
    }
    return 0;
}
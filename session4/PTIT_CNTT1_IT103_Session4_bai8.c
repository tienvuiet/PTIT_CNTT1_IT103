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
    int search;
    int check =0;
    printf("nhap vao gia tri can tim : ");
    scanf("%d", &search);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == search)
        {
            printf("%d, ", i);
            check ++;
        }
    }
    if(check==0){
        printf("phan tu ko co trong mang");
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("nhap vao do dai cua mang: ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("mang ban dau la: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    int search;
    printf("nhap vao so muon kiem tra: \n");
    scanf("%d", &search);
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            tong = a[i] + a[j];
            if (tong == search)
            {
                printf("%d, %d", a[i], a[j]);
            }else{
                tong = 0;
            }
        }
    }
    free(a);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("nhap vao so luong phan tu: ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("mang ban dau la: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    int m;
    printf("\nnhap vao so luong can them vao mang: ");
    scanf("%d", &m);
    a = (int *)realloc(a, (m+n) * sizeof(int));
    for(int i =n; i<n+m; i++){
        printf("a[%d]: ", i);
        scanf("%d",&a[i]);
    }
    printf("cac phan tu cua mang sau khi them la: ");
    for(int i =0; i< n+m; i++){
        printf("%d ", a[i]);
    }
    free(a);
    return 0;
}
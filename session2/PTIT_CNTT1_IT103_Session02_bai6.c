#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("kich thuoc mang: ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]", i);
        scanf("%d", &a[i]);
    }
    printf("mang ban dau: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    int index, value;
    printf("nhap vi tri index muon them: ");
    scanf("%d", &index);
    printf("nhap gia tri can them: ");
    scanf("%d", &value);
    if(index<0||index>n){
        printf("khong hop le");
        free(a);
        return 1;
    }
    a = (int *)realloc(a, (n+1)*sizeof(int ));
    for(int i = n-1; i>=index; i--){
        a[i+1]=a[i];
    }
    a[index]=value;
    n++;
    printf("mang sau khi them la: ");
    for(int i =0; i< n ; i++){
        printf("%d ", a[i]);
    }
    free(a);
    return 0;
}
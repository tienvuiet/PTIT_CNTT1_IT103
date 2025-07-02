#include <stdio.h>

void merge(int a[], int n, int left, int middle, int right)
{
    int lenght_left = middle - left + 1;
    int lenght_right = right - middle;
    int a_left[lenght_left];
    int a_right[lenght_right];
    for (int i = 0; i < lenght_left; i++)
    {
        a_left[i] = a[left + i];
    }
    for (int i = 0; i < lenght_right; i++)
    {
        a_right[i] = a[middle + i + 1];
    }
    int i1 = 0;
    int i2 = 0;
    int k = left;
    while (i1 < lenght_left && i2 < lenght_right)
    {
        if (a_left[i1] <= a_right[i2])
        {
            a[k] = a_left[i1];
            i1++;
        }
        else
        {
            a[k] = a_right[i2];
            i2++;
        }
        k++;
    }
    while(i1<lenght_left){
        a[k]= a_left[i1];
        i1++;
        k++;
    }
    while(i2<lenght_right){
        a[k]= a_right[i2];
        i2++;
        k++;
    }
}

void mergeShort(int a[], int n, int left, int right)
{
    if (left == right)
    {
        return;
    }
    int middle = (left + right) / 2;

    mergeShort(a, n, left, middle);
    mergeShort(a, n, middle + 1, right);
    merge(a, n, left, middle, right);
}
int main()
{
    int n;
    printf("nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("before: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    mergeShort(a, n , 0, n-1);
    printf("\nafter: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

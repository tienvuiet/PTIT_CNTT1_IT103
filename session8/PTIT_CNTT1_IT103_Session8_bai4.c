#include <stdio.h>
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex!=i)
        {
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}
int main()
{
    int n;
    printf("nhap vao so luong: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("before: ");
    for(int i =0 ; i< n ; i++){
        printf("%d ", a[i]);
    }
    selectionSort(a, n);
    printf("after: ");
    for(int i =0 ; i< n ; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
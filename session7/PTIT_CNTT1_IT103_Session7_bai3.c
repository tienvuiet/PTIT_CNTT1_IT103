#include <stdio.h>
void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int key = arr[i]; // phan tu can chen
        int j = i - 1;
        // doi cac phan tu lon key sang ben tay phai
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        // chen key vao dung vi tri
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    // xap xep chen
    printf("before: ");
    for(int i = 0 ; i< n ; i++){
        printf("%d ", arr[i]);
    }
    insertionSort(arr, n);
    printf("\nafter: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
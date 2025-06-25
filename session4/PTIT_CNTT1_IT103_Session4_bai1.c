#include <stdio.h>
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 2};
    int size = sizeof(a) / sizeof(a[0]);
    int index;
    int check = 0;
    int number;
    printf("nhap vao so can tim: ");
    scanf("%d", &number);
    for (int i = 0; i < size; i++)
    {
        if (a[i] == number)
        {
            index = i;
            check = 1;
            break;
        }
    }
    if(check){
        printf("so duoc tim thay o vi tri index = %d",index);
    }else{
        printf("khong ton tai so trong mang");
    }
    return 0;
}
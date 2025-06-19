#include <stdio.h>
#include <stdlib.h>
int *insertToArray(int *arr, int size, int value);
int main()
{
    int choice;
    int *number = NULL;
    do
    {
        printf("menu");
        printf("1.them phan tu");
        printf("2.hien thi mang");
        printf("3.xoa phan tu");
        printf("4.thoat");
        printf("lua chon:");
        switch (choice)
        {
        case 1:
            // numbers= insertToArray(number, $size,1);

            break;
        case 2:
            break;
        case 3:
            break;
        }

    } while (choice != 4);
}

int *insertToArray(int *arr, int *size, int value)
{
    // b1: cap phat lai bo nho cho mang duoc truyen vao
    // arr = (int *)realloc(arr, sizeof(int) * (size + 1));
    // b2: gan lai gia tri cua phan tu cuoi cung cua mang duoc cap phat moi
    arr[*size] = value;
    (*size)++;
    return arr;
    // b3: tra ve mang (con tro) duoc cap phat
}

int *printfArray(int *arr, int size){

}
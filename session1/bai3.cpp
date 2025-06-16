#include<stdlib.h>
int* mallocArray(int n){
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i = 0;i<n;i++){
        arr[i]=i;
    }
    return arr;
}
//sử dụng malloc cấp phát n ô nhớ kiểu int =>O(n)
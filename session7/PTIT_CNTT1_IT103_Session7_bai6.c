#include<stdio.h>
#include<stdlib.h>

void merge(int a[1000], int left,int middle,  int right){
    //ben trai:left-->middle
    int len_left = middle-left+1;
    //so phan tu trai
    int len_right = right-middle;
    //so phan tu phai
    //tao mang tam thoi
    int a_left[len_left];
    int a_right[len_right]; 
    //ben phai:middle+1-->right
    
    for(int i = 0 ; i< len_left; i++){
        a_left[i] = a[left+i];
    }

    for(int i = 0 ; i< len_right; i++){
        a_right[i] = a[middle+i+1];
    }
    //gop hai mang theo quy tac phan tu nho hon duoc dua vao mang gopp truoc
    int i1 = 0 ;//vi tri hien tai cua phan tu mang ben trai

    int i2 = 0;// vi tri hien tai cua mang ben phai
    int k = left;

    while(i1<len_left && i2< len_right){
        if(a_left[i1]<= a_right[i2]){
            a[k] = a_left[i1];
            i1++;
        }else{
            a[k] = a_right[i2];
            i2++;
        }
        k++;
    }
    //copy nhung phan tu cua mang ben trai chua duoc bo vao
    while(i1<len_left){
        a[k]= a_left[i1];
        i1++;
        k++;
    }
    //copy nhung phan tu cua mang ben phai chua duoc bo vao
    while(i2<len_right){
        a[k]= a_right[i2];
        i2++;
        k++;
    }


}

void mergeSort(int a[1000], int left, int right){
    if(left<right){
        //tim vi tri o giua
        int middle = (left+right)/2;

        //goi de quy sort tung phan ben trai va ben phai
        mergeSort(a, left, middle);
        mergeSort(a, middle+1, right);

        //gop hai phan ben trai va ben phai lai
        merge(a, left, middle,right);

    }
}

int main (){
    int n ; 
    int  a[1000];
    printf("nhap vao n: ");
    scanf("%d", &n);
    for(int i =0 ; i< n ; i++){
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    mergeSort(a, 0, n-1);
    for(int i = 0 ; i< n; i++){
        printf("%d ", a[i]);
    }
}
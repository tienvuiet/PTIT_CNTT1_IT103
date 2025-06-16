#include<stdio.h>
int main(){
    int arr[]={62,23,12,32,12,23};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i =0; i<n-1; i++){
        int minIndex = i;   
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex]=arr[i];
        arr[i]=temp;
    }
    for(int i =0;i<n; i++){
        printf("%d ",arr[i]);
    }
}
//độ phức tạp là O(n^2) vì nó có 2 vòng for lồng nhau n*(n+1)=n^2+n mà khi n lớn lớn thì nó sẽ còn n^2
#include <stdio.h>
int binarySearch(int arr[], int low, int high, int key)
{   

    //dieu kien dung khi khong tim thay
    if(low>high){
        return -1;
    }
    //dieu kien dung khi khong tim thay

    int mid = (low+high)/2;
    if(arr[mid]==key){
        return mid;
    }
    if(key<arr[mid]){
        //bai toan o nua dau
        binarySearch(arr,low,mid-1, key);
    }else{
        //bai toan o nua sau
        binarySearch(arr, mid+1,high,key);
    }
}
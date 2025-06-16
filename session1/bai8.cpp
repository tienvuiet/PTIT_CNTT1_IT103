#include<stdio.h>
int main(){
    int arr[]= {1,2,3,4,5,6,7,8,9,1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxCount = 0;
    int maxNumber;
    for(int i =0; i<n ; i++){
        int count =0;
        for(int j = 0; j<n ; j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count > maxCount){
            maxCount = count ;
            maxNumber =arr[i];
        }
    }
    printf("phan tu xuat hien nhieu nhat la: %d", maxNumber);
}
//vòng for i thì chạy n lan 
//vòng for moi n i thi n j lan len la n*n=>n^2
//do phuc tap O(n^2)
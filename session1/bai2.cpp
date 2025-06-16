#include<stdio.h>
void printDouble(int n);
int main (){
    printDouble(6);
    return 0;
}
void printDouble(int n){
    int i =1;
    while(i<n){
        printf("%d\n",i);
        i*=2;
    }
}
//do phuc tap la O(logn) vì
//kết thúc thì i>=n mà i = 2^k =>2^k>=n 
//k>=log2n; =>O(log2n);
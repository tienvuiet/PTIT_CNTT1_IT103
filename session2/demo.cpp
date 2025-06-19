//cap phat dong
#include<stdio.h>
#include<stdlib.h>
int main(){
    int numbers[5];
    int *numbers =(int*) malloc(5*sizeof(int ));
    //2 cái dưới và trên như nhau 
    int numeber2[10]={0};
    int *number2 = (int*) calloc(10,sizeof(int));
    //
    int *number3 = (int*) realloc(number3,10*sizeof(int));
    return 0;
}
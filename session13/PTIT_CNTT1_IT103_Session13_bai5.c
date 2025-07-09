#include<stdio.h>
#include<stdlib.h>
typedef struct Stack{
    int *arr;
    int top;
    int cap;
}Stack;
Stack* createStack(int cap){
    Stack *newStack = (Stack*)malloc(sizeof(Stack));
    newStack->top = -1;
    newStack->cap = cap;
    newStack->arr = (int *)malloc(sizeof(int)*cap);
    return newStack;
}
int isFull(Stack* stack){
    if(stack->top==stack->cap-1){
        return 1;
    }
    return 0;
}
int push(Stack *stack, int val){ 
    if(isFull(stack)){
        printf("stack overflow");
        return 0;
    }
    stack->top = stack->top+1;
    return stack->arr[stack->top] = val;
    return 1;
}
int isEmpty(Stack *stack){
    if(stack->top==-1){
        return 1;
    }
    return 0;
}
int pop(Stack *stack){
    if(isEmpty(stack)){
        printf("stack underflow");
        return 0;
    }   
    stack->top = stack->top-1;
    return stack->arr[stack->top+1];
}
int main (){
    int n;
    printf("nhap so luong phan tu mang: ");
    scanf("%d", &n);
    int a[n];
    for(int i = 0;i< n ; i++){
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("before: ");
    for(int i = 0;i< n ; i++){
        printf("%d ", a[i]);
    }
    Stack* stack = createStack(n);
    for(int i =0 ; i<n ; i++){
        push(stack, a[i]);
    }
    printf("after: ");
    while(!isEmpty(stack)){
        printf("%d ", pop(stack));
    }
    return 0;


}
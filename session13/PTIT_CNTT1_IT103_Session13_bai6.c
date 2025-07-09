#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack
{
    int *arr;
    int top;
    int cap;
} Stack;
Stack *createStack(int cap)
{
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    newStack->top = -1;
    newStack->cap = cap;
    newStack->arr = (int *)malloc(sizeof(int) * cap);
    return newStack;
}
int isFull(Stack *stack)
{
    if (stack->top == stack->cap - 1)
    {
        return 1;
    }
    return 0;
}
int push(Stack *stack, int val)
{
    if (isFull(stack))
    {
        printf("stack overflow");
        return 0;
    }
    stack->top = stack->top + 1;
    stack->arr[stack->top] = val;
    return 1;
}
int isEmpty(Stack *stack)
{
    if (stack->top == -1)
    {
        return 1;
    }
    return 0;
}
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("stack underflow");
        return 0;
    }
    stack->top = stack->top - 1;
    return stack->arr[stack->top + 1];
}
int doiXung(char *str){
    int len = strlen(str);
    Stack *stack = createStack(len);
    for(int i = 0; i< len/2; i++){
        push(stack, str[i]);
    }
    int start = (len%2==0)?len/2:len/2+1;
    for(int i = start; i<len; i++){
        if(pop(stack)!= str[i]){
            return 0 ;
        }
    }
    return 1;
}
int main()
{
    char str[100];
    printf("nhap vao chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    if(doiXung(str)){
        printf("true");
    }else{
        printf("false");
    }
    return 0;
}
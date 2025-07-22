#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct GraphicAction {
    char Action[100];
    char TimeStamp[100];
}GraphicAction;
typedef struct Stack {
    GraphicAction *data;
    int top;
    int cap;
}Stack;
Stack *createStack(int cap) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->cap = cap;
    s->top = -1;
    s->data = (GraphicAction *)malloc(sizeof(GraphicAction) * cap);
    return s;
}
int isFull(Stack *stack) {
    if (stack->top == stack->cap-1) {
        return 1;
    }
    return 0;
}
int isEmpty(Stack *stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}

int push (Stack *stack, GraphicAction ga) {
    if (isFull(stack)) {
        printf("stack is full\n");
        return 0;
    }
    stack->top = stack->top + 1;
    stack->data[stack->top] = ga;
    return 1;
}
GraphicAction pop(Stack *stack) {
    GraphicAction empty = {"", ""};
    if (isEmpty(stack)) {
        printf("stack is empty\n");
        return empty;
    }
    GraphicAction ga = stack->data[stack->top];
    stack->top = stack->top - 1;
    return ga;
}
int main(void) {
    Stack *undo = createStack(100);
    Stack *redo = createStack(100);
    int choice;
    do {
        printf("Menu\n");
        printf("1.DRAW\n");
        printf("2.UNDO\n");
        printf("3.REDO\n");
        printf("4.PRINT\n");
        printf("5.EXIT\n");
        printf("CHOICE: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                GraphicAction ga;
                getchar();
                printf("Ve: ");
                fgets(ga.Action,100,stdin);
                ga.Action[strcspn(ga.Action, "\n")] = '\0';
                printf("Thoi gian (dd/mm/yyyy: ");
                fgets(ga.TimeStamp,100,stdin);
                ga.TimeStamp[strcspn(ga.TimeStamp, "\n")] = '\0';
                push(undo,ga);
                redo->top = -1;
                break;
            case 2:
                if(isEmpty(undo)) {
                    printf("khong co hanh dong de hoan tac\n");
                }else {
                    GraphicAction ga = pop(undo);
                    push(redo,ga);
                    printf("Undone: %s trong thoi gian %s\n ", ga.Action, ga.TimeStamp);

                }
                break;
            case 3:
                if(isEmpty(redo)) {
                    printf("khong co hanh dong de hoan tac\n");
                }else {
                    GraphicAction ga = pop(redo);
                    push(undo,ga);
                    printf("Undone: %s trong thoi gian %s\n", ga.Action, ga.TimeStamp);

                }
                break;
            case 4:
                if (isEmpty(undo)) {
                    printf("khong co hanh dong de in\n");
                }else {
                    printf("Tat ca hanh dong: \n");
                    for (int i = 0 ; i<= undo->top ; i++) {
                        printf("%s trong thoi gian %s\n", undo->data[i].Action , undo->data[i].TimeStamp);
                    }
                }
                break;
            case 5:
                printf("da thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le");

        }
    }while(choice != 5);

    return 0;
} 
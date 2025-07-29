#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Operation
{
    char action;
    char value;
} Operation;
typedef struct Stack
{
    Operation *data;
    int top;
    int cap;
} Stack;
Stack *createStack(int cap)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->cap = cap;
    s->top = -1;
    s->data = (Operation *)malloc(sizeof(Operation) * cap);
    return s;
}
int isFull(Stack *s)
{
    if (s->top == s->cap - 1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}
int push(Stack *s, Operation o)
{
    if (isFull(s))
    {
        return 0;
    }
    s->top++;
    s->data[s->top] = o;
    return 1;
}
Operation pop(Stack *s)
{
    Operation empty = {'\0', '\0'};
    if (isEmpty(s))
    {
        return empty;
    }
    return s->data[s->top--];
}
int main()
{
    Stack *undo = createStack(100);
    Stack *redo = createStack(100);
    char text[1000] = "";
    int choice;
    do
    {
        printf("\nMENU\n");
        printf("1.INSERT x\n");
        printf("2.UNDO\n");
        printf("3.REDO\n");
        printf("4.HIEN THI\n");
        printf("5.THOAT\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {

        case 1:
        {
            char ch;
            printf("Nhap ki tu muon them: ");
            scanf("%c", &ch);
            getchar();
            int len = strlen(text);
            text[len] = ch;
            text[len + 1] = '\0';
            Operation op = {'I', ch};
            push(undo, op);
            redo->top = -1;
            break;
        }

        case 2:
        {
            if (isEmpty(undo))
            {
                printf("khong co thao tac nao de undo\n");
            }
            else
            {
                Operation op = pop(undo);
                if (op.action == 'I')
                {
                    int len = strlen(text);
                    if (len > 0)
                    {
                        text[len - 1] = '\0';
                        push(redo, op);
                    }
                }
            }
            break;
        }
        case 3:
        {
            if (isEmpty(redo))
            {
                printf("khong co thao tac nao de redo");
            }
            else
            {
                Operation op = pop(redo);
                if (op.action == 'I')
                {
                    int len = strlen(text);
                    text[len] = op.value;
                    text[len + 1] = '\0';
                    push(undo, op);
                }
            }
            break;
        }
        case 4:
            printf("Van ban hien tai: %s\n", text);
            break;
        case 5:
            printf("Da thoat chuong trinh");
            break;
        default:
            printf("Lua chon khong hop le\n");
        }
    } while (choice != 5);
    return 0;
}
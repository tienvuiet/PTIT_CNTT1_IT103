#include <stdio.h>
#include <string.h>
#include <ctype.h>
void sapXep(char *str)
{
    int size = strlen(str);
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (str[i] > str[j])
            {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}
int main (){
    char str[100];
    printf("nhap chuoi:");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str,"\n")]=0;
    printf("before: %s\n", str);
    sapXep(str);
    printf("\nafter: %s\n", str);
    return 0;
    
}
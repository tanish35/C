#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char *a = "34";
    char *b = "56";
    int num1 = atoi(a);
    int num2 = atoi(b);
    int num = num1 + num2;
    char *str;
    sprintf(str, "%d", num);
    printf("%s", str);
}
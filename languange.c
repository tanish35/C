#include <stdio.h>
#include <string.h>
int main(void)
{
    char *str = "Hello world";
    printf("%c", str[strlen(str) - 1]);
}
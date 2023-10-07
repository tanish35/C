#include <stdio.h>

int main(void)
{
    int a = 1;
    int *ptr = &a;
    a = 2;
    *ptr += 2;
    printf("%d", a);
}
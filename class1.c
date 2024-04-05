#include <stdio.h>
#include <stdlib.h>

int main()
{
    // int a;
    // a = (5, 3);
    // int b = (6, 4);
    // printf("%d\n", a + b);

    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", a > b ? a > c ? a : c : b > c ? b
                                                 : c);
}
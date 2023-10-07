#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int values[] = {1, 1, 1, 1, 1, 44, 7, 7, 7, 7, 7, 7, 7, 7};
    int size = sizeof(values) / sizeof(values[0]);
    int e = 3;
    int d = 0;
    for (int i = 0; i < size; i++)
    {
        if (e != abs(values[i] % 2))
        {
            // printf("%d\n", values[i]);
            // printf("%d&&\n", values[i] % 2);
            d++;
        }
        e = abs(values[i] % 2);
        if (d == 3)
        {
            printf("%d\n", values[i - 1]);
            break;
        }
    }
    if (d == 2)
    {
        if (values[0] % 2 != values[1] % 2)
        {
            printf("%d\n", values[0]);
        }
        else
        {
            printf("%d\n", values[size - 1]);
        }
    }
}
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[20];
    int start = 4;
    int end = 17;
    int c = 0;
    // sprintf(str, "%d", start);
    // printf("%s\n", str);
    for (int i = start; i <= end; i++)
    {
        sprintf(str, "%d", i);
        if (strchr(str, '5') == NULL)
        {
            c++;
            // printf("%s\n", str);
        }
    }
    printf("%d\n", c);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// int main(void)
// {
//     int n = 5634;
//     if (n / 10.00 == n / 10)
//     {
//         printf("%f", n / 10);
//     }
//     else
//     {
//         printf("%f", n / 10.00);
//     }
// }

// int main(void)
// {
//     char *source = "RqaEzty";
//     int n = strlen(source);
//     int c = 0;
//     n = (n * n + 3 * n - 2) / 2;
//     char *string = malloc(n + 1);
//     for (int i = 0; i < strlen(source); i++)
//     {
//         for (int j = 0; j <= i; j++)
//         {
//             if (j == 0)
//             {
//                 if (source[i] >= 'a' && source[i] <= 'z')
//                 {
//                     string[c] = source[i] - ('a' - 'A');
//                     // char temp[2] = {source[i] - ('a' - 'A'), '\0'};
//                     // strcat(string, temp);
//                 }
//                 else
//                 {
//                     string[c] = source[i];
//                     // char temp[2] = {source[i], '\0'};
//                     // strcat(string, temp);
//                 }
//             }
//             else
//             {
//                 if (source[i] >= 'A' && source[i] <= 'Z')
//                 {
//                     string[c] = source[i] + ('a' - 'A');
//                     // char temp[2] = {source[i] + ('a' - 'A'), '\0'};
//                     // strcat(string, temp);
//                 }
//                 else
//                 {
//                     string[c] = source[i];
//                     // char temp[2] = {source[i], '\0'};
//                     // strcat(string, temp);
//                 }
//             }
//             c++;
//         }
//         string[c] = '-';
//         c++;
//     }
//     string[c - 1] = '\0';
//     printf("%s", string);
// }

// int main(void)
// {
//     const char *h = "Hello world";
//     char *i = malloc(strlen(h) + 1);
//     strcpy(i, h);
//     i[1] = 'o';
//     printf("%s", i);
// }

int main(void)
{
    const char *IPv4 = "128.32.10.1";
    int a[4] = {0, 0, 0, 0};
    int c = 0;
    for (int i = 0; i < strlen(IPv4); i++)
    {
        if (IPv4[i] != '.')
        {
            a[c] = a[c] * 10 + IPv4[i] - '0';
        }
        else
        {
            c++;
        }
    }
    c = 0;
    long b[4] = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++)
    {
        int c = 1;
        while (a[i] != 0)
        {
            b[i] = b[i] + (a[i] % 2) * c;
            c = c * 10;
            a[i] = a[i] / 2;
        }
    }
    long c = 1;
    long n = 0;
    for (int i = 3; i > 0; i--)
    {
        while (b[i] != 0)
        {
            n += (b[i] % 10) * c;
            c = c * 10;
            b[i] = b[i] / 10;
            printf("%d\n", b[i]);
            printf("%d\n", n);
        }
        for(int i=0)
    }
    printf("%d", n);
}
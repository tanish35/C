#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const unsigned char sequence[5][16] = {
    {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31},
    {2, 3, 6, 7, 10, 11, 14, 15, 18, 19, 22, 23, 26, 27, 30, 31},
    {4, 5, 6, 7, 12, 13, 14, 15, 20, 21, 22, 23, 28, 29, 30, 31},
    {8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 26, 27, 28, 29, 30, 31},
    {16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31}};

// int main()
// {
//     const unsigned char answers[5] = {1, 1, 1, 0, 0};
//     int result = 0;
//     for (int i = 0; i < 5; i++)
//     {
//         result += sequence[i][0] * answers[i];
//     }
//     printf("The number is %d\n", result);
// }

int main()
{
    unsigned char n = 1;
    unsigned char answers[5];
    for (int i = 4; i >= 0; i--)
    {
        answers[i] = n % 2;
        n = n / 2;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d", answers[i]);
    }
}
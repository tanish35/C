#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[] = "Welcome to the CSE Department of IIT Kharagpur";
    char result[100] = "";
    char *copy = strdup(str);
    char *token = strtok(copy, " ");
    // printf("%s\n", token);
    while (token != NULL)
    {
        int x = strlen(token);
        if (x >= 5)
        {
            char *temp = malloc(sizeof(char) * x + 2);
            for (int i = 0; i < x; i++)
            {
                temp[i] = token[x - i - 1];
            }
            temp[x] = ' ';
            temp[x + 1] = '\0';
            strcat(result, temp);
        }
        else
        {
            strcat(result, token);
            strcat(result, " ");
        }
        token = strtok(NULL, " ");
    }
    printf("%s\n", result);
    return 0;
}
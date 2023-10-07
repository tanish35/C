#include <stdio.h>
#include <string.h>
int main(void)
{
    char *str_in = "how are you today?";
    char *str_out = '\0';
    int n = strlen(str_in);
    for (int i = 0; i < n; i++)
    {
        if (strchr("aeiou", str_in[i]) == NULL)
        {
            printf("%c", str_in[i]);
            *str_out = str_in[i] + *str_out;
        }
    }
    printf("%s", str_out);
}
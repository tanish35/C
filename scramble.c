#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *str1 = "scriptjavx";
    char *str2 = "javascript";
    int map[26] = {0};
    for (int i = 0; i < strlen(str1); i++)
    {
        map[str1[i] - 'a']++;
    }
    for (int i = 0; i < strlen(str2); i++)
    {
        if (map[str2[i] - 'a'] != 0)
        {
            map[str2[i] - 'a']--;
        }
        else
        {
            printf("false\n");
            return 0;
        }
    }
    printf("true\n");
}
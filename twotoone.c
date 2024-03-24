#include <stdio.h>
#include <string.h>
int main()
{
    char *s1 = "xyaabbbccccdefww";
    char *s2 = "xxxxyyyyabklmopq";
    char s3[27];
    int arr[26] = {0};
    for (int i = 0; i < strlen(s1); i++)
    {
        arr[s1[i] - 'a']++;
    }
    for (int i = 0; i < strlen(s2); i++)
    {
        arr[s2[i] - 'a']++;
    }
    int j = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > 0)
        {
            s3[j] = i + 'a';
            j++;
        }
    }
    s3[j] = '\0';
    printf("%s", s3);
}

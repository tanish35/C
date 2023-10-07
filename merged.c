#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    const char *s = "codewars";
    const char *part1 = "cdw";
    const char *part2 = "oears";
    int map[26] = {0};
    for (int i = 0; part1[i] != '\0'; i++)
    {
        map[part1[i] - 'a']++;
    }
    for (int i = 0; part2[i] != '\0'; i++)
    {
        map[part2[i] - 'a']++;
    }
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (map[s[i] - 'a'] != 0)
        {
            map[s[i] - 'a']--;
        }
        else
        {
            printf("false");
            return 0;
        }
    }
    printf("true");
}
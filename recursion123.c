#include <stdio.h>
void recur(int cur, char s[3])
{
    if (cur == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            printf("%d", s[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= 5; i++)
    {
        s[cur] = i;
        recur(cur + 1, s);
    }
}

int main()
{
    char s[3];
    recur(0, s);
    return 0;
}
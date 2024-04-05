#include <iostream>
using namespace std;
int main()
{
    int n = 1;
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        int i = 1, e = 4, u = 1;
        cin >> i >> e >> u;
        int c = 0;
        c = c + i;
        c = c + (e / 3);
        int r = e % 3;
        if (r > 0)
        {
            c = c + 1;
            u = u - (3 - r);
        }

        if (u % 3 == 0)
        {
            c = c + (u / 3);
        }
        else
        {
            c = c + (u / 3) + 1;
        }
        if (u < 0)
        {
            c = -1;
        }
        cout << c << endl;
    }
}
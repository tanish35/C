#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n = 23;
    int p = ceil(n / 2.0);
    int q = n - p;
    int k = 1;
    while (k <= n)
    {
        for (int i = 0; i < p && k <= n; i++)
        {
            cout << k << " ";
            k++;
        }
        cout << endl;
        p = ceil(q / 2.0);
        q = q - p;
    }
}
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int del[a];
        for (int i = 0; i < a; i++)
        {
            cin >> del[i];
        }
        int pl[b];
        for (int i = 0; i < b; i++)
        {
            cin >> pl[i];
        }
        for (int i = 0; i < b; i++)
        {
            if (pl[i] < del[0])
            {
                cout << pl[i] << " ";
            }
            else
            {
                cout << del[0] - 1 << " ";
            }
        }
        cout << endl;
    }
}
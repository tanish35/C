#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a1, b1;
        cin >> a1 >> b1;
        if (a1 < b1)
        {
            swap(a1, b1);
        }
        bool yes = false;
        for (int i = 0; i < a1.size(); i++)
        {
            if (a1[i] > b1[i] && yes)
            {
                swap(a1[i], b1[i]);
            }
            if (a1[i] != b1[i])
            {
                yes = true;
            }
        }
        cout << a1 << endl;
        cout << b1 << endl;
    }
}
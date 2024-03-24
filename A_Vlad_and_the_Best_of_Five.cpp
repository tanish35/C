#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int a = 0, b = 0;
        for (int j = 0; j < 5; j++)
        {
            if (s[j] == 'A')
                a++;
            else
                b++;
        }
        if (a > b)
            cout << "A" << endl;
        else if (b > a)
            cout << "B" << endl;
    }
}
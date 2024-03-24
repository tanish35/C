#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a = 0, b = 0, c = 0;
        for (int k = 0; k < 3; k++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < s.length(); j++)
            {
                if (s[j] == 'A')
                {
                    a++;
                }
                else if (s[j] == 'B')
                {
                    b++;
                }
                else if (s[j] == 'C')
                {
                    c++;
                }
            }
        }
        if (a < 3)
        {
            cout << "A" << endl;
        }
        else if (b < 3)
        {
            cout << "B" << endl;
        }
        else if (c < 3)
        {
            cout << "C" << endl;
        }
    }
}

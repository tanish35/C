#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string p;
    for (int i = 0; i < n; i++)
    {
        int one = 0;
        int x;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            string s;
            cin >> s;
            int one1 = 0;
            for (int k = 0; k < s.length(); k++)
            {
                if (s[k] == '1')
                {
                    one1++;
                }
            }
            if (one1 == one && one != 0)
            {
                p = "SQUARE";
            }
            else if (one1 != one && one != 0 && one1 != 0)
            {
                p = "TRIANGLE";
            }
            else
            {
                one = one1;
            }
        }
        cout << p << endl;
    }
}
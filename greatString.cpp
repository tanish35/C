#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s = "pP";
    if (s == "")
    {
        cout << "Empty string" << endl;
        return 0;
    }
    string::iterator p1 = s.begin();
    string::iterator p2 = s.begin() + 1;
    while (p2 != s.end())
    {
        if (char(*p1 - 32) == *p2 || char(*p1 + 32) == *p2)
        {
            s.erase(p1, p2 + 1);
            if (p1 != s.begin())
            {
                p1--;
                p2--;
            }
            else
            {
                p1 = s.begin();
                p2 = s.begin() + 1;
            }
        }
        else
        {
            p1++;
            p2++;
        }

        if (s == "")
        {
            cout << "Empty string" << endl;
            return 0;
        }
    }
    cout << s << endl;
}

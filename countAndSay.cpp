#include <iostream>
#include <string>
using namespace std;
string countAndSay(int n)
{
    if (n == 1)
        return "1";
    if (n > 1)
    {
        string s = countAndSay(n - 1);
        string res = "";
        int c = 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == s[i + 1])
                c++;
            else
            {
                res += to_string(c) + s[i];
                c = 1;
            }
        }
        return res;
    }
}
int main()
{
    int n;
    cin >> n;
    cout << countAndSay(n) << endl;
    return 0;
}
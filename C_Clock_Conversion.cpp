#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int h = stoi(s.substr(0, 2));
        int m = stoi(s.substr(3, 2));
        string arr[2] = {"AM", "PM"};
        int t = 0;
        if (h >= 12)
        {
            h = h - 12;
            t = 1;
        }
        if (h == 0)
        {
            h = 12;
        }
        if (h > 0 && h < 10)
        {
            cout << "0";
        }
        cout << h << ":";
        if (m >= 0 && m < 10)
        {
            cout << "0";
        }
        cout << m << " " << arr[t] << endl;
    }
}
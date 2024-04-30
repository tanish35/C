#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        unordered_set<int> s;
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            if (s.find(a[i]) == s.end())
                s.insert(a[i]);
            else
                c++;
        }
        cout << c << endl;
    }
}
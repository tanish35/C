#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int case_num = 1; case_num <= t; case_num++)
    {
        long long n, c, d;
        cin >> n >> c >> d;
        vector<long long> v(n * n);
        multiset<long long> s;

        for (int i = 0; i < n * n; i++)
        {
            cin >> v[i];
            s.insert(v[i]);
        }
        sort(v.begin(), v.end());

        long long ct = 0, pt = 0;
        vector<long long> u;

        while (ct < n)
        {
            long long qt = *s.begin();
            u.push_back(qt);
            for (int j = 0; j < n; j++)
            {
                auto it = s.find(qt);
                if (it == s.end())
                {
                    pt = 1;
                    break;
                }
                else
                {
                    s.erase(it);
                    qt += c;
                }
            }
            if (pt)
            {
                break;
            }
            ct++;
        }

        for (int i = 0; i < u.size() - 1; i++)
        {
            if (u[i + 1] - u[i] != d)
            {
                pt = 1;
                break;
            }
        }

        if (pt)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}

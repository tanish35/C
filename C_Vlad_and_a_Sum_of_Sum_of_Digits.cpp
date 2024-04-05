#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long> a;
    for (int i = 0; i < n; i++)
    {
        long long k;
        cin >> k;
        if (k < a.size())
        {
            cout << a[k] << endl;
        }
        else
        {
            long long sum = 0;
            if (a.size() != 0)
            {
                sum = a[a.size() - 1];
            }
            for (int j = a.size(); j <= k; j++)
            {
                long long temp = j;
                while (temp > 0)
                {
                    sum += temp % 10;
                    temp /= 10;
                }
                a.push_back(sum);
            }
            cout << a[k] << endl;
        }
        }
}
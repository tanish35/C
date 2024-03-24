#include <iostream>
#include <vector>
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

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            int element;
            cin >> element;

            // Flip the sign of the element if the index is odd
            if (i % 2 == 1)
            {
                element = -element;
            }

            a[i] = element;
        }

        unordered_set<int> prefixSums;
        int currentSum = 0;
        prefixSums.insert(0);

        for (int i = 0; i < n; ++i)
        {
            currentSum += a[i];

            if (prefixSums.count(currentSum))
            {
                cout << "YES\n";
                goto end_of_while;
            }

            prefixSums.insert(currentSum);
        }

        cout << "NO\n";

    end_of_while:
        continue;
    }

    return 0;
}

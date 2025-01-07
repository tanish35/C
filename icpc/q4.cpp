#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T; // Read the number of test cases

    while (T--)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y; // Read a, b, x, and y

        // Check the condition for constructing the triangle
        if (x >= b && y >= b)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }

    return 0;
}

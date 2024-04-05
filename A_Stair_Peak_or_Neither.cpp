// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         if (a < b && b < c)
//         {
//             cout << "STAIR" << endl;
//         }
//         else if (a < b && b > c)
//         {
//             cout << "PEAK" << endl;
//         }
//         else
//         {
//             cout << "NONE" << endl;
//         }
//     }
// }

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < b)
        {

            if (b < c)
            {
                cout << "STAIR" << endl;
            }
            else if (b > c)
            {
                cout << "PEAK" << endl;
            }
            else if (b == c)
            {
                cout << "NONE" << endl;
            }
        }
        else
        {
            cout << "NONE" << endl;
        }
    }

    return 0;
}
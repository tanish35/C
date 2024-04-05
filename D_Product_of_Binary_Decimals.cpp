#include <iostream>
using namespace std;
// int isBinary(int n)
// {
//     while (n != 0)
//     {
//         if (n == 1 || n == 0)
//         {
//             return 1;
//         }
//         int digit = n % 10;
//         if (digit != 0 && digit != 1)
//         {
//             return 0;
//         }
//         n /= 10;
//     }
//     return 1;
// }
// int main()
// {
//     int n = 1;
//     // cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int a = 1221;
//         // cin >> a;
//         int t = isBinary(a);
//         int k = 0;
//         if (t == 0)
//         {
//             while (a % 2 == 0)
//             {
//                 a /= 2;
//             }
//             for (int i = 3; i * i <= a; i += 2)
//             {
//                 cout << i << endl;
//                 if (a % i == 0)
//                 {
//                     if (isBinary(i) == 0)
//                     {
//                         break;
//                     }
//                 }
//                 while (a % i == 0)
//                 {

//                     a /= i;
//                 }
//             }
//             if (a > 2)
//             {
//                 if (isBinary(a) == 0)
//                 {
//                     k = 0;
//                 }
//                 else
//                 {
//                     k = 1;
//                 }
//             }
//             else
//             {
//                 k = 1;
//             }
//         }
//         cout << k << endl;
//         if (t == 1 || k == 1)
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }
// }

int arr[30] = {10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10000, 10001, 10010, 10011, 10100, 10101, 10110, 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111};

bool check(int n)
{
    if (n == 1)
    {
        return true;
    }
    bool ans = false;
    for (int i = 0; i < 30; i++)
    {
        if (n % arr[i] == 0)
        {
            ans = check(n / arr[i]);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (check(a))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
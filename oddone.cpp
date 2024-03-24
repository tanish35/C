#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int arr[3];
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[j];
        }
        if (arr[1] == arr[0])
        {
            cout << arr[2] << endl;
        }
        else if (arr[1] == arr[2])
        {
            cout << arr[0] << endl;
        }
        else
        {
            cout << arr[1] << endl;
        }
    }
}
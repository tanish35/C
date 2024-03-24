#include <iostream>
using namespace std;
int main()
{
    int arr[] = {};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == target)
        {
            cout << mid << endl;
            return 0;
        }
        if (arr[s] <= arr[mid])
        {
            if (target >= arr[s] && target <= arr[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else
        {
            if (target >= arr[mid] && target <= arr[e])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    cout << -1 << endl;
    ;
}
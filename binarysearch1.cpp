// the code of binary search
#include <iostream>
#include <conio.h>
using namespace std;

int binary_search(int arr[], int size, int target);

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int size = 9;
    int target = 80;

    int ansI = binary_search(arr, size, target);
    if (ansI == -1)
    {
        cout << "target not found";
    }
    else
    {
        cout << "target found at index [" << ansI << "]";
    }
    return 0;
}

int binary_search(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else // arr[mid] > target
        {
            end = mid - 1;
        }
    }
    return -1;

    getch();
}

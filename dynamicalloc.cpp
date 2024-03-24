#include <iostream>
using namespace std;
int main()
{
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;
    int *p = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    cout << "The elements of the array are: ";
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
}
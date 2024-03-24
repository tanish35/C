#include <iostream>
#include <string>
using namespace std;
int main()
{
    string arr[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int a, b;
    cin >> a;
    cin >> b;
    for (int i = a; i <= b; i++)
    {
        if (i <= 9)
        {
            cout << arr[i - 1] << endl;
        }
        else
        {
            if (i % 2 == 0)
            {
                cout << "even" << endl;
            }
            else
            {
                cout << "odd" << endl;
            }
        }
    }
}
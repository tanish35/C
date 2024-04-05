#include <iostream>
#include <vector>
using namespace std;

void print(int *p)
{
    cout << *p << endl;
}
int main()
{
    int arr[5] = {1, 3, 67, 89, 0};
    // // int *ptr = arr;
    // // *ptr = 10;
    // // ptr++;
    // // *ptr = 20;
    // // for (int *cur = arr; cur <= ptr; cur++)
    // // {
    // //     cout << *cur << endl;
    // // }
    int *p = arr;
    p = p + 1;
    *p = 72;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    // vector<int> v = {1, 3, 67, 89, 0};
    // int *p = &v[0];
    // cout << *(p + 8) << endl;

    // char ch[6] = "hello";
    // char *p = ch;
    // int n = 200;
    // int *p = &n;
    // print(p);

    // int n = 100;
    // int *p = &n;
    // p = p + 1;
    // *p = 7;
    // cout << *p << endl;
    // cout << n << endl;
}
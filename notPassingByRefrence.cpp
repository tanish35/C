#include <iostream>
#include <vector>

using namespace std;

void something(vector<int> arr)
{
    arr[0] = 100;
    cout << "Inside function: " << arr[0] << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    something(arr);
    cout << "Outside function: " << arr[0] << endl;
    return 0;
}

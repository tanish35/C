#include <iostream>
#include <vector>
using namespace std;
int key = 7;
vector<int> num = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
void BS(int low, int high)
{
    int mid = (low + high) / 2;
    if (num[mid] == key)
    {
        cout << mid << endl;
        return;
    }
    if (num[mid] < key)
    {
        BS(mid + 1, high);
        return;
    }
    if (num[mid] > key)
    {
        BS(low, mid - 1);
        return;
    }
}

int main()
{
    BS(0, num.size() - 1);
    return 0;
}
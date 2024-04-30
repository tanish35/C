#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vi vector<int>
#define umap unordered_map<int, int>
#define uset unordered_set<int>
int binarySearch(vi &numbers, int target, int start)
{
    int left = start, right = numbers.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (numbers[mid] == target)
            return mid;
        else if (numbers[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int target = 9;
    vi numbers = {2, 7, 11, 15};
    vi result;
    for (int i = 0; i < numbers.size(); i++)
    {
        int complement = target - numbers[i];
        int index = binarySearch(numbers, complement, i + 1);
        if (index != -1)
        {
            result.push_back(i + 1);
            result.push_back(index + 1);
            break;
        }
    }
    for (int i : result)
        cout << i << " ";
    return 0;
}
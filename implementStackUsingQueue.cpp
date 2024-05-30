#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define umap unordered_map<int, int>
#define uset unordered_set<int>

class MyStack
{
public:
    queue<int> q1, q2;
    int topElement;

    void push(int x)
    {
        q1.push(x);
        topElement = x;
    }

    int pop()
    {
        while (q1.size() > 1)
        {
            topElement = q1.front();
            q2.push(topElement);
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        swap(q1, q2);
        return x;
    }

    int top()
    {
        return topElement;
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    return 0;
}
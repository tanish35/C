#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define umap unordered_map<int, int>
#define uset unordered_set<int>

class MyQueue
{
public:
    stack<int> s1, s2;
    void push(int x)
    {
        s1.push(x);
    }

    int peek()
    {
        int x = -1;
        while (!s1.empty())
        {
            s2.push(s1.top());
            x = s1.top();
            s1.pop();
        }
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }

    int pop()
    {
        int x = -1;
        while (!s1.empty())
        {
            s2.push(s1.top());
            x = s1.top();
            s1.pop();
        }
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }

    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.peek() << endl;
    cout << q.pop() << endl;
    cout << q.empty() << endl;

    return 0;
}
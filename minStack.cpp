#include <bits/stdc++.h>
using namespace std;
class MinStack
{
private:
    stack<int> s;
    stack<int> minStack;

public:
    void push(int val)
    {
        s.push(val);
        if (minStack.empty() || val <= minStack.top())
        {
            minStack.push(val);
        }
    }
    void pop()
    {
        if (s.top() == minStack.top())
        {
            minStack.pop();
        }
        s.pop();
    }
    int top()
    {
        return s.top();
    }
    int getMin()
    {
        return minStack.top();
    }
};

int main()
{
    MinStack *obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;
}
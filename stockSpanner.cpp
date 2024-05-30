#include <bits/stdc++.h>
using namespace std;
class StockSpanner
{
public:
    stack<pair<int, int>> prices;

    int next(int price)
    {
        int span = 1;
        while (!prices.empty() && prices.top().first <= price)
        {
            span += prices.top().second;
            prices.pop();
        }
        prices.push({price, span});
        return span;
    }
};

int main()
{
    StockSpanner obj;
    cout << obj.next(100) << endl;
    cout << obj.next(80) << endl;
    cout << obj.next(60) << endl;
    cout << obj.next(70) << endl;
    cout << obj.next(60) << endl;
    cout << obj.next(75) << endl;
    cout << obj.next(85) << endl;
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

string s = "ABC";
int n = s.length();

void subseq(int i, string ans)
{
    cout << ans << endl;

    for (int j = i; j < n; j++)
    {
        ans.push_back(s[j]);
        subseq(j + 1, ans);
        ans.pop_back();
    }
}

int main()
{
    subseq(0, "");
    return 0;
}

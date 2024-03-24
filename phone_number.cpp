#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

vector<string> res;
// string digits = "2345";

map<char, string> dic = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

void phone_number(int i, string s)
{
    if (i == digits.size())
    {
        res.push_back(s);
        return;
    }

    for (int j = 0; j < dic[digits[i]].size(); j++)
    {
        phone_number(i + 1, s + dic[digits[i]][j]);
    }
}

int main()
{
    phone_number(0, "");
    for (auto k : res)
    {
        cout << k << endl;
    }
    return 0;
}

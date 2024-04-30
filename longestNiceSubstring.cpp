#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    string longestNiceSubstring(std::string s)
    {
        if (s.length() < 2)
            return "";
        unordered_set<char> set;
        for (char c : s)
            set.insert(c);
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (set.count(toupper(c)) && set.count(tolower(c)))
                continue;
            string sub1 = longestNiceSubstring(s.substr(0, i));
            string sub2 = longestNiceSubstring(s.substr(i + 1));
            return (sub1.length() >= sub2.length()) ? sub1 : sub2;
        }
        return s;
    }
};

int main()
{
    Solution sol;
    string input = "YazaAay";
    cout << "Longest nice substring: " << sol.longestNiceSubstring(input) << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int minDistance(string word1, string word2, int m, int n)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;

    if (word1[m - 1] == word2[n - 1])
        return minDistance(word1, word2, m - 1, n - 1);

    return 1 + min({minDistance(word1, word2, m, n - 1),
                    minDistance(word1, word2, m - 1, n),
                    minDistance(word1, word2, m - 1, n - 1)});
}

int main()
{
    string word1 = "intention";
    string word2 = "execution";
    cout << minDistance(word1, word2, word1.size(), word2.size()) << endl;
    return 0;
}
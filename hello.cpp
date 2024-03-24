#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string name = "Thomas";
    string result = "";
    result += toupper(name[0]);
    result += '.';
    cout << result << endl;
}
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        for (int j = 0; j < 2 * a; j++)
        {
            int temp;
            if (j % 4 == 0 || j % 4 == 1)
            {
                temp = 0;
            }
            else
            {
                temp = 1;
            }
            for (int k = 0; k < a; k++)
            {
                if (temp == 0)
                {
                    cout << "##";
                    temp = 1;
                }
                else
                {
                    cout << "..";
                    temp = 0;
                }
            }
            cout << endl;
        }
    }
}
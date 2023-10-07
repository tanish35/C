#include <iostream>
using namespace std;
int size(void)
{
    int n;
    printf(" Enter a number ");
    cin>>n;
    return n;
}
int main(void)
{
    int n;
    n=size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

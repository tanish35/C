#include <iostream>
using namespace std;
int main(void)
{
    int a,r,c=0;
    printf("Enter a number\n");
    cin>>a;
    r=a;
    while (r>0)
    {
        c=(c*10)+(r%10);
        r=r/10;
    }
    cout<<c<<endl;
}
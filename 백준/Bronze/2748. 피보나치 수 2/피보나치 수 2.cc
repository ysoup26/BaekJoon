#include <iostream>

using namespace std;

long solve(int n)
{
    if(n==0||n==1)
        return n;
    else
    {
        long fn1=0;
        long fn2=1;
        long now;
        for(int i=2;i<=n;i++)
        {
            now=fn1+fn2;   
            fn1=fn2;
            fn2=now;
        }
        return now;
    }
}

int main()
{
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}
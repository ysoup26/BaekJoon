#include <iostream>

using namespace std;

int main()
{
    int N,money,cnt=0;
    int coins[10];
    cin>>N>>money;
    for(int i=0;i<N;i++)
    {
        cin>>coins[i];
    }
    for(int i=N-1;i>=0;i--)
    {
        cnt+=(money/coins[i]); 
        money%=coins[i];
    }
    cout<<cnt;
    return 0;
}

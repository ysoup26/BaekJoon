#include <iostream>

using namespace std;

int main()
{
    int changes[6]={500,100,50,10,5,1};
    int money,cnt=0;
    cin>>money;
    money=1000-money;
    for(int i=0;i<6;i++)
    {
        cnt+=(money/changes[i]); 
        money%=changes[i];
    }
    cout<<cnt;
    return 0;
}

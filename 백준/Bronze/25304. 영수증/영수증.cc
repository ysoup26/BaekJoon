#include <iostream>

using namespace std;
int main()
{
    int price,N,checkPrice=0;
    cin>>price>>N;
    for(int i=0;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        checkPrice+=(a*b);
    }
    if(price==checkPrice)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
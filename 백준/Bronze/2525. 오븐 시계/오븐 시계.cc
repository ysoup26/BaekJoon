#include <iostream>

using namespace std;

int main()
{
    int h,m,t;
    cin>>h>>m>>t;
    m+=t; //분에 모두 더하고 분해함
    h+=(int)(m/60);
    h%=24;
    m%=60;
    cout<<h<<" "<<m;
    return 0;
}
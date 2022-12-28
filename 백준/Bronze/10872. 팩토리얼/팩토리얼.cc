#include <iostream>

using namespace std;

void f(int N,int now,int sum)
{
    if(now>=N)
    {
        cout<<sum*now;
        return;
    }else
    {
        sum*=now++;
        f(N,now,sum);
    }
}

int main()
{
    int N;
    cin>>N;
    f(N,1,1); //1부터 순차적으로 곱함
    return 0;
}
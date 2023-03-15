#include <iostream>

int main()
{
    long N,cnt;
    std::cin>>N;
    cnt=0;
    for(int i=1;i<=N-1;i++)
    {
        for(int j=i+1;j<=N;j++)
            cnt++;
    }
    std::cout<<cnt<<'\n'<<2;
    return 0;
}
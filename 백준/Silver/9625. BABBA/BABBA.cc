#include <iostream>

using namespace std;

void solve(int K)
{
    /*수식
    다음A=현재B
    다음B=현재B+현재A
    */
    //처음 A=1 B=0
    int A=1,B=0;
    for(int i=1;i<=K;i++)
    {
        int nextA,nextB;
        nextA=B;
        nextB=B+A;
        A=nextA;
        B=nextB;
    }
    cout<<A<<" "<<B;
    return;
}

int main()
{
    int K;
    cin>>K;
    solve(K);
    return 0;
}
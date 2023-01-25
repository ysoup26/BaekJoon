#include <iostream>

using namespace std;

int reverse(int v)
{
    int re=0;
    while(v%10) //0 == 모든 자리수를 확인함
    {
        re=(re*10)+v%10;
        v=(int)v/10; //v/10이 float형일때를 주의해야함
    }
    return re;
}

int main()
{
    int A,B;
    cin>>A>>B;
    A=reverse(A);
    B=reverse(B);
    cout<<max(A,B);
    return 0;
}
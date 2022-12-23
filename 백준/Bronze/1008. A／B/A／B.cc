#include <iostream>

using namespace std;

int main()
{
    double A,B;
    cout.precision(10); //소수점의 길이를 설정하는 부분
    //10^-9의 오차이니 10으로 설정하였음
    cin>>A>>B;
    cout<<fixed<<A/B;
    return 0;
}